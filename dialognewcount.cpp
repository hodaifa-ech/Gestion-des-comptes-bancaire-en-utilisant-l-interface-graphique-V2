#include "dialognewcount.h"
#include "ui_dialognewcount.h"
#include "dialoglogin.h"
#include <QMessageBox>

extern mediator newAccount;

DialogNewCount::DialogNewCount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewCount)
{
    ui->setupUi(this);
    ui->name->setText(newAccount.getname());
    ui->type->setText(newAccount.gettype());
    ui->aNum->setText(newAccount.getnum());
    ui->dBal->setText("$7");
}

DialogNewCount::~DialogNewCount()
{
    delete ui;
}

void DialogNewCount::on_login_clicked()
{
    hide();
    DialogLogin fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

void DialogNewCount::on_quit_clicked()
{
    int reponse = QMessageBox::question(this, "Exit Confirmation",
    "Do you really want to quit App?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        exit(0);
    }
}

