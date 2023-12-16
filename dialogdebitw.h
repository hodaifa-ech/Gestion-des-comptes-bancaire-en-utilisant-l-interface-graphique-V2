#ifndef DIALOGDEBITW_H
#define DIALOGDEBITW_H

#include <QDialog>
#include "mediator.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "dbConnexion.h"
#include <QMessageBox>

namespace Ui {
class DialogDebitW;
}

class DialogDebitW : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDebitW(QWidget *parent = nullptr);
    ~DialogDebitW();

private slots:
    void on_ok_clicked();

    void on_close_clicked();

private:
    Ui::DialogDebitW *ui;
};

#endif // DIALOGDEBITW_H
