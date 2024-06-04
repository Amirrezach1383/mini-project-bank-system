#include "loginsigninform.h"
#include "ui_loginsigninform.h"
#include "users.h"



LoginSigninForm::LoginSigninForm(QWidget *parent) : QWidget(parent), ui(new Ui::LoginSigninForm) {

    ui->setupUi(this);

    hideAllError();



    connect(ui->signinPushButton, SIGNAL(clicked()), this, SLOT(checkTheFieldsValue()));
}

/// Check Functions
bool LoginSigninForm::checkCorrectAgeValue() {
    QString age = ui->ageLineEdit->text();

    if(age == "") {
        ui->ageInvalidError->hide();
        return true;
    }
    int i = 0;
    int ageInt = ui->ageLineEdit->text().toInt();

    while(i < age.length()) {
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

    if(nationalCode == "") {
        ui->nationalCodeInvalidError->hide();
        return true;
    }

    int i = 0;

    while(i < nationalCode.length()) {
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
bool LoginSigninForm::checkCorrectFirstName() {
    QString firstName = ui->firstNameLineEdit->text();
    if(firstName == "") {
        ui->firstNameInvalidError->hide();
        return true;
    }

    int i = 0;

    while(i < firstName.length()) {
        if(('A' <= firstName[i] && firstName[i] <= 'Z') || ('a' <= firstName[i] && 'z' >= firstName[i]))
            i++;
        else {
            ui->firstNameError->hide();
            ui->firstNameInvalidError->show();
            return false;
        }
    }
    ui->firstNameInvalidError->hide();
    return true;
}
bool LoginSigninForm::checkCorrectLastName() {
    QString lastName = ui->lastNameLineEdit->text();
    if(lastName == "") {
        ui->lastNameInvalidError->hide();
        return true;
    }

    int i = 0;

    while(i < lastName.length()) {
        if(('A' <= lastName[i] && lastName[i] <= 'Z') || ('a' <= lastName[i] && 'z' >= lastName[i]))
            i++;
        else {
            ui->lastNameError->hide();
            ui->lastNameInvalidError->show();
            return false;
        }
    }
    ui->lastNameInvalidError->hide();
    return true;
}
bool LoginSigninForm::checkCorrectUserName() {
    QString username = ui->usernameLineEditS->text();

    if(username == "") {
        ui->usernameInvalidError->hide();
        return true;
    }

    int i = 0, a = 0;

    while(i < username.length()) {
        if((username[i] <= 'Z' && username[i] >= 'A') || (username[i] <= 'z' && username[i] >= 'a') ||
            (username[i] <= '9' && username[i] >= '0')) {

            if((username[i] <= 'Z' && username[i] >= 'A') || (username[i] <= 'z' && username[i] >= 'a'))
                a++;
            i++;
        }
        else {
            ui->usernameFillError->hide();
            ui->usernameInvalidError->show();
            return false;
        }

    }

    if(a != 0) {
        ui->usernameInvalidError->hide();
        return true;
    } else {
        ui->usernameFillError->hide();
        ui->usernameInvalidError->show();
        return false;
    }
}
bool LoginSigninForm::checkCorrectPassword() {
    QString password = ui->passwordLineEditS->text();

    if(password == "") {
        ui->passwordInvalidError->hide();
        return true;
    }

    int i = 0, a = 0, a1 = 0;

    while(i < password.length()) {
        if((password[i] <= 'Z' && password[i] >= 'A') || (password[i] <= 'z' && password[i] >= 'a') || (password[i] <= '9' && password[i] >= '0') || (password[i] == '_')) {
            if((password[i] <= 'Z' && password[i] >= 'A') || (password[i] <= 'z' && password[i] >= 'a'))
                a++;
            else if(password[i] <= '9' && password[i] >= '0')
                a1++;
            i++;
        }
        else {
            ui->passwordFillError->hide();
            ui->passwordInvalidError->show();
            return false;
        }
    }


    if(a != 0 && a1 != 0) {
        ui->passwordInvalidError->hide();
        return true;

    }else {
        ui->passwordFillError->hide();
        ui->passwordInvalidError->show();
        return false;
    }
}

void LoginSigninForm::hideAllError(){
    ui->firstNameError->hide();
    ui->firstNameInvalidError->hide();

    ui->lastNameError->hide();
    ui->lastNameInvalidError->hide();

    ui->nationalCodeError->hide();
    ui->nationalCodeInvalidError->hide();

    ui->ageError->hide();
    ui->ageInvalidError->hide();

    ui->usernameInvalidError->hide();
    ui->usernameFillError->hide();

    ui->passwordFillError->hide();
    ui->passwordInvalidError->hide();
}



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

    if(checkCorrectAgeValue() && checkCorrectNationalCodeValue() && checkCorrectPassword() && checkCorrectFirstName()
        && checkCorrectLastName() && checkCorrectUserName())

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
