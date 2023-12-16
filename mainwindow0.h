#ifndef MAINWINDOW0_H
#define MAINWINDOW0_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "OthersFunctions.h"

namespace Ui {
class MainWindow0;
}

class MainWindow0 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow0(QWidget *parent = nullptr);
    ~MainWindow0();

private slots:
    void on_quit0_clicked();

    void on_logon0_clicked();

    void on_aboutB_clicked();

private:
    Ui::MainWindow0 *ui;
};

#endif // MAINWINDOW0_H
