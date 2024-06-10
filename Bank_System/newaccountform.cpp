#include "newaccountform.h"
#include "ui_newaccountform.h"
#include "userpanel.h"
#include <ctime>
#include <time.h>
#include <bankaccount.h>
#include <cards.h>

NewAccountForm::NewAccountForm(Users users, QWidget *parent)  : QWidget(parent), user(users), ui(new Ui::NewAccountForm) {

    ui->setupUi(this);
    ui->cardInformationGroupBox->hide();
    ui->accountInformationGroupBox->hide();

    setUserInformation();
    checkBoxChangeLineEditEnableOrDisable();

    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));

    /// Connect Push Button
    connect(ui->makeAccountPushButton, SIGNAL(clicked()), this, SLOT(makeAccountPushButton()));

    /// Connect CheckBox
    connect(ui->secondFixedPasswordCheckBox, SIGNAL(checkStateChanged(Qt::CheckState)), this, SLOT(checkBoxChangeLineEditEnableOrDisable()));
}

NewAccountForm::~NewAccountForm()
{
    delete ui;
}

///============ Private Slot Functions ============
void NewAccountForm::openUserPanelForm() {
    UserPanel *userPanel = new class UserPanel(user);
    userPanel->show();
    this->close();
}
void NewAccountForm::makeAccountPushButton() {

    if(checkAllError()) {
        user.setNumOfUserAccount(user.getNumOfUserAccount() + 1);
        setUsersAccountInformation();
        setUsersCardInformation();
        ui->makeAccountPushButton->setEnabled(false);
        addNewDataToUserLists();
    }
}

void NewAccountForm::checkBoxChangeLineEditEnableOrDisable (){
    if(ui->secondFixedPasswordCheckBox->isChecked())
        ui->secondFixedPasswordLineEdit->setEnabled(true);
    else
        ui->secondFixedPasswordLineEdit->setEnabled(false);

    ui->secondFixedPasswordLineEdit->clear();
    ui->secondFixedPasswordErrorLabel->clear();
}

///========= Set Users Account And Card Information =========
Cards NewAccountForm::setUsersCardInformation(){
    Cards cardTmp;

    cardTmp.setCardNumber(makeCardNum());
    cardTmp.setCardPassword(ui->cardPsswordLineEdit->text());
    cardTmp.setExpirationDate(makeCardExpirationDate());
    cardTmp.setCvv2Number(makeCvv2());

    if(ui->secondFixedPasswordCheckBox->isChecked())
        cardTmp.setFixedSecondPassword(ui->secondFixedPasswordLineEdit->text());

    return cardTmp;
}
void NewAccountForm::setUsersAccountInformation(){
    BankAccount bankAccountTmp;

    bankAccountTmp.setAccountNumber(makeAccountNum());
    bankAccountTmp.setShabaNumber(makeShabaNumber(bankAccountTmp.getAccountNumber()));
    bankAccountTmp.setAccountType(ui->accountTypeComboBox->currentText());
    bankAccountTmp.setBalance(ui->intialBalanceLineEdit->text().toLongLong());
    bankAccountTmp.setCard(setUsersCardInformation());

    user.addBankAccountToList(bankAccountTmp);

    setAccountInformationInFormsLabels();
    setCardsInformationInFormsLabels();

}

void NewAccountForm::addNewDataToUserLists() {
    QString username = user.getUsername();

    Node<Users> *tmp = user.usersList.getHeadNode();
    while (tmp) {
        if (tmp->getData().getUsername() == username) {
            tmp->setData(user);
        }
        tmp = tmp->getNextNode();
    }

}

void NewAccountForm::setCardsInformationInFormsLabels(){

    Node<BankAccount> *tmp = user.userBankAccountsList.getTailNode();
    Cards card = tmp->getData().getCard();
    QString expirationDate;

    tm time = card.getExpirationDate();

    expirationDate = QString::number(time.tm_year) + "/" + QString::number(time.tm_mon);


    ui->cardsNumberLabelEdit->setText(card.getCardNumber());
    ui->exparationDateLabelEdit->setText(expirationDate);
    ui->cvv2LabelEdit->setText(card.getCvv2Number());

    ui->cardInformationGroupBox->show();
}
void NewAccountForm::setAccountInformationInFormsLabels(){

    Node<BankAccount> *tmp = user.userBankAccountsList.getTailNode();

    ui->accountNumberLabelEdit->setText(tmp->getData().getAccountNumber());
    ui->shabaNumberLabelEdit->setText(tmp->getData().getShabaNumber());

    ui->accountInformationGroupBox->show();
}

/// Make Account and Card Information
QString NewAccountForm::makeAccountNum() {
    QString accountNum;
    QString nationalCode = user.getNationalCode();
    int randomNum = getRandomNumber();

    nationalCode.erase(&nationalCode[0], &nationalCode[3]);
    std::random_shuffle(nationalCode.begin(), nationalCode.end());

    std::srand(time(0));
    randomNum += (std::rand() % 9555 + 1000);

    accountNum = "10" + QString::number(randomNum) + nationalCode;

    return accountNum;
}
QString NewAccountForm::makeCardNum() {
    QString cardNum;
    QString nationalCode = user.getNationalCode();
    int randomNum = getRandomNumber();

    nationalCode.erase(&nationalCode[0], &nationalCode[2]);
    std::random_shuffle(nationalCode.begin(), nationalCode.end());

    std::srand(time(0));
    randomNum += (std::rand() % 9000 + 1000);

    cardNum = "3138" + nationalCode + QString::number(randomNum);

    return cardNum;
}

tm NewAccountForm::makeCardExpirationDate() {
    tm expirationDate;
    std::time_t now = std::time(nullptr);
    tm time = *std::localtime(&now);

    time.tm_year += 3;

    expirationDate = time;
    return expirationDate;
}
QString NewAccountForm::makeShabaNumber(QString accountNum) {
    QString shabaNumber;
    int accountType = findAccountType();

    shabaNumber = "IR35101" + QString::number(accountType) + "00000" + accountNum;

    return shabaNumber;
}
QString NewAccountForm::makeCvv2(){
    QString cvv2;
    int randomNum = getRandomNumber();

    std::srand(time(0));
    randomNum += (rand() % 800 + 100);

    cvv2 = QString::number(randomNum);

    return cvv2;
}


///========= Check and Set Errors in Form ==========
bool NewAccountForm::checkAllError() {

    bool checkErrors = true;
    if(user.getNumOfUserAccount() == 5) {
        ui->accountLimitError->setText("You Have Five Existing Accounts!");
        checkErrors = false;
    }
    if(!checkPasswordLineEdit())
        checkErrors = false;

    if(!checkInitialBalanceLineEdit())
        checkErrors = false;

    if(ui->secondFixedPasswordCheckBox->isChecked()){
        if(!checkFixedSecondPassword())
            checkErrors = false;
    }

    if(!checkComboBox())
        checkErrors = false;

    return checkErrors;
}

bool NewAccountForm::checkInitialBalanceLineEdit () {

    if(ui->intialBalanceLineEdit->text() == "") {
        ui->initialBalanceErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkInitialBalanceValid()) {
        ui->initialBalanceErrorLabel->setText("Invalid Data");
        return false;
    }
    if(ui->intialBalanceLineEdit->text().toInt() <= 50000) {
        ui->initialBalanceErrorLabel->setText("The Deposit Amount Must Be More Than 50 000");
        return false;
    }
    ui->initialBalanceErrorLabel->clear();
    return true;
}
bool NewAccountForm::checkInitialBalanceValid (){
    int i = 0;
    QString initialBalance = ui->intialBalanceLineEdit->text();
    while (i < ui->intialBalanceLineEdit->text().length()) {
        if(!('0' <= initialBalance[i] && initialBalance[i] <= '9')) {
            return false;
        }
        i++;
    }
    return true;
}

bool NewAccountForm::checkPasswordLineEdit() {

    if(ui->cardPsswordLineEdit->text() == "") {
        ui->cardPasswordErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkPasswordValid()) {
        ui->cardPasswordErrorLabel->setText("Invalid Data");
        return false;
    }
    if(ui->cardPsswordLineEdit->text().length() > 4 || ui->cardPsswordLineEdit->text().length() < 4) {
        ui->cardPasswordErrorLabel->setText("Please Enter Only Four Digit!");
        return false;
    }
    ui->cardPasswordErrorLabel->clear();
    return true;

}
bool NewAccountForm::checkPasswordValid () {
    int i = 0;
    QString password = ui->cardPsswordLineEdit->text();

    while(i < password.length()) {
        if(!('0' <= password[i] && '9' >= password[i])) {
            return false;
        }
        i++;
    }
    return true;
}

bool NewAccountForm::checkFixedSecondPassword() {

    if(ui->secondFixedPasswordLineEdit->text() == "") {
        ui->secondFixedPasswordErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkFixedSecondPasswordValid()) {
        ui->secondFixedPasswordErrorLabel->setText("Invalid Data");
        return false;
    }
    if(ui->secondFixedPasswordLineEdit->text().length() > 7 || ui->secondFixedPasswordLineEdit->text().length() < 7) {
        ui->secondFixedPasswordErrorLabel->setText("Please Enter Only Seven Digit!");
        return false;
    }
    ui->secondFixedPasswordErrorLabel->clear();
    return true;


}
bool NewAccountForm::checkFixedSecondPasswordValid () {
    int i = 0;
    QString password = ui->secondFixedPasswordLineEdit->text();

    while(i < password.length()) {
        if(!('0' <= password[i] && '9' >= password[i])) {
            return false;
        }
        i++;
    }
    return true;
}

bool NewAccountForm::checkComboBox() {

    if(ui->accountTypeComboBox->currentText() == "") {
        ui->accountTypeComboBoxErrorLabel->setText("Please Choose One Type");
        return false;
    }
    ui->accountTypeComboBoxErrorLabel->clear();
    return true;

}

/// ============ Other Functions ==============
int NewAccountForm::findAccountType () {

    if(ui->accountTypeComboBox->currentText() == "Saving Account")
        return 0;
    if(ui->accountTypeComboBox->currentText() == "Checking Account")
        return 1;
    if(ui->accountTypeComboBox->currentText() == "Loan Account")
        return 2;

    return -1;
}
int NewAccountForm::getRandomNumber () {
    std::time_t now = std::time(nullptr);
    tm time = *std::localtime(&now);
    int hour = time.tm_hour, min = time.tm_min, month = time.tm_mon, day = time.tm_mday;
    int randomNum = hour + min + month + day;

    return randomNum;
}

/// ============ Set User Information ============
void NewAccountForm::setUserInformation() {
    ui->firstNameLabel->setText(user.getFirstName() + " " + user.getLastName());
    ui->nationalCodeLabel->setText(user.getNationalCode());
}
