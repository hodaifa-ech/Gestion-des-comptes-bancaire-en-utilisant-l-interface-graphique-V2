#include "dialogloan.h"
#include "ui_dialogloan.h"

extern mediator mediator;

DialogLoan::DialogLoan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLoan)
{
    ui->setupUi(this);
    ui->loan->setPlaceholderText("Enter the loan you need");
}

DialogLoan::~DialogLoan()
{
    delete ui;
}

void DialogLoan::on_ok_clicked()
{
    if (ui->per->isChecked() && ui->delay->isChecked() && ui->loan->text() != "")
    {
        QString m_loan = ui->loan->text();
        QString m_type = "Loan";
        double cBal1 = m_loan.toDouble();
        mediator.setCredit(cBal1);
        double newBal(mediator.getcredit() + mediator.getbalance());
        mediator.setbalance(newBal);
        bool good(dbConnected());
        if (good)
        {
            QSqlQuery request(QSqlDatabase::database("MyConnect"));
            request.prepare("SELECT * FROM Customers WHERE accountnumber = :accountnumber");
            request.bindValue(":accountnumber",mediator.getnum());
            if(request.exec())
            {
                while(request.next())
                {
                    QString a_num = request.value(0).toString();

                    if(a_num == mediator.getnum())
                    {
                        double a = mediator.getbalance();
                        QSqlQuery req;
                        req.prepare("UPDATE Customers SET balance=:a WHERE accountnumber = :accountnumber");
                        req.bindValue(":accountnumber",mediator.getnum());
                        req.bindValue(":a",a);
                        if (!req.exec())
                        {
                            QMessageBox::critical(this,"","Something is running bad !");
                        }
                        break;
                    }
                }
                QSqlQuery reqT;
                QString send = "FST_BANK\t";
                QString m_dateC = QDate::currentDate().toString("yyyy/MM/dd");
                QString m_timeC = QTime::currentTime().toString("hh:mm:ss");
                reqT.prepare("INSERT INTO Transactions(Date,Time,TransactionType,AccountNumberP,AccountNumberS,TransactionBalance) VALUES(:Date,:Time,:TransactionType,:AccountNumberP,:AccountNumberS,:TransactionBalance)");
                reqT.bindValue(":Date",m_dateC);
                reqT.bindValue(":Time",m_timeC);
                reqT.bindValue(":TransactionType",m_type);
                reqT.bindValue(":AccountNumberP",send);
                reqT.bindValue(":AccountNumberS",mediator.getnum());
                reqT.bindValue(":TransactionBalance",mediator.getcredit());
                if(reqT.exec())
                {
                    QMessageBox::information(this,"","Loan successfully granted !");
                    hide();
                }
            }
            hide();
        }
        else
        {
            QMessageBox::critical(this,"","Access failed !");
        }
    }
    else
        QMessageBox::information(this,"Loan Conditions","Conditions must be accepted before loan.");
}


