#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <QString>
#include <cards.h>
#include <ctime>


class BankAccount
{
private:
    QString accountType;
    QString shabaNumber;
    QString accountNumber;
    QString dynamicSecondPassword;
    long long int balance;
    Cards card;
    tm lastTransactionDate;
    long long int lastTransactionAmount;

public:

    BankAccount();

    /// Setters
    void setCard(Cards);
    void setBalance(long long int);
    void setAccountType(QString);
    void setShabaNumber(QString);
    void setAccountNumber(QString);
    void setDynamicSecondPassword(QString);
    void setLastTransactionDate(tm);
    void setLastTransactionAmount(long long int);


    /// Getters
    Cards getCard();
    long long int getBalance();
    QString getAccountType();
    QString getShabaNumber();
    QString getAccountNumber();
    QString getDynamicSecondPassword();
    tm getLastTransactionDate();
    long long int getLastTransactionAmount();


};

#endif // BANKACCOUNT_H
