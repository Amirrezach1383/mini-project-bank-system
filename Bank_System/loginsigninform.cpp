#include "loginsigninform.h"
#include "ui_loginsigninform.h"
#include "users.h"



LoginSigninForm::LoginSigninForm(QWidget *parent) : QWidget(parent), ui(new Ui::LoginSigninForm) {

    ui->setupUi(this);

    ui->ageError->hide();
    ui->usernameFillError->hide();
    ui->nationalCodeError->hide();
    ui->firstNameError->hide();
    ui->lastNameError->hide();
    ui->passwordFillError->hide();
    ui->ageInvalidError->hide();
    ui->nationalCodeInvalidError->hide();

    connect(ui->signinPushButton, SIGNAL(clicked()), this, SLOT(checkTheFieldsValue()));
}

/// Check Functions
bool LoginSigninForm::checkCorrectAgeValue() {
    QString age = ui->ageLineEdit->text();

    if(age == "")
        return true;

    int i = 0;
    int ageInt = ui->ageLineEdit->text().toInt();

    while(i != age.length() - 1) {
        if('0' <= age[i] && age[i] <= '9')
            i++;
        else {
            ui->ageError->hide();
            ui->ageInvalidError->show();
            return false;
        }
    }
    if(ageInt >= 18) {
        ui->ageInvalidError->hide();
        return true;
    }
    else {
        ui->ageError->hide();
        ui->ageInvalidError->show();
        return false;
    }
}
bool LoginSigninForm::checkCorrectNationalCodeValue () {
    QString nationalCode = ui->nationalCodeLineEdit->text();

    if(nationalCode == "")
        return true;

    int i = 0;

    while(i != nationalCode.length() - 1) {
        if('0' <= nationalCode[i] && nationalCode[i] <= '9')
            i++;
        else {
            ui->nationalCodeError->hide();
            ui->nationalCodeInvalidError->show();
            return false;
        }
    }
    if(nationalCode.length() >= 10) {
        ui->nationalCodeInvalidError->hide();
        return true;
    }
    else {
        ui->nationalCodeError->hide();
        ui->nationalCodeInvalidError->show();
        return false;
    }
}
bool LoginSigninForm::checkCorrectFirstName(){}
bool LoginSigninForm::checkCorrectLastName(){}
bool LoginSigninForm::checkCorrectUserName(){}
bool LoginSigninForm::checkCorrectPassword(){}



void LoginSigninForm::checkTheFieldsValue () {
    bool checkEmpty = true, checkCorrectValue = true;

    if(ui->firstNameLineEdit->text() == "") {
        ui->firstNameError->show();
        checkEmpty = false;
    } else if (!ui->firstNameError->isHidden())
        ui->firstNameError->hide();

    if(ui->lastNameLineEdit->text() == "") {
        ui->lastNameError->show();
        checkEmpty = false;
    } else if (!ui->lastNameError->isHidden())
        ui->lastNameError->hide();

    if(ui->ageLineEdit->text() == "") {
        ui->ageInvalidError->hide();
        ui->ageError->show();
        checkEmpty = false;
    } else
        ui->ageError->hide();

    if(ui->nationalCodeLineEdit->text() == "") {
        ui->nationalCodeInvalidError->hide();
        ui->nationalCodeError->show();
        checkEmpty = false;
    } else
        ui->nationalCodeError->hide();

    if(ui->usernameLineEditS->text() == "") {
        ui->usernameFillError->show();
        checkEmpty = false;
    } else if (!ui->usernameFillError->isHidden())
        ui->usernameFillError->hide();

    if(ui->passwordLineEditS->text() == "") {
        ui->passwordFillError->show();
        checkEmpty = false;
    } else if (!ui->passwordFillError->isHidden())
        ui->passwordFillError->hide();

    if(checkCorrectAgeValue() && checkCorrectNationalCodeValue())
        checkCorrectValue = true;
    else
        checkCorrectValue = false;

    if(checkEmpty && checkCorrectValue) {
        pushSignUpInputs();
    }
}

void LoginSigninForm::pushSignUpInputs() {

    Users user;
    user.setName(ui->firstNameLineEdit->text());
    user.setLastName(ui->lastNameLineEdit->text());
    user.setNationnalCode(ui->nationalCodeLineEdit->text());
    user.setAge(ui->ageLineEdit->text());
    user.setUserName(ui->usernameLineEditS->text());
    user.setPassword(ui->passwordLineEditS->text());

    user.addUserToList();
}

LoginSigninForm::~LoginSigninForm() {
    delete ui;
}
