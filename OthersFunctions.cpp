#include "OthersFunctions.h"

QString Cryptographie(QString m)
{
    QString pC;
    QVector <char> chiffrer;
    for (int i = 0; i < m.length(); i++)
    {
        if (m[i] == 'a')
            chiffrer.push_back('d');
        else if (m[i] == 'b')
            chiffrer.push_back('e');
        else if (m[i] == 'b')
            chiffrer.push_back('f');
        else if (m[i] == 'd')
            chiffrer.push_back('g');
        else if (m[i] == 'e')
            chiffrer.push_back('h');
        else if (m[i] == 'f')
            chiffrer.push_back('i');
        else if (m[i] == 'g')
            chiffrer.push_back('j');
        else if (m[i] == 'h')
            chiffrer.push_back('k');
        else if (m[i] == 'i')
            chiffrer.push_back('l');
        else if (m[i] == 'j')
            chiffrer.push_back('m');
        else if (m[i] == 'k')
            chiffrer.push_back('n');
        else if (m[i] == 'l')
            chiffrer.push_back('o');
        else if (m[i] == 'm')
            chiffrer.push_back('p');
        else if (m[i] == 'n')
            chiffrer.push_back('q');
        else if (m[i] == 'o')
            chiffrer.push_back('r');
        else if (m[i] == 'p')
            chiffrer.push_back('s');
        else if (m[i] == 'q')
            chiffrer.push_back('t');
        else if (m[i] == 'r')
            chiffrer.push_back('u');
        else if (m[i] == 's')
            chiffrer.push_back('v');
        else if (m[i] == 't')
            chiffrer.push_back('w');
        else if (m[i] == 'u')
            chiffrer.push_back('x');
        else if (m[i] == 'v')
            chiffrer.push_back('y');
        else if (m[i] == 'w')
            chiffrer.push_back('z');
        else if (m[i] == 'x')
            chiffrer.push_back('0');
        else if (m[i] == 'y')
            chiffrer.push_back('1');
        else if (m[i] == 'z')
            chiffrer.push_back('2');
        else if (m[i] == '0')
            chiffrer.push_back('3');
        else if (m[i] == '1')
            chiffrer.push_back('4');
        else if (m[i] == '2')
            chiffrer.push_back('5');
        else if (m[i] == '3')
            chiffrer.push_back('6');
        else if (m[i] == '4')
            chiffrer.push_back('7');
        else if (m[i] == '5')
            chiffrer.push_back('8');
        else if (m[i] == '6')
            chiffrer.push_back('9');
        else if (m[i] == '7')
            chiffrer.push_back('a');
        else if (m[i] == '8')
            chiffrer.push_back('b');
        else if (m[i] == '9')
            chiffrer.push_back('c');
    }
    for (auto element:chiffrer)
        pC = pC + element;
    return pC;
}

int CustomersNumber()
{
    int a(0);
    bool good(dbConnected());
    if (good)
    {
        QSqlQuery request(QSqlDatabase::database("MyConnect"));
        request.prepare("SELECT * FROM Customers");
        if(request.exec())
            while(request.next())
                a+=1;//to be reviewed....................
        else
            return -1;
    }
    return a;
}
