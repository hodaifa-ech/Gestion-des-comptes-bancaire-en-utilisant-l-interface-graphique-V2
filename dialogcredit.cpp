#include "dialogcredit.h"
#include "ui_dialogcredit.h"
#include "mediator.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "dbConnexion.h"
#include <QMessageBox>
#include "dialogaccount.h"
extern mediator mediator;

DialogCredit::DialogCredit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCredit)
{
    ui->setupUi(this);
    ui->accountNumberT->setText(mediator.getnum());
}

DialogCredit::~DialogCredit()
{
    delete ui;
}

void DialogCredit::on_ok_clicked()
{
    QString acNum = ui->accountNumberT->text();
    QString cBal = ui->credit->text();
    if(acNum == "" || cBal == "")
    {
        QMessageBox::information(this,"Conditions","Gaps should be filled.");
    }
    else if(acNum == mediator.getnum())
    {
        QString m_type = "Credit";
        int indicator(0);
        double cBal1 = cBal.toDouble();
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

void DialogCredit::on_close_clicked()
{
    DialogAccount fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

