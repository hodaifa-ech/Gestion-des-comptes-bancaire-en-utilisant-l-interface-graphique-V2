#include "dialogtransaction.h"
#include "ui_dialogtransaction.h"

extern mediator mediator;
DialogTransaction::DialogTransaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTransaction)
{
    ui->setupUi(this);
    QSqlQuery request(QSqlDatabase::database("MyConnect"));
    QString result = "DATE\t\tTIME\t\tTRANSACTION TYPE\tTRANSACTION BALANCE\t\tACCOUNTNUMBERD\tACCOUNTNUMBERC\n";
    request.prepare("SELECT * FROM Transactions WHERE AccountNumberP = :accountnumber OR AccountNumberS = :accountnumber");// AND password = :password");
    request.bindValue(":accountnumber",mediator.getnum());

    if(request.exec())
    {
        while(request.next())
        {
            QString date = request.value(0).toString();
            QString time = request.value(1).toString();
            QString type0 = request.value(3).toString();
            QString balance = request.value(2).toString();
            QString type1 = request.value(4).toString();
            QString type2 = request.value(5).toString();
            result = result + date + "\t" + time + "\t\t" + balance + "\t\t\t\t" + type0 + "\t\t\t" + type1 + "\t\t" + type2 + "\n";
        }
        ui->label->setText(result);
    }

}

DialogTransaction::~DialogTransaction()
{
    delete ui;
}
