#ifndef DIALOGCREATE_H
#define DIALOGCREATE_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "OthersFunctions.h"

namespace Ui {
class DialogCreate;
}

class DialogCreate : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreate(QWidget *parent = nullptr);
    ~DialogCreate();
    QString GenerateAccountNumber(QString,QString,int);

private slots:

    void on_saveData_clicked();

    void on_quit_clicked();

    void on_cancel_clicked();

private:
    Ui::DialogCreate *ui;
    QString m_accountNumberG;
};

#endif // DIALOGCREATE_H
