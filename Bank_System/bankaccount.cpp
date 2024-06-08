#include "bankaccount.h"

/// Setter Functions
void BankAccount::setAccountNumber(QString data){
    accountNumber = data;
}
void BankAccount::setAccountType(QString data) {
    accountType = data;
}
void BankAccount::setBalance(long long int data) {
    balance = data;
}
void BankAccount::setShabaNumber(QString data) {
    shabaNumber = data;
}
void BankAccount::setDynamicSecondPassword(QString data) {
    dynamicSecondPassword = data;
}
void BankAccount::setCard(Cards data) {
    card = data;
}

/// Getter Functions
QString BankAccount::getAccountNumber() {
    return accountNumber;
}
QString BankAccount::getAccountType() {
    return accountType;
}
long long int BankAccount::getBalance() {
    return balance;
}
QString BankAccount::getShabaNumber() {
    return shabaNumber;
}
QString BankAccount::getDynamicSecondPassword() {
    return dynamicSecondPassword;
}
Cards BankAccount::getCard () {
    return card;
}

