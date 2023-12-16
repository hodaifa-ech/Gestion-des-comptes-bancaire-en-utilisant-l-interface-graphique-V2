#ifndef DIALOGCREDITW_H
#define DIALOGCREDITW_H

#include <QDialog>
#include "mediator.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "dbConnexion.h"
#include <QMessageBox>

namespace Ui {
class DialogCreditW;
}

class DialogCreditW : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreditW(QWidget *parent = nullptr);
    ~DialogCreditW();

private slots:
    void on_ok_clicked();

    void on_close_clicked();

private:
    Ui::DialogCreditW *ui;
};

#endif // DIALOGCREDITW_H
