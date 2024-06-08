#include "cards.h"


/// Setters Functions
void Cards::setCardPassword(QString data) {
    cardPassword = data;
}
void Cards::setCardNumber(QString data) {
    cardNumber = data;
}
void Cards::setCvv2Number(QString data) {
    cvv2Number = data;
}
void Cards::setExpirationDate(tm data) {
    expirationDate = data;
}
void Cards::setFixedSecondPassword(QString data) {
    fixedSecondPassword = data;
}

/// Gettrs Functions
QString Cards::getCardPassword() {
    return cardPassword;
}
QString Cards::getCardNumber() {
    return cardNumber;
}
QString Cards::getCvv2Number() {
    return cvv2Number;
}
tm Cards::getExpirationDate() {
    return expirationDate;
}
QString Cards::getFixedSecondPassword() {
    return fixedSecondPassword;
}
