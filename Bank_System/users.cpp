#include "users.h"

Users::Users () {
}
Users::~Users() {
}

/// Getter Functions
QString Users::getFirstName () {
    return firstName;
}
QString Users::getLastName () {
    return lastName;
}
QString Users::getPassword () {
    return password;
}
QString Users::getUsername () {
    return username;
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
void Users::setFirstName (QString data) {
    firstName = data;
}
void Users::setLastName (QString data) {
    lastName = data;
}
void Users::setUsername (QString data) {
    username = data;
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

void Users::addUserToList() {
    usersList.pushBack(*this);
}
bool Users::searchPasswordInList(QString password){
    Node<Users> *tmp = usersList.getHeadNode();
    while (tmp) {
        if (tmp->getData().password == password)
            return true;
        tmp = tmp->getNextNode();
    }
    return false ;
}
bool Users::searchUsernameInList(QString username) {
    if(usersList.getSize() == 0)
        return false;
    Node<Users> *tmp = usersList.getHeadNode();
    while (tmp) {
        if (tmp->getData().username == username)
            return true;
        tmp = tmp->getNextNode();
    }
    return false ;
}

