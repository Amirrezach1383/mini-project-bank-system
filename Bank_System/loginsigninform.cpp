#include "loginsigninform.h"
#include "ui_loginsigninform.h"
#include "users.h"
#include "linklist.h"


LoginSigninForm::LoginSigninForm(QWidget *parent) : QWidget(parent), ui(new Ui::LoginSigninForm) {

    ui->setupUi(this);
    ui->ageError->hide();
    ui->usernameFillError->hide();
    ui->nationalCodeError->hide();
    ui->firstNameError->hide();
    ui->lastNameError->hide();
    ui->passwordFillError->hide();

    connect(ui->signinPushButton, SIGNAL(clicked()), this, SLOT(checkTheFieldsFilled()));
}
void LoginSigninForm::checkTheFieldsFilled () {
    bool checkTrue = true;

    if(ui->firstNameLineEdit->text() == "") {
        ui->firstNameError->show();
        checkTrue = false;
    } else if (!ui->firstNameError->isHidden())
        ui->firstNameError->hide();

    if(ui->lastNameLineEdit->text() == "") {
        ui->lastNameError->show();
        checkTrue = false;
    } else if (!ui->lastNameError->isHidden())
        ui->lastNameError->hide();

    if(ui->ageLineEdit->text() == "") {
        ui->ageError->show();
        checkTrue = false;
    } else if (!ui->ageError->isHidden())
        ui->ageError->hide();

    if(ui->nationalCodeLineEdit->text() == "") {
        ui->nationalCodeError->show();
        checkTrue = false;
    } else if (!ui->nationalCodeError->isHidden())
        ui->nationalCodeError->hide();

    if(ui->usernameLineEditS->text() == "") {
        ui->usernameFillError->show();
        checkTrue = false;
    } else if (!ui->usernameFillError->isHidden())
        ui->usernameFillError->hide();

    if(ui->passwordLineEditS->text() == "") {
        ui->passwordFillError->show();
        checkTrue = false;
    } else if (!ui->passwordFillError->isHidden())
        ui->passwordFillError->hide();



    if(checkTrue) {
        pushSignUpInputs();
    } else
        LoginSigninForm();

}

void LoginSigninForm::pushSignUpInputs() {

    Users users;
    users.setName(ui->firstNameLineEdit->text());
    users.setLastName(ui->lastNameLineEdit->text());
    users.setNationnalCode(ui->nationalCodeLineEdit->text());
    users.setAge(ui->ageLineEdit->text());
    users.setUserName(ui->usernameLineEditS->text());
    users.setPassword(ui->passwordLineEditS->text());

    userList.pushBack(users);
}

LoginSigninForm::~LoginSigninForm() {
    delete ui;
}
