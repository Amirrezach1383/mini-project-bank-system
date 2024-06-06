#include "newaccountform.h"
#include "ui_newaccountform.h"
#include "userpanel.h"
#include <ctime>
#include <time.h>


NewAccountForm::NewAccountForm(Users users, QWidget *parent)  : QWidget(parent), user(users), ui(new Ui::NewAccountForm) {

    ui->setupUi(this);
    // ui->cardInformationGroupBox->hide();
    // ui->accountInformationGroupBox->hide();

    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));

    /// Connect Push Button
    connect(ui->makeAccountPushButton, SIGNAL(clicked()), this, SLOT(makeAccountPushButton()));

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

}

///========= Set Users Account And Card Information =========
void NewAccountForm::setUsersCardInformation(){

}
void NewAccountForm::setUsersAccountInformation(){

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
QString NewAccountForm::makeCardExpirationDate() {
    QString expirationDate;
    std::time_t now = std::time(nullptr);
    tm time = *std::localtime(&now);

    int month = time.tm_mon;
    int year = time.tm_year + 1903;

    expirationDate = QString::number(year) + "/" + QString::number(month);
    return expirationDate;
}
QString NewAccountForm::makeShabaNumber() {
    QString shabaNumber;
    int accountType = findAccountType();

    shabaNumber = "IR35101" + QString::number(accountType) + user.getBankAccount(user.getNumOfUserAccount() - 1).getAccountNumber();

    return shabaNumber;
}
QString NewAccountForm::makeCvv2(){
    QString cvv2;
    QString nationalCode = user.getNationalCode();
    int randomNum = getRandomNumber();

    std::srand(time(0));
    randomNum += (rand() % 800 + 100);

    cvv2 = QString::number(randomNum);

    return cvv2;
}


///========= Check and Set Errors in Form ==========
bool NewAccountForm::checkAllError() {


}


bool NewAccountForm::checkInitialBalanceLineEdit () {

    if(ui->intialBalanceLineEdit->text() == "") {
        ui->initialBalanceErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkInitialBalanceLineEdit()) {
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
}


bool NewAccountForm::checkFixedSecondPassword() {

}


int NewAccountForm::findAccountType () {

    if(ui->comboBox->currentText() == "Saving Account")
        return 0;
    if(ui->comboBox->currentText() == "Checking Account")
        return 1;
    if(ui->comboBox->currentText() == "Loan Account")
        return 2;

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
    ui->firstNameLabel->setText(user.getFirstName());
    ui->lastNameLabel->setText(user.getLastName());
    ui->nationalCodeLabel->setText(user.getNationalCode());
}
