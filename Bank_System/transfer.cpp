#include "transfer.h"
#include "ui_transfer.h"
#include "users.h"
#include "userpanel.h"

Transfer::Transfer(Users users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::Transfer) {

    ui->setupUi(this);
    setUsersInformationInFormsLabels();
    setUsersCardsInformation();
    setUserBalanceInForm();

    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));

    /// Connect transfer PushButton
    connect(ui->transferPushButton, SIGNAL(clicked()), this, SLOT(transferPushButton()));

    /// Connect ComboBox to Balance Value
    connect(ui->originCardNumberComboBax, SIGNAL(activated(int)), this, SLOT(setUserBalanceInForm()));

    /// Connect getSecondPassPushButton
    connect(ui->getSecondPasswordPushButton, SIGNAL(clicked()), this, SLOT(getSecondPassPushButton()));

    /// Connect Destination Card Number
    connect(ui->distinationCardNumberLineEdit, SIGNAL(textChanged(QString)), this, SLOT(destinationCardNumberLineEdit()));

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

void Transfer::setUserBalanceInForm() {
    QString cardNum = ui->originCardNumberComboBax->currentText();
    ui->yourBalanceValueLabel->setText(QString::number(findOriginCardBankAccount(cardNum).getBalance()));
}
void Transfer::getSecondPassPushButton(){

    if(checkChangePasswordError()) {
        ui->secondPasswordErrorLabel->clear();
        if(checkGetSecondPasswordLineEditErorr()) {
            ui->secondPasswordLineEdit->setEnabled(false);
            setRandomSecondPassword();
        }
        else
            ui->secondPasswordErrorLabel->setText("You Have Requested A Password Once");
    }
}
void Transfer::transferPushButton() {

    if(checkAllErrors()){
        setChangeInDestinationAccount();
        setChangeInOriginAccount();
        checkAndUpdateLastTransactionDate();
    }

}

void Transfer::destinationCardNumberLineEdit(){
    if(checkDestinationCardNumLineEditError())
        setDesUserInfo();

}

/// Other Functions
void Transfer::setRandomSecondPassword(){
    int randomNum = getRandomNumber();

    srand(time(0));

    randomNum += (rand() % 8990000) + 1000000;

    ui->secondPasswordLineEdit->setText(QString::number(randomNum));
    secondTimePassword = QString::number(randomNum);

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

    if(!checkTheCardsNumSame())
        checkAllErrors = false;

    if(!checkTransferAmountIn24Hour())
        checkAllErrors = false;

    return checkAllErrors;
}

bool Transfer::checkChangePasswordError(){
    bool checkAllErrors = true;

    if(!checkOrirginCardNumComboBoxError())
        checkAllErrors = false;

    if(!checkTransferAmountLineEditError())
        checkAllErrors = false;

    if(!checkDestinationCardNumLineEditError())
        checkAllErrors = false;

    if(!checkCvv2LineEditError())
        checkAllErrors = false;

    if(!checkTransferAmountIn24Hour())
        checkAllErrors = false;

    return checkAllErrors;

}

bool Transfer::checkTheCardsNumSame(){
    if(ui->originCardNumberComboBax->currentText() == ui->distinationCardNumberLineEdit->text()) {
        ui->transferErrorLabel->setText("Please Enter Differnt Card Number");
        return false;
    }
    ui->transferErrorLabel->clear();
    return true;
}

bool Transfer::checkOrirginCardNumComboBoxError(){
    if(ui->originCardNumberComboBax->currentText() == ""){
        ui->originCardNumComboBoxErrorLabel->setText("Please Select A Card Number");
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
    if(!checkTransferAmountInRange()) {
        ui->transferAmountErrorLabel->setText("Card Balance Is Insufficient");
        return false;
    }
    if(!checkTransferAmountIn24Hour()){
        ui->transferErrorLabel->setText("You Can't Transfer More");
        return false;
    }
    if(!checkTransferAmountsRange()){
        ui->transferErrorLabel->setText("Transfer Amount Is Out Of Range");
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
bool Transfer::checkTransferAmountInRange(){

    QString cardNum = ui->originCardNumberComboBax->currentText();
    long long int balance = findOriginCardBankAccount(cardNum).getBalance();

    if(ui->transferAmountLineEdit->text().toLongLong() >= balance)
        return false;

    return true;
}
bool Transfer::checkTransferAmountIn24Hour() {
    BankAccount bankAccount = findOriginCardBankAccount(ui->originCardNumberComboBax->currentText());
    if(bankAccount.getLastTransactionAmount() == 0)
        return true;
    long long int transferAmount = ui->transferAmountLineEdit->text().toLongLong();

    if((transferAmount + bankAccount.getLastTransactionAmount()) > 6000000)
        if(!checkPassed24hour(bankAccount.getLastTransactionDate()))
            return false;

    return true;

}
bool Transfer::checkTransferAmountsRange(){

    QString transferAmount = ui->transferAmountLineEdit->text();
    long long int transferAmountInt = transferAmount.toLongLong();

    if(transferAmountInt > 3000000 || transferAmountInt < 1000)
        return false;
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
    if(ui->transferAmountLineEdit->text().toLongLong() > 100000) {
        ui->secondPasswordErrorLabel->setText("You Can't Transfer More Than 100 000 With Fixed Password");
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

    if(ui->secondPasswordLineEdit->text() == secondPassword)
        return true;

    if(!searchSecondPassword(secondPassword))
        return false;

    return true;

}
bool Transfer::checkGetSecondPasswordLineEditErorr(){

    if(ui->secondPasswordLineEdit->isEnabled()) {
        return true;
    }
    return false;
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
        ui->cvv2ErrorLabel->setText("Incorrect");
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

/// Set Changes in Users BankAccounts
void Transfer::setChangeInDestinationAccount(){
    BankAccount bankAccount = findDesCardBankAccount(ui->distinationCardNumberLineEdit->text());
    long long int transferAmount = ui->transferAmountLineEdit->text().toLongLong();

    bankAccount.setBalance(bankAccount.getBalance() + transferAmount);
    setDateAndAmountLastTransacion(bankAccount);
    updateUsersBankAccount(bankAccount);
}
void Transfer::setChangeInOriginAccount(){
    BankAccount bankAccount = findOriginCardBankAccount(ui->originCardNumberComboBax->currentText());
    long long int transferAmount = ui->transferAmountLineEdit->text().toLongLong();

    bankAccount.setBalance(bankAccount.getBalance() - transferAmount - (transferAmount * 0.0001));
    setDateAndAmountLastTransacion(bankAccount);
    updateUsersBankAccount(bankAccount);
}

void Transfer::updateUsersBankAccount(BankAccount bankAccount) {
    Node<Users> *tmp = user.usersList.getHeadNode();
    while (tmp) {
        Node<BankAccount> *bankAccountTmp = user.userBankAccountsList.getHeadNode();
        while(bankAccountTmp) {
            if(bankAccountTmp->getData().getAccountNumber() == bankAccount.getAccountNumber()) {
                bankAccountTmp->setData(bankAccount);
                return;
            }
            bankAccountTmp = bankAccountTmp->getNextNode();
        }
        tmp = tmp->getNextNode();
    }
}

void Transfer::setDateAndAmountLastTransacion(BankAccount& bankAccount){
    if(bankAccount.getLastTransactionAmount() == 0) {
        time_t now = time(0);
        bankAccount.setLastTransactionDate(*localtime(&now));
    }
    bankAccount.setLastTransactionAmount(bankAccount.getLastTransactionAmount() + ui->transferAmountLineEdit->text().toLongLong());
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
    Node<BankAccount> *tmpBankAccount;

    tmpBankAccount = user.userBankAccountsList.getHeadNode();
    while(tmpBankAccount) {
        if(tmpBankAccount->getData().getCard().getFixedSecondPassword() == secondPassword)
            return true;
        tmpBankAccount = tmpBankAccount->getNextNode();
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

BankAccount Transfer::findOriginCardBankAccount(QString cardNum) {
    Node<BankAccount> *tmpBankAccount;

    tmpBankAccount = user.userBankAccountsList.getHeadNode();
    while(tmpBankAccount) {
        if(tmpBankAccount->getData().getCard().getCardNumber() == cardNum)
            return tmpBankAccount->getData();
        tmpBankAccount = tmpBankAccount->getNextNode();
    }

    return *new BankAccount;

}
BankAccount Transfer::findDesCardBankAccount(QString cardNum) {
    Node<Users> *tmp = user.usersList.getHeadNode();

    while(tmp) {
        Node<BankAccount> *bankAccount = user.userBankAccountsList.getHeadNode();
        while(bankAccount) {
            if(bankAccount->getData().getCard().getCardNumber() == cardNum)
                return bankAccount->getData();
            bankAccount = bankAccount->getNextNode();
        }
        tmp = tmp->getNextNode();
    }
    return *new BankAccount;

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
    ui->firstNameLabel->setText(user.getFirstName() + " " + user.getLastName());
    ui->nationalCodeLabel->setText(user.getNationalCode());
}

void Transfer::setUsersCardsInformation(){
    Node<BankAccount> *tmp = user.userBankAccountsList.getHeadNode();
    while(tmp){
        ui->originCardNumberComboBax->addItem(tmp->getData().getCard().getCardNumber());
        tmp = tmp->getNextNode();
    }
}

/// Time Functions
bool Transfer::isBeforeNow(const std::tm& date){

    std::time_t now = std::time(nullptr);
    std::time_t inputTime = std::mktime(const_cast<std::tm*>(&date));

    return inputTime < now;
}
bool Transfer::checkPassed24hour(tm date){
    date.tm_mday += 1;

    std::mktime(&date);

    if(!isBeforeNow(date))
        return true;
    return false;

}

void Transfer::checkAndUpdateLastTransactionDate () {

    BankAccount bankAccount = findOriginCardBankAccount(ui->originCardNumberComboBax->currentText());

    if(!checkPassed24hour(bankAccount.getLastTransactionDate())){
        time_t now = time(0);
        bankAccount.setLastTransactionDate(*localtime(&now));
        updateUsersBankAccount(bankAccount);
    }
}


/// Get random Number
int Transfer::getRandomNumber () {
    std::time_t now = std::time(nullptr);
    tm time = *std::localtime(&now);
    int hour = time.tm_hour, min = time.tm_min, month = time.tm_mon, day = time.tm_mday;
    int randomNum = hour + min + month + day;

    return randomNum;
}




