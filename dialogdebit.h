#ifndef DIALOGDEBIT_H
#define DIALOGDEBIT_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include "mediator.h"
#include "dbConnexion.h"
#include <QSqlQuery>

namespace Ui {
class DialogDebit;
}

class DialogDebit : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDebit(QWidget *parent = nullptr);
    ~DialogDebit();

private slots:
    void on_ok_clicked();

    void on_close_clicked();

private:
    Ui::DialogDebit *ui;
};

#endif // DIALOGDEBIT_H
