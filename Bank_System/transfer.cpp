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
    ui->originCardNumComboBoxErrorLabel->clear();
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

/// Set Users Informations

void Transfer::setUsersInformationInFormsLabels () {
    ui->firstNameLabel->setText(user.getFirstName());
    ui->lastNameLabel->setText(user.getLastName());
    ui->nationalCodeLabel->setText(user.getNationalCode());
}
