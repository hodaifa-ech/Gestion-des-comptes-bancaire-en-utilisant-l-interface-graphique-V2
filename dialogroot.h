#ifndef DIALOGROOT_H
#define DIALOGROOT_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "OthersFunctions.h"
#include "dialogcreditw.h"
#include "dialogdebitw.h"
#include "dialogtransferw.h"
#include "QLabel"
#include "dbConnexion.h"
#include <QTableView>
#include  <QSqlTableModel>
#include  <QSqlQueryModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "dialogcreate.h"
#include <QMessageBox>

namespace Ui {
class DialogRoot;
}

class DialogRoot : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRoot(QWidget *parent = nullptr);
    ~DialogRoot();

private slots:
    void on_cancel_clicked();

    void on_addNew_clicked();

    void on_listAll_clicked();

    void on_quit_clicked();

    void on_credit_clicked();

    void on_debit_clicked();

    void on_transfer_clicked();

    void on_research_clicked();

    void on_statement_clicked();

    void on_pushButton_clicked();

private:
    Ui::DialogRoot *ui;
};

#endif // DIALOGROOT_H
