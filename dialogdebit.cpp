#include "dialogdebit.h"
#include "ui_dialogdebit.h"
#include "dialogaccount.h"
extern mediator mediator;
DialogDebit::DialogDebit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDebit)
{
    ui->setupUi(this);
    ui->accountNumberT->setText(mediator.getnum());
}

DialogDebit::~DialogDebit()
{
    delete ui;
}

void DialogDebit::on_ok_clicked()
{
    QString acNum = ui->accountNumberT->text();
    QString cBal = ui->debit->text();
    if(acNum == "" || cBal == "")
    {
        QMessageBox::information(this,"Conditions","You should fill gaps.");
    }
    else if(acNum == mediator.getnum())
    {
        double currentBalance = mediator.getbalance();
        double debitAmount = cBal.toDouble();
        if(debitAmount <= currentBalance)
        {
        QString m_type = "Debit";
        int indicator(0);
        double cBal1 = cBal.toDouble();
        mediator.setCredit(cBal1);
        double newBal(mediator.getbalance() - mediator.getcredit());
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
                    if(a_num == acNum)
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
                        else
                            indicator = 1;
                        break;
                    }
                }
                if (indicator != 1)
                {
                    QMessageBox::critical(this,"","No exist data !");
                }
                else
                {
                    QSqlQuery reqT;
                    QString m_dateC = QDate::currentDate().toString("yyyy/MM/dd");
                    QString m_timeC = QTime::currentTime().toString("hh:mm:ss");
                    reqT.prepare("INSERT INTO Transactions(Date,Time,TransactionType,AccountNumberP,AccountNumberS,TransactionBalance) VALUES(:Date,:Time,:TransactionType,:AccountNumberP,:AccountNumberS,:TransactionBalance)");
                    reqT.bindValue(":Date",m_dateC);
                    reqT.bindValue(":Time",m_timeC);
                    reqT.bindValue(":TransactionType",m_type);
                    reqT.bindValue(":AccountNumberP",mediator.getnum());
                    reqT.bindValue(":AccountNumberS",acNum);
                    reqT.bindValue(":TransactionBalance",mediator.getcredit());
                    if(reqT.exec())
                    {
                        QMessageBox::information(this,"","Transaction successfully saved !");
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
    }
        else
        {
        QMessageBox::information(this, "", "The withdrawal amount exceeds the available balance.");
        }
    }
    else
    {
        QMessageBox::information(this,"","You are not authorized to debit from another account than yours\nwithout an official bank draft or a validate personal check.\nThanks for understanding.");
    }
}

void DialogDebit::on_close_clicked()
{
    DialogAccount fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

