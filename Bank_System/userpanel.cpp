#include "userpanel.h"
#include "ui_userpanel.h"
#include <users.h>
#include "transfer.h"
#include "newaccountform.h"
#include "changepasses.h"
#include "balanceform.h"
#include "loginsigninform.h"

UserPanel::UserPanel(Users users, QWidget *parent) : QWidget(parent) , user(users), ui(new Ui::UserPanel) {
    ui->setupUi(this);

    /// Set Label's Texts
    ui->firstNameLabel->setText(user.getUserName());
    ui->lastNameLabel->setText(user.getLastName());
    ui->nationalCodeLabel->setText(user.getNationalCode());

    /// ================ Connect To Other Pages ==================

    connect(ui->logoutPushButton, SIGNAL(clicked()), this, SLOT(openLoginSignUpForm()));
    connect(ui->newAccountPushButton, SIGNAL(clicked()), this, SLOT(openNewAccountForm()));
    connect(ui->changPasswordPushButton, SIGNAL(clicked()), this, SLOT(openChangePasswordForm()));
    connect(ui->showBalancePushButton, SIGNAL(clicked()), this, SLOT(openBalanceForm()));
    connect(ui->transferPushButton, SIGNAL(clicked()), this, SLOT(openTransferForm()));
}

/// ====== Open Other Forms =======

void UserPanel::openTransferForm() {
    Transfer *transfer = new Transfer(user);
    transfer->show();
    this->close();
}
void UserPanel::openNewAccountForm() {
    NewAccountForm *newAccount = new NewAccountForm(user);
    newAccount->show();
    this->close();
}
void UserPanel::openBalanceForm() {
    BalanceForm *balance = new BalanceForm(user);
    balance->show();
    this->close();
}
void UserPanel::openChangePasswordForm() {
    ChangePasses *changePassword = new ChangePasses(user);
    changePassword->show();
    this->close();
}
void UserPanel::openLoginSignUpForm() {
    LoginSigninForm *loginSignin = new LoginSigninForm;
    loginSignin->show();
    this->close();
}




UserPanel::~UserPanel()
{
    delete ui;
}
