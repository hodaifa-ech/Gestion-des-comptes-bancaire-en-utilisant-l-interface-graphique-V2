#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "OthersFunctions.h"
#include "dialogconnexion.h"
#include "dialogroot.h"
#include <QMessageBox>
#include "mediator.h"

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();

private slots:
    void on_quit_clicked();

    void on_cancel_clicked();

    void on_login_clicked();

private:
    Ui::Dialog2 *ui;
};

#endif // DIALOG2_H
