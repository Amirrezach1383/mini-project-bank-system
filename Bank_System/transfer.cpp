#include "transfer.h"
#include "ui_transfer.h"
#include "users.h"
#include "userpanel.h"

Transfer::Transfer(Users users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::Transfer) {

    ui->setupUi(this);
    setUsersInformationInFormsLabels();

    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));


}

Transfer::~Transfer()
{
    delete ui;
}

/// Private Slots
void Transfer::openUserPanelForm() {
    UserPanel *userPanel = new UserPanel(user);
    userPanel->show();
    this->close();
}

///========== Check And Set Errors Functions ==========

bool Transfer::checkAllErrors (){

}

bool Transfer::checkOrirginCardNumComboBoxError(){
    if(ui->originCardNumberComboBax->currentText() == ""){
        ui->originCardNumComboBoxErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    ui->originCardNumComboBoxErrorLabel->clear();
    return true;
}

bool Transfer::checkTransferAmountLineEditError(){

}

bool Transfer::checkSecondPasswordLineEditError(){

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
        ui->disCardNumComboBoxErrorLabel->setText("Incorrect Card Number");
        return false;
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

/// Serch Function
bool Transfer::searchCard (QString cardNum){
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


/// Set Users Informations

void Transfer::setUsersInformationInFormsLabels () {
    ui->firstNameLabel->setText(user.getFirstName());
    ui->lastNameLabel->setText(user.getLastName());
    ui->nationalCodeLabel->setText(user.getNationalCode());
}
