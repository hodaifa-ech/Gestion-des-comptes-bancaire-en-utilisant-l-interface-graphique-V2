#include "mainwindow0.h"
#include "dialogconnexion.h"
#include "ui_mainwindow0.h"
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include "dialogroot.h"
#include <QLabel>
#include "mediator.h"
#include "about.h"
MainWindow0::MainWindow0(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow0)
{
    ui->setupUi(this);

}

MainWindow0::~MainWindow0()
{
    delete ui;
}

void MainWindow0::on_quit0_clicked()
{
    int reponse = QMessageBox::question(this, "Exit Confirmation",
    "Do you really want to quit App?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        exit(0);
    }
}

void MainWindow0::on_logon0_clicked()
{
    //hide();
    DialogConnexion fenetre;
    fenetre.setWindowTitle("connexion");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/add-user.png"));
    fenetre.setModal(true);
    fenetre.exec();
}

void MainWindow0::on_aboutB_clicked()
{
    //hide();
    about fenetre;
    fenetre.setWindowTitle("about");
    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/Screenshot_20210211-234801.png"));
    fenetre.setModal(true);
    fenetre.exec();
}


