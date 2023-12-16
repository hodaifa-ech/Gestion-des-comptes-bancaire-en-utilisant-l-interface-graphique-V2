#include "dialogconfiguration.h"
#include "ui_dialogconfiguration.h"
#include "OthersFunctions.h"
#include "dialogaccount.h"
extern mediator mediator;

DialogConfiguration::DialogConfiguration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConfiguration)
{
    ui->setupUi(this);
    ui->old->setPlaceholderText("Enter the last corresponding data");
    ui->newD->setPlaceholderText("Enter the new data");
}

DialogConfiguration::~DialogConfiguration()
{
    delete ui;
}

void DialogConfiguration::on_ok_clicked()
{
    QString oldM = ui->old->text();
    QString newM = ui->newD->text();
    bool good(dbConnected());
    if (good)
    {
        QSqlQuery request(QSqlDatabase::database("MyConnect"));
        request.prepare("SELECT * FROM Customers WHERE accountnumber = :accountnumber");
        request.bindValue(":accountnumber",mediator.getnum());
        if(request.exec())
        {
            QString mod;
            while(request.next())
            {
                if(ui->passW->isChecked())
                {
                    mod = request.value(4).toString();
                    oldM = oldM;
                    if(mod == oldM)
                    {
                        QString a = newM;
                        QSqlQuery req;
                        req.prepare("UPDATE Customers SET password=:a WHERE accountnumber = :accountnumber");
                        req.bindValue(":accountnumber",mediator.getnum());
                        newM = newM;
                        req.bindValue(":a",newM);
                        if (!req.exec())
                        {
                            QMessageBox::critical(this,"","Something is running bad !");
                        }
                        else
                        {
                            QMessageBox::information(this,"Modification Status","Your password is successfully modified.");
                        }
                        break;
                    }
                }
                else if (ui->emaiL->isChecked())
                {
                    mod = request.value(8).toString();
                    if(mod == oldM)
                    {
                        QString a = newM;
                        QSqlQuery req;
                        req.prepare("UPDATE Customers SET email=:a WHERE accountnumber = :accountnumber");
                        req.bindValue(":accountnumber",mediator.getnum());
                        req.bindValue(":a",newM);
                        if (!req.exec())
                        {
                            QMessageBox::critical(this,"","Something is running bad !");
                        }
                        else
                        {
                            QMessageBox::information(this,"Modification Status","Your email is successfully modified.");
                            ui->old->setText("");
                            ui->newD->setText("");
                        }
                        break;
                    }
                }
                else if (ui->phonenuM->isChecked())
                {
                    mod = request.value(9).toString();
                    if(mod == oldM)
                    {
                        QString a = newM;
                        QSqlQuery req;
                        req.prepare("UPDATE Customers SET phnonenumber=:a WHERE accountnumber = :accountnumber");
                        req.bindValue(":accountnumber",mediator.getnum());
                        req.bindValue(":a",newM);
                        if (!req.exec())
                        {
                            QMessageBox::critical(this,"","Something is running bad !");
                        }
                        else
                        {
                            QMessageBox::information(this,"Modification Status","Your phone number is successfully modified.");
                        }
                        break;
                    }
                }
                else
                {
                    QMessageBox::critical(this,"","Old data is not correct !");
                    break;
                }
            }
        }
        else
        {
            QMessageBox::critical(this,"","Access failed !");
        }
    }
}



void DialogConfiguration::on_cancel_clicked()
{
    DialogAccount fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

