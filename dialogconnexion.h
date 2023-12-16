#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "OthersFunctions.h"


namespace Ui {
class DialogConnexion;
}

class DialogConnexion : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConnexion(QWidget *parent = nullptr);
    ~DialogConnexion();

private slots:
    void on_connect_clicked();

    void on_cancel_clicked();

private:
    Ui::DialogConnexion *ui;
};

#endif // DIALOGCONNEXION_H
