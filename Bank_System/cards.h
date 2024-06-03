#ifndef CARDS_H
#define CARDS_H
#include <QString>

class Cards
{
private:
    QString cardNumber;
    QString cvv2Number;
    QString cardPassword;
    QString fixedSecondPassword;
    QString expirationDate;

public:
    Cards();
    ~Cards();

    /// Setters
    void setCardNumber(QString);
    void setCvv2Number(QString);
    void setCardPassword(QString);
    void setFixedSecondPassword(QString);
    void setExpirationDate(QString);

    /// Getters
    QString getCardNumber();
    QString getCvv2Number();
    QString getCardPassword();
    QString getFixedSecondPassword();
    QString getExpirationDate();

};

#endif // CARDS_H
