#include "dialogcreditw.h"
#include "ui_dialogcreditw.h"
#include "dialogroot.h"
extern mediator mediator;

DialogCreditW::DialogCreditW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCreditW)
{
    ui->setupUi(this);
}

DialogCreditW::~DialogCreditW()
{
    delete ui;
}

void DialogCreditW::on_ok_clicked()
{
    QString acNum = ui->accountNumberT->text();
    QString cBal = ui->credit->text();
    if(acNum == "" || cBal == "")
    {
        QMessageBox::information(this,"Conditions","Gaps should be filled.");
    }
    else
    {
        /*QString m_type = "Credit";
        int indicator(0);
        double cBal1 = cBal.toDouble();
        mediator.setCredit(cBal1);
        bool good(dbConnected());*/
        QString m_type = "Credit";
        int indicator = 0;
        double cBal1 = cBal.toDouble();
        mediator.setCredit(cBal1);
        bool good = dbConnected();

        if (good)
        {
            /*QSqlQuery request(QSqlDatabase::database("MyConnect"));

            request.prepare("SELECT * FROM Customers WHERE accountnumber = :accountnumber");
            request.bindValue(":accountnumber",acNum);*/
            QSqlQuery request(QSqlDatabase::database("MyConnect"));
            request.prepare("SELECT * FROM Customers WHERE accountnumber = :accountnumber");
            request.bindValue(":accountnumber", acNum);

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
                    double newBal(mediator.getcredit() + balance);
                    mediator.setbalance(newBal);
                    QString type = request.value(1).toString();
                    QString name = request.value(5).toString() + " " + request.value(6).toString();
                    if(acNum == a_num)
                    {
                        mediator.setnum(a_num);
                        mediator.setname(name);
                        mediator.setbalance(newBal);
                        mediator.settype(type);
                        QSqlQuery request1(QSqlDatabase::database("MyConnect"));
                        request1.prepare("SELECT * FROM Customers WHERE accountnumber = :accountnumber");
                        request1.bindValue(":accountnumber",mediator.getnum());
                        if(request1.exec())
                        {
                            while(request1.next())
                            {
                                QString a_num = request1.value(0).toString();

                                if(a_num == acNum)
                                {
                                    double a = mediator.getbalance();
                                    QSqlQuery req;
                                    req.prepare("UPDATE Customers SET balance=:a WHERE accountnumber = :accountnumber");
                                    req.bindValue(":accountnumber",acNum);
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
                    QMessageBox::information(this,"","No exist data !");
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
}

void DialogCreditW::on_close_clicked()
{
    DialogRoot fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

