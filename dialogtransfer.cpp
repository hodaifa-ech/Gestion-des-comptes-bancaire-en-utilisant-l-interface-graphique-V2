#include "dialogtransfer.h"
#include "ui_dialogtransfer.h"
#include "dialogaccount.h"
extern mediator mediator;

DialogTransfer::DialogTransfer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTransfer)
{
    ui->setupUi(this);
}

DialogTransfer::~DialogTransfer()
{
    delete ui;
}

void DialogTransfer::on_ok_clicked()
{
    int indicator(0);
    QString m_type = "Transfer";
    QString acNum = ui->accountNumberT->text();
    QString cBal = ui->transfer->text();
    double cBal1 = cBal.toDouble();
    mediator.setCredit(cBal1);
    double newBal(mediator.getbalance() - mediator.getcredit());
    if(acNum.isEmpty() || cBal.isEmpty())
    {
        QMessageBox::information(this, "Conditions", "You should fill in all fields.");
    }
    else if(newBal <=0)
    {
        QMessageBox::information(this, "", "Insufficient balance for the transfer.");
    }
    else{
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
                else
                {
                    QMessageBox::critical(this,"","No exist data !");
                    break;
                }
            }
            hide();
        }
        else
        {
            QMessageBox::critical(this,"","Access failed !");
        }
        QSqlQuery request2(QSqlDatabase::database("MyConnect"));
        request2.prepare("SELECT * FROM Customers WHERE accountnumber = :accountnumber");
        request2.bindValue(":accountnumber",acNum);
        if(request2.exec())
        {
            while(request2.next())
            {
                QString a_num = request2.value(0).toString();
                QString a_bal = request2.value(13).toString();
                if(a_num == acNum)
                {
                    double a = a_bal.toDouble();
                    double newBal2(a + cBal1);
                    QSqlQuery req2;
                    req2.prepare("UPDATE Customers SET balance=:a WHERE accountnumber = :accountnumber");
                    req2.bindValue(":accountnumber",acNum);
                    req2.bindValue(":a",newBal2);
                    if (!req2.exec())
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
    else
    {
        QMessageBox::information(this,"","You are not authorized to debit from another account than yours\nwithout an official bank draft or a validate personal check.\nThanks for understanding.");
    }
    }

}

void DialogTransfer::on_close_clicked()
{
    DialogAccount fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

