#include "bankaccount.h"

/// Setter Functions
void BankAccount::setAccountNumber(QString data){
    accountNumber = data;
}
void BankAccount::setAccountType(QString data) {
    accountType = data;
}
void BankAccount::setBalance(unsigned long int data) {
    balance = data;
}
void BankAccount::setCardPassword(QString data) {
    cardPassword = data;
}
void BankAccount::setShabaNumber(QString data) {
    shabaNumber = data;
}
void BankAccount::setCardNumber(QString data) {
    cardNumber = data;
}
void BankAccount::setCvv2Number(QString data) {
    cvv2Number = data;
}
void BankAccount::setDynamicSecondPassword(QString data) {
    dynamicSecondPassword = data;
}
void BankAccount::setExpirationDate(QString data) {
    expirationDate = data;
}
void BankAccount::setFixedSecondPassword(QString data) {
    fixedSecondPassword = data;
}

/// Getter Functions
QString BankAccount::getAccountNumber() {
    return accountNumber;
}
QString BankAccount::getAccountType() {
    return accountType;
}
unsigned long int BankAccount::getBalance() {
    return balance;
}
QString BankAccount::getCardPassword() {
    return cardPassword;
}
QString BankAccount::getShabaNumber() {
    return shabaNumber;
}
QString BankAccount::getCardNumber() {
    return cardNumber;
}
QString BankAccount::getCvv2Number() {
    return cvv2Number;
}
QString BankAccount::getDynamicSecondPassword() {
    return dynamicSecondPassword;
}
QString BankAccount::getExpirationDate() {
    return expirationDate;
}
QString BankAccount::getFixedSecondPassword() {
    return fixedSecondPassword;
}
