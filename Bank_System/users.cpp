#include "users.h"

Users::Users () {
}
Users::~Users() {
}

/// Getter Functions
QString Users::getName () {
    return name;
}
QString Users::getLastName () {
    return lastName;
}
QString Users::getPassword () {
    return password;
}
QString Users::getUserName () {
    return userName;
}
BankAccount Users::getBankAccount (int idx) {
    return bankAccount[idx];
}
QString Users::getAge () {
    return age;
}
QString Users::getNationalCode () {
    return nationalCode;
}

/// Setter Functions
void Users::setAge (QString data) {
    age = data;
}
void Users::setName (QString data) {
    name = data;
}
void Users::setLastName (QString data) {
    lastName = data;
}
void Users::setUserName (QString data) {
    userName = data;
}
void Users::setBankAccount (BankAccount data, int idx) {
    bankAccount[idx] = data;
}
void Users::setPassword (QString data) {
    password = data;
}
void Users::setNationnalCode (QString data) {
    nationalCode = data;
}
