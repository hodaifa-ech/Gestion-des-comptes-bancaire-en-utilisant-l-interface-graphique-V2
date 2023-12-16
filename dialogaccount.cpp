#include "dialogaccount.h"
#include "ui_dialogaccount.h"
#include <QMessageBox>
#include "dialogcredit.h"
#include "mediator.h"
#include "dialogloan.h"

extern mediator mediator;

DialogAccount::DialogAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAccount)
{
    ui->setupUi(this);
    ui->balance->display(mediator.getbalance());
    ui->nameT->setText(mediator.getname());
    ui->accountnumber->setText(mediator.getnum());
    ui->accounttype->setText(mediator.gettype());
}

DialogAccount::~DialogAccount()
{
    delete ui;
}

void DialogAccount::on_quit_clicked()
{
    int reponse = QMessageBox::question(this, "Exit Confirmation",
    "Do you really want to quit App?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        exit(0);
    }
}

void DialogAccount::on_cancel_clicked()
{
    DialogLogin fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogAccount::on_credit_clicked()
{
    DialogCredit fenetre;
    fenetre.setWindowTitle("credit");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/money-transfer.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogAccount::on_refresh_clicked()
{
    ui->balance->display(mediator.getbalance());
}

void DialogAccount::on_debit_clicked()
{
    DialogDebit fenetre;
    fenetre.setWindowTitle("debit");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/money-transfer.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogAccount::on_transfer_clicked()
{
    DialogTransfer fenetre;
    fenetre.setWindowTitle("transfer");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/money-transfer.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogAccount::on_mailMod_clicked()
{
    DialogConfiguration fenetre;
    fenetre.setWindowTitle("change");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/money-transfer.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogAccount::on_statement_clicked()
{
    DialogTransaction fenetre;
    fenetre.setWindowTitle("statement");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/money-transfer.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogAccount::on_loan_clicked()
{
    DialogLoan fenetre;
    fenetre.setWindowTitle("statement");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/money-transfer.png"));
    fenetre.setModal(true);
    fenetre.exec();
}
