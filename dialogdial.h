#ifndef DIALOGDIAL_H
#define DIALOGDIAL_H

#include <QDialog>
#include "OthersFunctions.h"


namespace Ui {
class DialogDial;
}

class DialogDial : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDial(QWidget *parent = nullptr);
    ~DialogDial();

private slots:
    void on_dial_valueChanged(int value);

    void on_dial2_valueChanged(int value);

    void on_dial3_valueChanged(int value);

    void on_ok_clicked();

private:
    Ui::DialogDial *ui;
    int value1, value2, value3;
};

#endif // DIALOGDIAL_H
