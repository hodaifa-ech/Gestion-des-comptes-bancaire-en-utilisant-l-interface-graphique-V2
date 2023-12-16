#ifndef DIALOGTRANSFERW_H
#define DIALOGTRANSFERW_H

#include <QDialog>
#include "mediator.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "dbConnexion.h"
#include <QMessageBox>

namespace Ui {
class DialogTransferW;
}

class DialogTransferW : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTransferW(QWidget *parent = nullptr);
    ~DialogTransferW();

private slots:
    void on_ok_clicked();

    void on_pushButton_clicked();

    void on_close_clicked();

private:
    Ui::DialogTransferW *ui;
};

#endif // DIALOGTRANSFERW_H
