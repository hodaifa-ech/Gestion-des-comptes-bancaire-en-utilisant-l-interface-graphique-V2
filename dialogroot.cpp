#include "dialogroot.h"
#include "dialog2.h"
#include <QMessageBox>
#include "ui_dialogroot.h"
#include "dialogloan.h"

DialogRoot::DialogRoot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRoot)
{
    ui->setupUi(this);
}

DialogRoot::~DialogRoot()
{
    delete ui;
}

void DialogRoot::on_cancel_clicked()
{
    Dialog2 fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogRoot::on_listAll_clicked()
{
    bool good(dbConnected());
    if (good)
    {
        QSqlTableModel *requestModel = new QSqlTableModel();
        requestModel->setTable("Customers");
        requestModel->setHeaderData(0,Qt::Horizontal,tr("Account Number"));
        requestModel->setHeaderData(1,Qt::Horizontal,tr("Account Type"));
        requestModel->setHeaderData(2,Qt::Horizontal,tr("Time"));
        requestModel->setHeaderData(3,Qt::Horizontal,tr("Date"));
        requestModel->setHeaderData(4,Qt::Horizontal,tr("Passsword"));
        requestModel->setHeaderData(5,Qt::Horizontal,tr("FirstName"));
        requestModel->setHeaderData(6,Qt::Horizontal,tr("Surname"));
        requestModel->setHeaderData(7,Qt::Horizontal,tr("Gender"));
        requestModel->setHeaderData(8,Qt::Horizontal,tr("Email"));
        requestModel->setHeaderData(9,Qt::Horizontal,tr("Phone Number"));
        requestModel->setHeaderData(10,Qt::Horizontal,tr("Birthdate"));
        requestModel->setHeaderData(11,Qt::Horizontal,tr("Country"));
        requestModel->setHeaderData(12,Qt::Horizontal,tr("Status"));
        requestModel->setHeaderData(13,Qt::Horizontal,tr("Balance"));
        requestModel->select();
        ui->display->setModel(requestModel);
    }
    else
    {
        QMessageBox::information(this,"","Connexion Failed !");
    }
}

void DialogRoot::on_addNew_clicked()
{
    DialogCreate fenetre;
    fenetre.setWindowTitle("create");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/add-user.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogRoot::on_quit_clicked()
{
    int reponse = QMessageBox::question(this, "Exit Confirmation",
    "Do you really want to quit App?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        exit(0);
    }
}

void DialogRoot::on_credit_clicked()
{
    DialogCreditW fenetre;
    fenetre.setWindowTitle("creditw");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/money-transfer.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogRoot::on_debit_clicked()
{
    DialogDebitW fenetre;
    fenetre.setWindowTitle("debitw");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/money-transfer.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogRoot::on_transfer_clicked()
{
    DialogTransferW fenetre;
    fenetre.setWindowTitle("transferw");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/money-transfer.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogRoot::on_research_clicked()
{
    QString enter = ui->search->text();
    QSqlQuery request(QSqlDatabase::database("MyConnect"));
    QString result = "AccountNumber\tAccountType\tCreationTime\tCreationDate\tFirstname\tSurname\tEmail\tPhoneNumber\tBirthdate\tCountry\tStatus\tBalance\n";
    request.prepare("SELECT * FROM Customers WHERE gender = :gender OR phonenumber = :phonenumber OR accounttype = :accounttype OR accountnumber = :accountnumber OR firstname = :firstname OR surname = :surname OR email = :email");// AND password = :password");
    request.bindValue(":accountnumber",enter.toInt());
    request.bindValue(":firstname",enter);
    request.bindValue(":surname",enter);
    request.bindValue(":email",enter);
    request.bindValue(":accounttype",enter);
    request.bindValue(":phonenumber",enter);
    request.bindValue(":gender",enter);
    if(request.exec())
    {
        while(request.next())
        {
            QString num = request.value(0).toString();
            QString type = request.value(1).toString();
            QString time = request.value(2).toString();
            QString date = request.value(3).toString();
            QString name = request.value(5).toString();
            QString name2 = request.value(6).toString();
            QString gender = request.value(7).toString();
            QString email = request.value(8).toString();
            QString phone = request.value(9).toString();
            QString birthdate = request.value(10).toString();
            QString country = request.value(11).toString();
            QString status = request.value(12).toString();
            QString bal = request.value(13).toString();
            result = result + num + "\t" + type + "\t" + time + "\t" + date + "\t" + name + "\t" + name2 + "\t" + gender + "\t"+ email + "\t" + phone + "\t"+ birthdate + "\t" + country + "\t" + status + "\t" + bal + "\n";
        }
        ui->outcome->setText(result);
    }
}

void DialogRoot::on_statement_clicked()
{
    bool good(dbConnected());
    if (good)
    {
        QSqlQuery request(QSqlDatabase::database("MyConnect"));
        QMessageBox::information(this,"","Successfully accessed !");
        QSqlQueryModel *requestModel = new QSqlQueryModel();
        requestModel->setQuery("SELECT * FROM Transactions");
        requestModel->setHeaderData(0,Qt::Horizontal,tr("Date"));
        requestModel->setHeaderData(1,Qt::Horizontal,tr("Time"));
        requestModel->setHeaderData(2,Qt::Horizontal,tr("TransactionType"));
        requestModel->setHeaderData(3,Qt::Horizontal,tr("TransactionBalance"));
        requestModel->setHeaderData(4,Qt::Horizontal,tr("AccountNumber P"));
        requestModel->setHeaderData(5,Qt::Horizontal,tr("AccountNumber S"));
        ui->display->setModel(requestModel);
    }
    else
    {
        QMessageBox::information(this,"","Connexion Failed !");
    }
}

void DialogRoot::on_pushButton_clicked()
{
    DialogLoan fenetre;
    fenetre.setWindowTitle("loan");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/money-transfer.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

