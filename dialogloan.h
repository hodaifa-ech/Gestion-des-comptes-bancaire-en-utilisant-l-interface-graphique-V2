#ifndef DIALOGLOAN_H
#define DIALOGLOAN_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include "mediator.h"
#include "dbConnexion.h"
#include <QSqlQuery>

namespace Ui {
class DialogLoan;
}

class DialogLoan : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLoan(QWidget *parent = nullptr);
    ~DialogLoan();

private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::DialogLoan *ui;
};

#endif // DIALOGLOAN_H
