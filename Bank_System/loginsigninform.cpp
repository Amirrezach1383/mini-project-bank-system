#include "loginsigninform.h"
#include "ui_loginsigninform.h"
#include "users.h"
#include "userpanel.h"
#include "QMessageBox"

LoginSigninForm::LoginSigninForm(Users users,QWidget *parent) : QWidget(parent), user(users), ui(new Ui::LoginSigninForm) {
    ui->setupUi(this);

    /// SignUp =========
    hideAllError();
    connect(ui->signinPushButton, SIGNAL(clicked()), this, SLOT(checkTheFieldsValue()));
    /// =======

    /// Login ==========
    connect(ui->loginPushButton, SIGNAL(clicked()), this, SLOT(checkLoginFieldsValue()));
    /// =======
}
LoginSigninForm::~LoginSigninForm() {
    delete ui;
}

void LoginSigninForm::hideAllError(){

    /// SignUP Errors
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
    ui->usernameExistsError->hide();

    ui->passwordFillError->hide();
    ui->passwordInvalidError->hide();

    ui->signUpUserExistError->hide();

    /// Login Errors
    ui->loginPasswordEmptyError->hide();
    ui->loginPasswordInvalidError->hide();
    ui->loginPasswordIncorrectError->hide();

    ui->loginUsernameIncorrectError->hide();
    ui->loginUsernameEmptyError->hide();
    ui->loginUsernameInvalidError->hide();
}

/// =================== SignUp ====================

void LoginSigninForm::cleanFields() {
    ui->usernameLineEditS->clear();
    ui->passwordLineEditS->clear();
    ui->firstNameLineEdit->clear();
    ui->lastNameLineEdit->clear();
    ui->nationalCodeLineEdit->clear();
    ui->ageLineEdit->clear();
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
            ui->usernameExistsError->hide();
            ui->usernameInvalidError->show();
            return false;
        }

    }

    if(a != 0) {
        ui->usernameInvalidError->hide();
        return true;
    } else {
        ui->usernameExistsError->hide();
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
bool LoginSigninForm::checkUserExist() {
    QString firstName, lastName, nationalCode;
    firstName = ui->firstNameLineEdit->text();
    lastName = ui->lastNameLineEdit->text();
    nationalCode = ui->nationalCodeLineEdit->text();

    Node<Users> *tmp = user.usersList.getHeadNode();
    while (tmp) {
        if (tmp->getData().getFirstName() == firstName && tmp->getData().getLastName() == lastName && tmp->getData().getNationalCode() == nationalCode) {

            ui->signUpUserExistError->show();
            return false;
        }

        tmp = tmp->getNextNode();
    }
    return true;
}
bool LoginSigninForm::checkSignUpUsernameExist() {
    QString username = ui->usernameLineEditS->text();

    if(username == "") {
        ui->usernameExistsError->hide();
        return true;
    }

    Node<Users> *tmp = user.usersList.getHeadNode();
    while (tmp) {
        if (tmp->getData().getUsername() == username) {
            ui->usernameFillError->hide();
            ui->usernameInvalidError->hide();
            ui->usernameExistsError->show();
            return false;
        }
        tmp = tmp->getNextNode();
    }
    ui->usernameExistsError->hide();
    return true;
}

void LoginSigninForm::checkTheFieldsValue () {
    bool checkEmpty = true, checkCorrectValue = true, userExist = false, usernameExist = false;

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

    if(!checkCorrectAgeValue())
        checkCorrectValue = false;

    if(!checkCorrectNationalCodeValue())
        checkCorrectValue = false;

    if(!checkCorrectPassword())
        checkCorrectValue = false;

    if(!checkCorrectFirstName())
        checkCorrectValue = false;

    if(!checkCorrectLastName())
        checkCorrectValue = false;

    if(!checkCorrectUserName())
        checkCorrectValue = false;

    if(!checkUserExist()) {
        userExist = true;
    }
    if(!checkSignUpUsernameExist()) {
        usernameExist = true;
    }

    if(checkEmpty && checkCorrectValue && !usernameExist && !userExist) {
        pushSignUpInputs();
    }
}

///Push Inputs
void LoginSigninForm::pushSignUpInputs() {

    user.setFirstName(ui->firstNameLineEdit->text());
    user.setLastName(ui->lastNameLineEdit->text());
    user.setNationnalCode(ui->nationalCodeLineEdit->text());
    user.setAge(ui->ageLineEdit->text());
    user.setUsername(ui->usernameLineEditS->text());
    user.setPassword(ui->passwordLineEditS->text());

    user.addUserToList();

    cleanFields();
}

/// ========================================================


/// ===================== Login Part ========================

bool LoginSigninForm::checkValidLoginUsername() {
    QString username = ui->usernameLineEditL->text();

    if(username == "") {
        ui->loginUsernameInvalidError->hide();
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
            ui->loginUsernameEmptyError->hide();
            ui->loginUsernameIncorrectError->hide();
            ui->loginUsernameInvalidError->show();
            return false;
        }

    }

    if(a != 0) {
        ui->loginUsernameInvalidError->hide();
        return true;
    } else {
        ui->loginUsernameEmptyError->hide();
        ui->loginUsernameIncorrectError->hide();
        ui->loginUsernameInvalidError->show();
        return false;
    }
}
bool LoginSigninForm::checkValidLoginPassword() {
    QString password = ui->passwordLineEditL->text();

    if(password == "") {
        ui->loginPasswordInvalidError->hide();
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
            ui->loginPasswordEmptyError->hide();
            ui->loginPasswordIncorrectError->hide();
            ui->loginPasswordInvalidError->show();
            return false;
        }
    }


    if(a != 0 && a1 != 0) {
        ui->loginPasswordInvalidError->hide();
        return true;

    }else {
        ui->loginPasswordEmptyError->hide();
        ui->loginPasswordIncorrectError->hide();
        ui->loginPasswordInvalidError->show();
        return false;
    }
}
bool LoginSigninForm::checkCorrectLoginUsername(){
    QString username = ui->usernameLineEditL->text();

    if(username == "") {
        ui->loginUsernameIncorrectError->hide();
        return true;
    }

    Node<Users> *tmp = user.usersList.getHeadNode();
    while (tmp) {
        if (tmp->getData().getUsername() == ui->usernameLineEditL->text()){
            ui->loginUsernameIncorrectError->hide();
            return true;
        }
        tmp = tmp->getNextNode();
    }

    ui->loginUsernameEmptyError->hide();
    ui->loginUsernameInvalidError->hide();
    ui->loginUsernameIncorrectError->show();
    return false;

}
bool LoginSigninForm::checkCorrectLoginPassword(){

    QString password = ui->passwordLineEditL->text();

    if(password == "") {
        ui->loginPasswordIncorrectError->hide();
        return true;
    }


    if(user.searchPasswordInList(password)) {
        Users userTmp;
        Node<Users> *tmp = user.usersList.getHeadNode();
        while (tmp) {
            if (tmp->getData().getUsername() == ui->usernameLineEditL->text()){
                userTmp = tmp->getData();
            }
            tmp = tmp->getNextNode();
        }

        if(userTmp.getPassword() == password) {
            ui->loginPasswordIncorrectError->hide();
            return true;
        } else {
            ui->loginPasswordEmptyError->hide();
            ui->loginPasswordInvalidError->hide();
            ui->loginPasswordIncorrectError->show();
            return false;
        }

    } else {
        ui->loginPasswordEmptyError->hide();
        ui->loginPasswordInvalidError->hide();
        ui->loginPasswordIncorrectError->show();
        return false;
    }
}
bool LoginSigninForm::checkEmptyLoginUsername(){
    if(ui->usernameLineEditL->text() == "") {
        ui->loginUsernameInvalidError->hide();
        ui->loginUsernameIncorrectError->hide();
        ui->loginUsernameEmptyError->show();
        return false;
    }
    ui->loginUsernameEmptyError->hide();
    return true;
}
bool LoginSigninForm::checkEmptyLoginPassword(){
    if(ui->passwordLineEditL->text() == "") {
        ui->loginPasswordInvalidError->hide();
        ui->loginPasswordIncorrectError->hide();
        ui->loginPasswordEmptyError->show();
        return false;
    }
    ui->loginPasswordEmptyError->hide();
    return true;

}

void LoginSigninForm::checkLoginFieldsValue(){
    bool checkEmpty = false;
    bool checkValid = false;
    bool checkCorrect = false;

    if(checkEmptyLoginPassword())
        checkEmpty = true;
    if(checkEmptyLoginUsername())
        checkEmpty = true;

    if(checkCorrectLoginPassword())
        checkCorrect = true;
    if(checkCorrectLoginUsername())
        checkCorrect = true;

    if(checkValidLoginPassword())
        checkValid = true;
    if(checkValidLoginUsername())
        checkValid = true;

    if(checkCorrect && checkEmpty && checkValid) {
        openUserPanelForm();
    }


}

void LoginSigninForm::openUserPanelForm () {
    Users userTmp;

    Node<Users> *tmp = user.usersList.getHeadNode();
    while (tmp) {
        if (tmp->getData().getUsername() == ui->usernameLineEditL->text()
            && tmp->getData().getPassword() == ui->passwordLineEditL->text()) {
            userTmp = tmp->getData();
            break;
        }
        tmp = tmp->getNextNode();
    }

    userTmp.usersList.setHeadNode(user.usersList.getHeadNode());

    UserPanel *userPanel = new UserPanel(userTmp);
    userPanel->show();
    this->close();
}

