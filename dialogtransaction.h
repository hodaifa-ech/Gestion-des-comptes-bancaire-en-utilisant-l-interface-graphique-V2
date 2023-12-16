#ifndef DIALOGTRANSACTION_H
#define DIALOGTRANSACTION_H

#include <QDialog>
#include <QTableView>
#include "mediator.h"
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "mediator.h"

namespace Ui {
class DialogTransaction;
}

class DialogTransaction : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTransaction(QWidget *parent = nullptr);
    ~DialogTransaction();

private:
    Ui::DialogTransaction *ui;
};

#endif // DIALOGTRANSACTION_H
