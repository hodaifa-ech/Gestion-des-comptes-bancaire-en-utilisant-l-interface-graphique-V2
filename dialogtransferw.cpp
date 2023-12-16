#include "dialogtransferw.h"
#include "ui_dialogtransferw.h"
#include "dialogroot.h"
extern mediator mediator;

DialogTransferW::DialogTransferW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTransferW)
{
    ui->setupUi(this);
}

DialogTransferW::~DialogTransferW()
{
    delete ui;
}

void DialogTransferW::on_ok_clicked()
{
    int indicator(0);
    QString m_type = "Transfer";
    QString acNumD = ui->accountNumberD->text();
    QString acNum = ui->accountNumberC->text();
    QString cBal = ui->transfer->text();
    double cBal1 = cBal.toDouble();
    mediator.setCredit(cBal1);
    //double newBal(mediator.getbalance() - mediator.getcredit());
    //mediator.setbalance(newBal);
    bool good(dbConnected());
    if (good)
    {
        QSqlQuery request(QSqlDatabase::database("MyConnect"));
        request.prepare("SELECT * FROM Customers WHERE accountnumber = :accountnumber");// AND password = :password");
        request.bindValue(":accountnumber",acNumD);
        if(request.exec())
        {
            mediator.setnum("");
            mediator.setname("");
            mediator.setbalance(0);
            mediator.settype("");
            QMessageBox::information(this,"","Successfully connected !");
            while(request.next())
            {
                QString a_num = request.value(0).toString();
                QString pass = request.value(4).toString();
                double balance = request.value(13).toDouble();
                //double newBal(balance - mediator.getcredit());
                //mediator.setbalance(newBal);
                QString type = request.value(1).toString();
                QString name = request.value(5).toString() + " " + request.value(6).toString();
                if(acNumD == a_num)// && m_pass1 == pass)
                {
                    mediator.setnum(a_num);
                    mediator.setname(name);
                    mediator.setbalance(balance);
                    mediator.settype(type);
                    if (cBal1 > mediator.getbalance()) {
                        QMessageBox::critical(this, "", "Insufficient balance for the transfer!");
                        return; // Exit function if balance is insufficient
                    }
                    double newBal(balance - mediator.getcredit());
                    mediator.setbalance(newBal);
                    QSqlQuery request1(QSqlDatabase::database("MyConnect"));
                    request1.prepare("SELECT * FROM Customers WHERE accountnumber = :accountnumber");
                    request1.bindValue(":accountnumber",mediator.getnum());
                    if(request1.exec())
                    {
                        while(request1.next())
                        {
                            QString a_num = request1.value(0).toString();
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
                                else
                                    indicator = 1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        QMessageBox::information(this,"","Access denied !");
                        break;
                    }
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
}



void DialogTransferW::on_close_clicked()
{
   DialogRoot  fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

