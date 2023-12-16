#ifndef SQLCONNEXION_H
#define SQLCONNEXION_H

#include "QSqlDatabase"
#include "QSqlQuery"

static bool connexionBd()
{
    QSqlDatabase DataB = QSqlDatabase::addDatabase("QSQLITE");
    //DataB.setHostName("127.0.0.1");
    //DataB.setUserName("root");
    DataB.setDatabaseName("Clients_Banque.db");
    //DataB.setPort(3306);
    //DataB.setPassword("");

    if(DataB.open())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif // SQLCONNEXION_H
