#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "OthersFunctions.h"

namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = nullptr);
    ~DialogLogin();

private slots:

    void on_quit_clicked();

    void on_cancel_clicked();

    void on_login_clicked();

private:
    Ui::DialogLogin *ui;
    QString num,type,balance;
};

#endif // DIALOGLOGIN_H
