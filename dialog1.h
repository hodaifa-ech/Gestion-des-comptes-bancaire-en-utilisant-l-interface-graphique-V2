#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private slots:
    void on_login_clicked();

    void on_newCount_clicked();

    void on_quit_clicked();

    void on_cancel_clicked();

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
