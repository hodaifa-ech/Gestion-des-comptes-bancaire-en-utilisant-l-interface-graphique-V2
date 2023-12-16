#include "dialoglogin.h"
#include "dialog1.h"
#include "ui_dialoglogin.h"
#include "QMessageBox"
#include "dialogaccount.h"
#include "dbConnexion.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql>
#include <QSqlDatabase>
#include "dialogcreate.h"
#include "mediator.h"
extern mediator mediator;
DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
    ui->accountNumber->setPlaceholderText("Enter your account number");
    ui->password->setPlaceholderText("Enter your password");
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::on_quit_clicked()
{
    int reponse = QMessageBox::question(this, "Exit Confirmation",
    "Do you really want to quit App?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        exit(0);
    }
}

void DialogLogin::on_cancel_clicked()
{
    Dialog1 fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogLogin::on_login_clicked()
{
    QString m_anum = ui->accountNumber->text();
    QString m_pass = ui->password->text();
    bool good(dbConnected());
    int indicator(0);
    if (good)
    {
        QSqlQuery request(QSqlDatabase::database("MyConnect"));
        QString m_pass1;
        m_pass1 = m_pass;
        request.prepare("SELECT * FROM Customers WHERE accountnumber = :accountnumber AND password = :password");
        request.bindValue(":accountnumber",m_anum);
        request.bindValue(":password",m_pass1);
        if(request.exec())
        {
            mediator.setnum("");
            mediator.setname("");
            mediator.setbalance(0);
            mediator.settype("");
            while(request.next())
            {
                QString a_num = request.value(0).toString();
                QString pass = request.value(4).toString();
                double balance = request.value(13).toDouble();
                QString type = request.value(1).toString();
                QString name = request.value(5).toString() + " " + request.value(6).toString();
                if(m_anum == a_num && m_pass1 == pass)
                {
                    mediator.setnum(a_num);
                    mediator.setname(name);
                    mediator.setbalance(balance);
                    mediator.settype(type);
                    hide();
                    DialogAccount fenetre;
                    fenetre.setModal(true);
                    fenetre.exec();
                    indicator = 1;
                    break;
                }
            }
            if (indicator == 1)
            {
                QMessageBox::information(this,"","Access denied !");
            }
        }
        else
        {
            QMessageBox::critical(this,"","Access failed !");
        }
    }
}
