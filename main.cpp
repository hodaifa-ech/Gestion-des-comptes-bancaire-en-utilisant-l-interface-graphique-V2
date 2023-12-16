#include "mainwindow0.h"
#include <QtGui>
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include "mediator.h"
#include "dialog1.h"
#include "dialog2.h"
#include "dialogaccount.h"
#include "dialogconfiguration.h"
#include "dialogconnexion.h"
#include "dialogcreate.h"
#include "dialogcredit.h"
#include "dialogcreditw.h"
#include "dialogdebit.h"
#include "dialogdebitw.h"
#include "dialogloan.h"
#include "dialoglogin.h"
#include "dialognewcount.h"
#include "dialogroot.h"
#include "dialogtransaction.h"
#include "dialogtransfer.h"
#include "dialogtransferw.h"

mediator mediator,newAccount,worker;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow0 w;
    Dialog2 d2;
    DialogAccount A;
    DialogConfiguration c;
    DialogConnexion co;
    DialogCreate cr;
    DialogCredit cre;
    DialogCreditW crew;
    DialogDebit de;
    DialogDebitW dew;
    DialogLoan lo;
    DialogLogin log;
    DialogNewCount ne;
    DialogRoot ro;
    DialogTransaction tr;
    DialogTransfer tra;
    DialogTransferW traw;


    w.setWindowTitle("FST BANK");
    w.setWindowIcon(QIcon(":/MesImages/MesImages/bank.png"));
    w.show();
    return a.exec();
}
