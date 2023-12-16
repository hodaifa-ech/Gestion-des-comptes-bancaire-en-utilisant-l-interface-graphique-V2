#include "mediator.h"

mediator::mediator()
{
    g_num = "";g_balance = 0;g_type = "";g_name = "";g_credit = 0;
}

QString mediator::getnum()
{
    return g_num;
}
double mediator::getbalance()
{
    return g_balance;
}
QString mediator::gettype()
{
    return g_type;
}
QString mediator::getname()
{
    return g_name;
}
double mediator::getcredit()
{
    return g_credit;
}
void mediator::setnum(QString m)
{
    g_num = m;
}
void mediator::settype(QString m)
{
    g_type = m;
}
void mediator::setname(QString m)
{
    g_name = m;
}
void mediator::setbalance(double m)
{
    g_balance = m;
}
void mediator::setCredit(double m)
{
    g_credit = m;
}
