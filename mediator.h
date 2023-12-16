#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QString>

class mediator
{
public:
    mediator();
    QString getnum();
    QString gettype();
    QString getname();
    double getbalance();
    double getcredit();
    void setnum(QString);
    void setbalance(double);
    void settype(QString);
    void setname(QString);
    void setCredit(double);
private:
    QString g_num,g_name,g_type;
    double g_balance,g_credit;
};

#endif // MEDIATOR_H
