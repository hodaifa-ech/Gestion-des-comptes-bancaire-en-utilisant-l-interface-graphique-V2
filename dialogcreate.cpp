#include "dialogcreate.h"
#include "dialog1.h"
#include "dialognewcount.h"
#include "ui_dialogcreate.h"
#include <QString>
#include <QMessageBox>
#include "dbConnexion.h"
#include <vector>
#include "mediator.h"

extern mediator mediator, newAccount;

DialogCreate::DialogCreate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCreate)
{
    ui->setupUi(this);
    ui->surname->setPlaceholderText("Enter your surname");
    ui->firstname->setPlaceholderText("Enter your firstname");
    ui->mail->setPlaceholderText("Enter your mail");
    ui->tel->setPlaceholderText("Enter your phone number");
    ui->password->setPlaceholderText("Enter your password");
    ui->password1->setPlaceholderText("Confirm your password");
}

DialogCreate::~DialogCreate()
{
    delete ui;
}

void DialogCreate::on_saveData_clicked()
{
    QString m_pass = ui->password->text();
    QString m_pass1 = ui->password1->text();
    QString m_surname = ui->surname->text();
    QString m_firstname = ui->firstname->text();
    QString m_mail = ui->mail->text();
    QString m_tel = ui->tel->text();
    QDate m_dateB = ui->dateB->date();
    QString m_countType = ui->countType->currentText();
    QString m_gender = ui->gender->currentText();
    QString m_city = ui->city->currentText();
    QString m_dateC = QDate::currentDate().toString("yyyy/MM/dd");
    QString m_timeC = QTime::currentTime().toString("hh:mm:ss");
    QString m_timeCc = QTime::currentTime().toString("hhmmss");
    if((m_pass != m_pass1) || m_surname == "" || m_firstname == "" || m_mail == "" || m_tel == "" || m_pass == "" || m_pass1 == "")
    {
        QMessageBox::critical(this,"Conditions","Password must agree AND all gaps must be filled.");
    }
    else
    {
        bool good(dbConnected());
        if (good)
        {
            QString m_passC = m_pass;
            QString m_accountNumber;
            QString type;
            if(m_countType == "Current account")
                type = "379";
            else
                type = "793";
            m_accountNumber = type + m_timeCc;
            QSqlQuery request;
            request.prepare("INSERT INTO Customers(accountType,accountNumber,password,firstname,surname,gender,email,phoneNumber,birthdate,city,creationDate,creationTime) VALUES(:accountType,:accountNumber,:password,:firstname,:surname,:gender,:email,:phoneNumber,:birthdate,:city,:creationDate,:creationTime)");
            request.bindValue(":accountType",m_countType);
            request.bindValue(":creationDate",m_dateC);
            request.bindValue(":creationTime",m_timeC);
            request.bindValue(":accountNumber",m_accountNumber);
            request.bindValue(":password",m_passC);
            request.bindValue(":firstname",m_firstname);
            request.bindValue(":surname",m_surname);
            request.bindValue(":gender",m_gender);
            request.bindValue(":email",m_mail);
            request.bindValue(":phoneNumber",m_tel);
            request.bindValue(":birthdate",m_dateB);
            request.bindValue(":city",m_city);
            if(request.exec())
            {
                QMessageBox::information(this,"","Succesfully inserted !");
                hide();
                newAccount.settype(m_countType);
                newAccount.setbalance(7.0);
                newAccount.setname(m_firstname + " " + m_surname);
                newAccount.setnum(m_accountNumber);
                DialogNewCount fenetre;
                fenetre.setWindowTitle("customre");
                fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/add-user.png"));
                fenetre.setModal(true);
                fenetre.exec();
            }
            else
            {
                QMessageBox::information(this,"","Insertion failed !");
            }

        }
        else
        {
            QMessageBox::information(this,"","Connexion failed !");
        }
    }
}
void DialogCreate::on_quit_clicked()
{
    int reponse = QMessageBox::question(this, "Exit Confirmation",
    "Do you really want to quit App?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        exit(0);
    }
}

void DialogCreate::on_cancel_clicked()
{
    Dialog1 fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}
