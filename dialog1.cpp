#include "dialog1.h"
#include "dialogconnexion.h"
#include "dialoglogin.h"
#include "dialogcreate.h"
#include "ui_dialog1.h"
#include "QMessageBox"
#include "OthersFunctions.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_login_clicked()
{
    hide();
    DialogLogin fenetre;
    fenetre.setWindowTitle("login");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/key.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

void Dialog1::on_newCount_clicked()
{
    hide();
    DialogCreate fenetre;
    fenetre.setWindowTitle("create");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/add-user.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

void Dialog1::on_quit_clicked()
{
    int reponse = QMessageBox::question(this, "Exit Confirmation",
    "Do you really want to quit App?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        exit(0);
    }
}

void Dialog1::on_cancel_clicked()
{
    DialogConnexion fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}
