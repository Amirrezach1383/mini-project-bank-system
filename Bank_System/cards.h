#ifndef CARDS_H
#define CARDS_H
#include <QString>
#include <ctime>

class Cards
{
private:
    QString cardNumber;
    QString cvv2Number;
    QString cardPassword;
    QString fixedSecondPassword;
    tm expirationDate;

public:

    /// Setters
    void setCardNumber(QString);
    void setCvv2Number(QString);
    void setCardPassword(QString);
    void setFixedSecondPassword(QString);
    void setExpirationDate(tm);

    /// Getters
    QString getCardNumber();
    QString getCvv2Number();
    QString getCardPassword();
    QString getFixedSecondPassword();
    tm getExpirationDate();

};

#endif // CARDS_H
