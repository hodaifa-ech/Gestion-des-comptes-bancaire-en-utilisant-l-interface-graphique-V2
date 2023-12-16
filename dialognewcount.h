#ifndef DIALOGNEWCOUNT_H
#define DIALOGNEWCOUNT_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "OthersFunctions.h"
#include "mediator.h"

namespace Ui {
class DialogNewCount;
}

class DialogNewCount : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewCount(QWidget *parent = nullptr);
    ~DialogNewCount();

private slots:
    void on_login_clicked();

    void on_quit_clicked();

    void on_advantageButton_clicked();

private:
    Ui::DialogNewCount *ui;
};

#endif // DIALOGNEWCOUNT_H
