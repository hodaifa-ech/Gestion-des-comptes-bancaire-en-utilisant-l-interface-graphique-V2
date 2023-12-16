#ifndef DIALOGCONFIGURATION_H
#define DIALOGCONFIGURATION_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include "mediator.h"
#include "dbConnexion.h"
#include <QSqlQuery>

namespace Ui {
class DialogConfiguration;
}

class DialogConfiguration : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConfiguration(QWidget *parent = nullptr);
    ~DialogConfiguration();

private slots:
    void on_ok_clicked();

    void on_pushButton_clicked();

    void on_cancel_clicked();

private:
    Ui::DialogConfiguration *ui;
};

#endif // DIALOGCONFIGURATION_H
