#ifndef USERS_H
#define USERS_H
#include <QString>
#include <bankaccount.h>

class Users {
private:
    QString name;
    QString lastName;
    QString nationalCode;
    QString age;
    QString password;
    QString userName;
    BankAccount bankAccount[5];

public:
    Users();
    ~Users();
    ///set data
    void setName (QString);
    void setLastName (QString);
    void setAge (QString);
    void setNationnalCode (QString);
    void setUserName (QString);
    void setBankAccount (BankAccount, int);
    void setPassword (QString);

    ///get data
    QString getName ();
    QString getLastName ();
    QString getAge ();
    QString getNationalCode ();
    QString getUserName ();
    QString getPassword ();
    BankAccount getBankAccount (int);
};

#endif // USERS_H
