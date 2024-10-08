#include "users.h"

Users::Users() {
    numOfUserAccount = 0;
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
QString Users::getAge () {
    return age;
}
QString Users::getNationalCode () {
    return nationalCode;
}
int Users::getNumOfUserAccount() {
    return numOfUserAccount;
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
void Users::setPassword (QString data) {
    password = data;
}
void Users::setNationnalCode (QString data) {
    nationalCode = data;
}
void Users::setNumOfUserAccount (int data) {
    numOfUserAccount = data;
}

void Users::addUserToList() {
    usersList.pushBack(*this);
}
void Users::addBankAccountToList(BankAccount bankAccount){

    this->userBankAccountsList.pushBack(bankAccount);
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
