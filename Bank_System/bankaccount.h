#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <QString>



class BankAccount
{
private:
    QString accountType;
    QString cardNumber;
    QString shabaNumber;
    QString accountNumber;
    QString cvv2Number;
    QString cardPassword;
    QString fixedSecondPassword;
    QString dynamicSecondPassword;
    QString expirationDate;
    unsigned long int balance;


public:
    BankAccount();
    ~BankAccount();

    /// Setters
    void setBalance(unsigned long int);
    void setAccountType(QString);
    void setCardNumber(QString);
    void setShabaNumber(QString);
    void setAccountNumber(QString);
    void setCvv2Number(QString);
    void setCardPassword(QString);
    void setFixedSecondPassword(QString);
    void setDynamicSecondPassword(QString);
    void setExpirationDate(QString);

    /// Getters
    unsigned long int getBalance();
    QString getAccountType();
    QString getCardNumber();
    QString getShabaNumber();
    QString getAccountNumber();
    QString getCvv2Number();
    QString getCardPassword();
    QString getFixedSecondPassword();
    QString getDynamicSecondPassword();
    QString getExpirationDate();

};

#endif // BANKACCOUNT_H
