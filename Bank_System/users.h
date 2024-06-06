#ifndef USERS_H
#define USERS_H
#include <QString>
#include <bankaccount.h>
#include "linklist.h"

class Users {
private:
    QString firstName;
    QString lastName;
    QString nationalCode;
    QString age;
    QString password;
    QString username;
    BankAccount bankAccount[5];
    int numOfUserAccount;

public:
    LinkList<Users> usersList;

    Users ();

    ///set data
    void setFirstName (QString);
    void setLastName (QString);
    void setAge (QString);
    void setNationnalCode (QString);
    void setUsername (QString);
    void setBankAccount (BankAccount, int);
    void setPassword (QString);
    void setNumOfUserAccount (int);


    ///get data
    QString getFirstName ();
    QString getLastName ();
    QString getAge ();
    QString getNationalCode ();
    QString getUsername ();
    QString getPassword ();
    BankAccount getBankAccount (int);
    int getNumOfUserAccount();

    void addUserToList();
    bool searchPasswordInList(QString);

};

#endif // USERS_H
