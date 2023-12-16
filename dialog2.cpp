#include "dialog2.h"
#include "ui_dialog2.h"
#include "QMessageBox"

extern mediator worker;
Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    ui->workerId->setPlaceholderText("Enter your ID");
    ui->password->setPlaceholderText("Enter your password");
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_quit_clicked()
{
    int reponse = QMessageBox::question(this, "Exit Confirmation",
    "Do you really want to quit App?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        exit(0);
    }
}

void Dialog2::on_cancel_clicked()
{
    hide();
    DialogConnexion fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

void Dialog2::on_login_clicked()
{
    int indicator(0);
    QString m_id = ui->workerId->text();
    QString m_pass = ui->password->text();
    bool good(dbConnected());
    if (good)
    {
        QSqlQuery request(QSqlDatabase::database("MyConnect"));
        request.prepare("SELECT * FROM BLBWorkers WHERE Identifying = :identifying AND Password = :password");
        request.bindValue(":identifying",m_id);
        request.bindValue(":password",m_pass);
        if(request.exec())
        {
            worker.setnum("");
            worker.setname("");
            QMessageBox::information(this,"","Successfully connected !");
            while(request.next())
            {
                QString a_num = request.value(3).toString();
                QString pass = request.value(4).toString();
                QMessageBox::information(this,"","Successfully connected !");
                QString name = request.value(1).toString() + " " + request.value(2).toString();
                if(m_id == a_num && m_pass == pass)
                {
                    worker.setnum(a_num);
                    worker.setname(name);
                    indicator = 1;
                    DialogRoot fenetre;
                    fenetre.setWindowTitle("root");
                    fenetre.setWindowIcon( QIcon(":/MesImages/MesImages/office-worker.png"));
                    fenetre.setModal(true);
                    fenetre.exec();
                    hide();
                    break;
                }
            }
            if (indicator != 1)
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
