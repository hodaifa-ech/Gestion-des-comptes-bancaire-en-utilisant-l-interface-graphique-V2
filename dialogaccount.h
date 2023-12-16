#ifndef DIALOGACCOUNT_H
#define DIALOGACCOUNT_H

#include <QDialog>
#include "dialoglogin.h"
#include "OthersFunctions.h"
#include "dialogdebit.h"
#include "dialogtransfer.h"
#include "dialogconfiguration.h"
#include "dialogtransaction.h"

namespace Ui {
class DialogAccount;
}

class DialogAccount : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAccount(QWidget *parent = nullptr);
    ~DialogAccount();

private slots:
    void on_quit_clicked();

    void on_cancel_clicked();

    void on_credit_clicked();

    void on_refresh_clicked();

    void on_debit_clicked();

    void on_transfer_clicked();

    void on_mailMod_clicked();

    void on_statement_clicked();

    void on_loan_clicked();

private:
    Ui::DialogAccount *ui;
};

#endif // DIALOGACCOUNT_H
