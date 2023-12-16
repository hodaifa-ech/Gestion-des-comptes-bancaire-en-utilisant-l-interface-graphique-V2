#ifndef DIALOGTRANSFER_H
#define DIALOGTRANSFER_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include "mediator.h"
#include "dbConnexion.h"
#include <QSqlQuery>

namespace Ui {
class DialogTransfer;
}

class DialogTransfer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTransfer(QWidget *parent = nullptr);
    ~DialogTransfer();

private slots:
    void on_ok_clicked();

    void on_close_clicked();

private:
    Ui::DialogTransfer *ui;
};

#endif // DIALOGTRANSFER_H
