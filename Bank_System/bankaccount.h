#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <QString>
#include <cards.h>


class BankAccount
{
private:
    QString accountType;
    QString shabaNumber;
    QString accountNumber;
    QString dynamicSecondPassword;
    long long int balance;
    Cards card;

public:

    /// Setters
    void setCard(Cards);
    void setBalance(long long int);
    void setAccountType(QString);
    void setShabaNumber(QString);
    void setAccountNumber(QString);
    void setDynamicSecondPassword(QString);


    /// Getters
    Cards getCard();
    long long int getBalance();
    QString getAccountType();
    QString getShabaNumber();
    QString getAccountNumber();
    QString getDynamicSecondPassword();
};

#endif // BANKACCOUNT_H
