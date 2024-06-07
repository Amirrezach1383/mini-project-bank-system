#include "changepasses.h"
#include "ui_changepasses.h"
#include "users.h"
#include "userpanel.h"

ChangePasses::ChangePasses(Users users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::ChangePasses) {

    ui->setupUi(this);

    cardPasswordCheckBox();
    fixedSecondCheckBox();

    setAccountInformationInComboBox ();

    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));

    /// Connect Functions to changePushButtons
    connect(ui->changePasswordPushButton, SIGNAL(clicked()), this, SLOT(changeCardPasswordPushButton()));
    connect(ui->changeFixedSecondPasswordPushButton, SIGNAL(clicked()), this, SLOT(changeFixedSecondPasswordPushButton()));

    /// Connect Functions to checkBoxes
    connect(ui->changeCardPasswordCheckBox, SIGNAL(checkStateChanged(Qt::CheckState)), this, SLOT(cardPasswordCheckBox()));
    connect(ui->changeFixedSecondPasswordCheckBox, SIGNAL(checkStateChanged(Qt::CheckState)), this, SLOT(fixedSecondCheckBox()));

}
ChangePasses::~ChangePasses()
{
    delete ui;
}

///========== Private Slots ============

void ChangePasses::openUserPanelForm() {
    UserPanel *userPanel = new class UserPanel(user);
    userPanel->show();
    this->close();
}

void ChangePasses::changeCardPasswordPushButton () {
    if(checkChangeCardPasswordAllError()) {
        setCardPasswordInformation();
        ui->newCardPasswordLineEdit->clear();
        ui->previousCardPasswordLineEdit->clear();
    }
}
void ChangePasses::changeFixedSecondPasswordPushButton () {
    if(checkChangeFixedSecondPasswordAllError()) {
        setFixedSecondPasswordInformation();
        ui->newFixedSecondPasswordLineEdit->clear();
        ui->previousFixedSecondPasswordLineEdit->clear();
    }
}

void ChangePasses::cardPasswordCheckBox(){

    if(ui->changeCardPasswordCheckBox->isChecked()) {
        ui->newCardPasswordLineEdit->setEnabled(true);
        ui->previousCardPasswordLineEdit->setEnabled(true);
        ui->changePasswordPushButton->setEnabled(true);
    } else {
        ui->newCardPasswordLineEdit->setEnabled(false);
        ui->previousCardPasswordLineEdit->setEnabled(false);
        ui->changePasswordPushButton->setEnabled(false);

        ui->newCardPasswordLineEdit->clear();
        ui->previousCardPasswordLineEdit->clear();
    }
}
void ChangePasses::fixedSecondCheckBox(){

    if(ui->changeFixedSecondPasswordCheckBox->isChecked()) {
        ui->newFixedSecondPasswordLineEdit->setEnabled(true);
        ui->previousFixedSecondPasswordLineEdit->setEnabled(true);
        ui->changeFixedSecondPasswordPushButton->setEnabled(false);
    } else {
        ui->newFixedSecondPasswordLineEdit->setEnabled(false);
        ui->previousFixedSecondPasswordLineEdit->setEnabled(false);
        ui->changeFixedSecondPasswordPushButton->setEnabled(false);

        ui->newFixedSecondPasswordLineEdit->clear();
        ui->previousFixedSecondPasswordLineEdit->clear();
    }
}

/// Set changes in User Information
void ChangePasses::setCardPasswordInformation(){
    int i = searchBankAccount ();
    QString password = ui->newCardPasswordLineEdit->text();

    BankAccount bankAccountTmp = user.getBankAccount(i);
    Cards cardTmp = bankAccountTmp.getCard();

    cardTmp.setCardPassword(password);
    bankAccountTmp.setCard(cardTmp);

    user.setBankAccount(bankAccountTmp, i);
}
void ChangePasses::setFixedSecondPasswordInformation(){
    int i = searchBankAccount ();
    QString password = ui->newFixedSecondPasswordLineEdit->text();

    BankAccount bankAccountTmp = user.getBankAccount(i);
    Cards cardTmp = user.getBankAccount(i).getCard();

    cardTmp.setFixedSecondPassword(password);
    bankAccountTmp.setCard(cardTmp);

    user.setBankAccount(bankAccountTmp, i);
}

/// Search BankAccount Function
int ChangePasses::searchBankAccount() {
    QString accountNum = ui->accountComboBox->currentText();
    int i = 0;

    while(i < user.getNumOfUserAccount()) {
        if(user.getBankAccount(i).getAccountNumber() == accountNum)
            return i;
        i++;
    }
    return -1;
}

void ChangePasses::setAccountInformationInComboBox () {
    int i = 0;

    while(i < user.getNumOfUserAccount()) {
        ui->accountComboBox->addItem(user.getBankAccount(i).getAccountNumber());
        i++;
    }
}

/// Check And Set Passwords Functions
bool ChangePasses::checkChangeFixedSecondPasswordAllError(){
    bool checkAllErrors = true;

    if(!checkNewFixedSecondPasswordLineEditError())
        checkAllErrors = false;

    if(!checkPreviousFixedSecondPasswordLineEditError())
        checkAllErrors = false;

    if(!checkComboBoxError())
        checkAllErrors = false;

    return checkAllErrors;
}
bool ChangePasses::checkChangeCardPasswordAllError(){
    bool checkAllErrors = true;

    if(!checkNewCardPasswordLineEditError())
        checkAllErrors = false;

    if(!checkPreviousCardPasswordLineEditError())
        checkAllErrors = false;

    if(!checkComboBoxError())
        checkAllErrors = false;

    return checkAllErrors;
}

bool ChangePasses::checkNewCardPasswordLineEditError(){

    if(ui->newCardPasswordLineEdit->text() == ""){
        ui->newCardPasswordErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkNewCardPasswordValid()){
        ui->newCardPasswordErrorLabel->setText("Invalid Data");
        return false;
    }
    if(ui->newCardPasswordLineEdit->text().length() < 4 || ui->newCardPasswordLineEdit->text().length() > 4) {
        ui->newCardPasswordErrorLabel->setText("Please Enter Only Four Digit");
        return false;
    }
    ui->newCardPasswordErrorLabel->clear();
    return true;
}
bool ChangePasses::checkNewCardPasswordValid(){

    int i = 0;
    QString password = ui->newCardPasswordLineEdit->text();

    while(i < password.length()) {
        if(!('0' <= password[i] && '9' >= password[i])) {
            return false;
        }
        i++;
    }
    return true;

}

bool ChangePasses::checkNewFixedSecondPasswordLineEditError(){

    if(ui->newFixedSecondPasswordLineEdit->text() == ""){
        ui->newFixedSecondPasswordErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkNewFixedSecondPasswordValid()){
        ui->newFixedSecondPasswordErrorLabel->setText("Invalid Data");
        return false;
    }
    if(ui->newFixedSecondPasswordLineEdit->text().length() < 7 || ui->newFixedSecondPasswordLineEdit->text().length() > 7) {
        ui->newFixedSecondPasswordErrorLabel->setText("Please Enter Only Seven Digit");
        return false;
    }
    ui->newFixedSecondPasswordErrorLabel->clear();
    return true;
}
bool ChangePasses::checkNewFixedSecondPasswordValid(){

    int i = 0;
    QString password = ui->newFixedSecondPasswordLineEdit->text();

    while(i < password.length()) {
        if(!('0' <= password[i] && '9' >= password[i])) {
            return false;
        }
        i++;
    }
    return true;
}

bool ChangePasses::checkPreviousCardPasswordLineEditError(){

    if(ui->previousCardPasswordLineEdit->text() == ""){
        ui->previousCardPasswordErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkpreviousCardPasswordValid()){
        ui->previousCardPasswordErrorLabel->setText("Invalid Data");
        return false;
    }
    if(ui->previousCardPasswordLineEdit->text().length() < 4 || ui->previousCardPasswordLineEdit->text().length() > 4) {
        ui->previousCardPasswordErrorLabel->setText("Please Enter Only Four Digit");
        return false;
    }
    if(!checkpreviousCardPasswordExists()) {
        ui->previousCardPasswordErrorLabel->setText("Incorrect Password");
        return false;
    }
    ui->previousCardPasswordErrorLabel->clear();
    return true;
}
bool ChangePasses::checkpreviousCardPasswordValid(){
    int i = 0;
    QString password = ui->previousCardPasswordLineEdit->text();

    while(i < password.length()) {
        if(!('0' <= password[i] && '9' >= password[i])) {
            return false;
        }
        i++;
    }
    return true;

}
bool ChangePasses::checkpreviousCardPasswordExists(){
    QString password = user.getBankAccount(user.getNumOfUserAccount() - 1).getCard().getCardPassword();

    if(ui->previousCardPasswordLineEdit->text() == password)
        return true;
    return false;
}

bool ChangePasses::checkPreviousFixedSecondPasswordLineEditError(){
    if(ui->previousFixedSecondPasswordLineEdit->text() == ""){
        ui->previousFixedSecondPasswordErrorLabel->setText("Please Fill Out This Field");
        return false;
    }
    if(!checkpreviousCardPasswordValid()){
        ui->previousFixedSecondPasswordErrorLabel->setText("Invalid Data");
        return false;
    }
    if(ui->previousFixedSecondPasswordLineEdit->text().length() < 7 || ui->previousFixedSecondPasswordLineEdit->text().length() > 7) {
        ui->previousFixedSecondPasswordErrorLabel->setText("Please Enter Only Seven Digit");
        return false;
    }
    if(!checkpreviousFixedSecondPasswordExists()){
        ui->previousFixedSecondPasswordErrorLabel->setText("Incorrect Password");
        return false;
    }

    ui->previousFixedSecondPasswordErrorLabel->clear();
    return true;
}
bool ChangePasses::checkpreviousFixedSecondPasswordValid(){
    int i = 0;
    QString password = ui->previousFixedSecondPasswordLineEdit->text();

    while(i < password.length()) {
        if(!('0' <= password[i] && '9' >= password[i])) {
            return false;
        }
        i++;
    }
    return true;
}
bool ChangePasses::checkpreviousFixedSecondPasswordExists(){
    QString password = user.getBankAccount(user.getNumOfUserAccount() - 1).getCard().getFixedSecondPassword();

    if(password == ui->previousFixedSecondPasswordLineEdit->text())
        return true;
    return false;

}

bool ChangePasses::checkComboBoxError(){
    if(ui->accountComboBox->currentText() == "") {
        ui->accountComboBoxErrorLabel->setText("Please Choose One Account");
        return false;
    }
    ui->accountComboBoxErrorLabel->clear();
    return true;
}

