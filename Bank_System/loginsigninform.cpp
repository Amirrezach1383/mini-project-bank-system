#include "loginsigninform.h"
#include "ui_loginsigninform.h"
#include "users.h"
#include "linklist.h"


LoginSigninForm::LoginSigninForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginSigninForm)
{
    ui->setupUi(this);

    connect(ui->signinPushButton, SIGNAL(clicked()), this, SLOT(pushinput));
}

void LoginSigninForm::pushInput() {
    Users users;
    users.setName(ui->firstNameLineEdit->text());
    users.setLastName(ui->lastNameLineEdit->text());
    users.setNationnalCode(ui->nationalCodeLineEdit->text());
    users.setAge(ui->ageLineEdit->text());
    users.setUserName(ui->usernameLineEditS->text());
    users.setPassword(ui->passwordLineEditS->text());

    LinkList<Users> userList;
    userList.pushBack(users);



}

LoginSigninForm::~LoginSigninForm()
{
    delete ui;
}
