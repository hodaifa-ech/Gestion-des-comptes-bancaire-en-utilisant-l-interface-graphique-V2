#ifndef DIALOGCREDIT_H
#define DIALOGCREDIT_H

#include <QDialog>

namespace Ui {
class DialogCredit;
}

class DialogCredit : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCredit(QWidget *parent = nullptr);
    ~DialogCredit();

private slots:
    void on_ok_clicked();

    void on_close_clicked();

private:
    Ui::DialogCredit *ui;
};

#endif // DIALOGCREDIT_H
