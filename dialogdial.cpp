#include "dialogdial.h"
#include "dialog2.h"
#include "ui_dialogdial.h"

DialogDial::DialogDial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDial)
{
    ui->setupUi(this);
}

DialogDial::~DialogDial()
{
    delete ui;
}

void DialogDial::on_dial_valueChanged(int value)
{
    ui->lcdNumber->display(value);
    value1 = value;
}

void DialogDial::on_dial2_valueChanged(int value)
{
    ui->lcdNumber2->display(value);
    value2 = value;
}

void DialogDial::on_dial3_valueChanged(int value)
{
    ui->lcdNumber3->display(value);
    value3 = value;
}

void DialogDial::on_ok_clicked()
{
    int a(7),b(9),c(3);
    if (value1 == a && value2 == b && value3 == c)
    {
        hide();
        Dialog2 fenetre;
        fenetre.setModal(true);
        fenetre.exec();
    }
    else
    {
        QMessageBox::critical(this,"ALERT","Access denied !!!");
        hide();
    }
}
