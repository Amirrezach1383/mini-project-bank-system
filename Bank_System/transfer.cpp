#include "transfer.h"
#include "ui_transfer.h"
#include "users.h"
#include "userpanel.h"

Transfer::Transfer(Users users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::Transfer) {

    ui->setupUi(this);
    setUsersInformationInFormsLabels();

    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));

    /// Connect transfer PushButton
    connect(ui->transferPushButton, SIGNAL(clicked()), this, SLOT(transferPushButton()));

}
Transfer::~Transfer()
{
    delete ui;
}

///========== Private Slots =============
void Transfer::openUserPanelForm() {
    UserPanel *userPanel = new UserPanel(user);
    userPanel->show();
    this->close();
}

void Transfer::transferPushButton() {

    if(checkAllErrors()){

    }

}

///========== Check And Set Errors Functions ==========
bool Transfer::checkAllErrors (){
    bool checkAllErrors = true;

    if(!checkOrirginCardNumComboBoxError())
        checkAllErrors = false;

    if(!checkTransferAmountLineEditError())
        checkAllErrors = false;

    if(!checkSecondPasswordLineEditError())
        checkAllErrors = false;

    if(!checkDestinationCardNumLineEditError())
        checkAllErrors = false;

    if(!checkCvv2LineEditError())
        checkAllErrors = false;




    return checkAllErrors;
}

bool Transfer::checkOrirginCardNumComboBoxError(){
    if(ui->originCardNumberComboBax->currentText() == ""){
        ui->originCardNumComboBoxErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkOriginCardExpirationDate()){
        ui->originCardNumComboBoxErrorLabel->setText("This Card Has Expired");
        return false;
    }
    ui->originCardNumComboBoxErrorLabel->clear();
    return true;
}
bool Transfer::checkOriginCardExpirationDate() {
    QString cardNum = ui->originCardNumberComboBax->currentText();

    tm expirationDate = findOrirginCard(cardNum).getExpirationDate();

    if(isBeforeNow(expirationDate))
        return false;
    return true;


}

bool Transfer::checkTransferAmountLineEditError(){
    if(ui->transferAmountLineEdit->text() == "") {
        ui->transferAmountErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkSecondPasswordLineEditValid()) {
        ui->transferAmountErrorLabel->setText("Invalid Data");
        return false;
    }
    ui->transferAmountErrorLabel->clear();
    return true;
}
bool Transfer::checkTransferAmountLineEditValid(){
    QString transferAmount = ui->transferAmountLineEdit->text();
    int i = 0;

    while (i < ui->transferAmountLineEdit->text().length()) {
        if(!('0' <= transferAmount[i] && transferAmount[i] <= '9')) {
            return false;
        }
        i++;
    }
    return true;
}

bool Transfer::checkSecondPasswordLineEditError(){
    if(ui->secondPasswordLineEdit->text() == "") {
        ui->secondPasswordErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkSecondPasswordLineEditValid()) {
        ui->secondPasswordErrorLabel->setText("Invalid Data");
        return false;
    }
    if(!checkSecondPasswordLineEditExist()) {
        ui->secondPasswordErrorLabel->setText("Incorrect Password");
        return false;
    }
    ui->secondPasswordErrorLabel->clear();
    return true;

}
bool Transfer::checkSecondPasswordLineEditValid(){
    QString secondPassword = ui->secondPasswordLineEdit->text();
    int i = 0;

    while (i < ui->secondPasswordLineEdit->text().length()) {
        if(!('0' <= secondPassword[i] && secondPassword[i] <= '9')) {
            return false;
        }
        i++;
    }
    return true;

}
bool Transfer::checkSecondPasswordLineEditExist(){
    QString secondPassword = ui->secondPasswordLineEdit->text();

    if(!searchSecondPassword(secondPassword))
        return false;
    return true;

}


bool Transfer::checkDestinationCardNumLineEditError(){
    if(ui->distinationCardNumberLineEdit->text() == "") {
        ui->disCardNumComboBoxErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkDestinationCardNumLineValid()) {
        ui->disCardNumComboBoxErrorLabel->setText("Invalid Data");
        return false;
    }
    if(!checkDestinationCardNumLineEditExist()) {
        ui->disCardNumComboBoxErrorLabel->setText("This User Doesn't Exists");
        return false;
    }
    if(!checkDestinationCardExpiration()) {
        ui->disCardNumComboBoxErrorLabel->setText("This Card Has Expired");
    }
    ui->disCardNumComboBoxErrorLabel->clear();
    return true;


}
bool Transfer::checkDestinationCardNumLineValid(){
    QString cvv2 = ui->distinationCardNumberLineEdit->text();
    int i = 0;

    while (i < ui->distinationCardNumberLineEdit->text().length()) {
        if(!('0' <= cvv2[i] && cvv2[i] <= '9')) {
            return false;
        }
        i++;
    }
    return true;

}
bool Transfer::checkDestinationCardNumLineEditExist(){
    QString cardNum = ui->distinationCardNumberLineEdit->text();

    if(!searchCard(cardNum))
        return false;
    return true;
}
bool Transfer::checkDestinationCardExpiration(){
    QString desCardNum = ui->originCardNumberComboBax->currentText();
    tm expirationDate = findDesCard(desCardNum).getExpirationDate();

    if(isBeforeNow(expirationDate))
        return false;
    return true;
}


bool Transfer::checkCvv2LineEditError(){
    if(ui->cvv2LineEdit->text() == "") {
        ui->cvv2ErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkCvv2LineEditValid()) {
        ui->cvv2ErrorLabel->setText("Invalid Data");
        return false;
    }
    if(!checkCvv2LineEditExist()) {
        ui->cvv2ErrorLabel->setText("Incorrect Password");
        return false;
    }
    ui->cvv2ErrorLabel->clear();
    return true;

}
bool Transfer::checkCvv2LineEditValid(){

    QString cvv2 = ui->cvv2LineEdit->text();
    int i = 0;

    while (i < ui->cvv2LineEdit->text().length()) {
        if(!('0' <= cvv2[i] && cvv2[i] <= '9')) {
            return false;
        }
        i++;
    }
    return true;

}
bool Transfer::checkCvv2LineEditExist(){
    QString cardNum = ui->originCardNumberComboBax->currentText();
    QString cvv2 = ui->cvv2LineEdit->text();

    Node<BankAccount> *tmp = user.userBankAccountsList.getHeadNode();

    while (tmp) {
        if(tmp->getData().getCard().getCardNumber() == cardNum) {
            if(cvv2 == tmp->getData().getCard().getCvv2Number()) {
                return true;
            }
        }
        tmp = tmp->getNextNode();
    }
    return false;
}

/// Set Destination Account's User's INFO
void Transfer::setDesUserInfo(){
    Users desUser = findDesUser();

    ui->toLabelEdit->setText(desUser.getFirstName() + " " + desUser.getLastName());
}


/// Search Function
bool Transfer::searchCard(QString cardNum){
    Node<Users> *tmp = user.usersList.getHeadNode();
    Node<BankAccount> *tmpBankAccount;
    while(tmp) {
        tmpBankAccount = tmp->getData().userBankAccountsList.getHeadNode();
        while(tmpBankAccount) {
            if(tmpBankAccount->getData().getCard().getCardNumber() == cardNum)
                return true;
            tmpBankAccount = tmpBankAccount->getNextNode();
        }
        tmp = tmp->getNextNode();
    }
    return false;
}
bool Transfer::searchSecondPassword(QString secondPassword){
    Node<Users> *tmp = user.usersList.getHeadNode();
    Node<BankAccount> *tmpBankAccount;
    while(tmp) {
        tmpBankAccount = tmp->getData().userBankAccountsList.getHeadNode();
        while(tmpBankAccount) {
            if(tmpBankAccount->getData().getCard().getFixedSecondPassword() == secondPassword)
                return true;
            tmpBankAccount = tmpBankAccount->getNextNode();
        }
        tmp = tmp->getNextNode();
    }
    return false;
}

Cards Transfer::findOrirginCard(QString cardNum){

    Node<BankAccount> *tmp = user.userBankAccountsList.getHeadNode();

    while(tmp) {
        if(cardNum == tmp->getData().getCard().getCardNumber()) {
            return tmp->getData().getCard();
        }
        tmp = tmp->getNextNode();
    }
    return *new Cards;

}
Cards Transfer::findDesCard(QString cardNum){
        Node<Users> *tmp = user.usersList.getHeadNode();
    Node<BankAccount> *tmpBankAccount;
    while(tmp) {
        tmpBankAccount = tmp->getData().userBankAccountsList.getHeadNode();
        while(tmpBankAccount) {
            if(tmpBankAccount->getData().getCard().getCardNumber() == cardNum)
                return tmpBankAccount->getData().getCard();
            tmpBankAccount = tmpBankAccount->getNextNode();
        }
        tmp = tmp->getNextNode();
    }
    return *new Cards;
}

Users Transfer::findDesUser(){
    QString desCardNum = ui->distinationCardNumberLineEdit->text();

    Node<Users> *tmp = user.usersList.getHeadNode();
    Node<BankAccount> *tmpBankAccount;
    while(tmp) {
        tmpBankAccount = tmp->getData().userBankAccountsList.getHeadNode();
        while(tmpBankAccount) {
            if(tmpBankAccount->getData().getCard().getCardNumber() == desCardNum)
                return tmp->getData();
            tmpBankAccount = tmpBankAccount->getNextNode();
        }
        tmp = tmp->getNextNode();
    }
    return *new Users;

}

/// Set Users Informations
void Transfer::setUsersInformationInFormsLabels () {
    ui->firstNameLabel->setText(user.getFirstName());
    ui->lastNameLabel->setText(user.getLastName());
    ui->nationalCodeLabel->setText(user.getNationalCode());
}

/// Time Functions
bool Transfer::isBeforeNow(const std::tm& date){

    std::time_t now = std::time(nullptr);
    std::time_t inputTime = std::mktime(const_cast<std::tm*>(&date));

    return inputTime < now;
}




