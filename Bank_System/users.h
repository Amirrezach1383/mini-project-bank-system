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
    BankAccount bankAccount;

public:
    Users();
    ~Users();

    ///set data
    void setName (QString);
    void setLastName (QString);
    void setAge (QString);
    void setNationnalCode (QString);
    void setUserName (QString);
    void setBankAccount (BankAccount);
    void setPassword (QString);

    ///get data
    QString getName ();
    QString getLastName ();
    QString getAge ();
    QString getNationalCode ();
    QString getUserName ();
    QString getPassword ();
    BankAccount getBankAccount ();
};

#endif // USERS_H
