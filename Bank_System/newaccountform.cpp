#include "newaccountform.h"
#include "ui_newaccountform.h"
#include "userpanel.h"


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

/// ============ Set User Information ============
void NewAccountForm::setUserInformation() {
    ui->firstNameLabel->setText(user.getFirstName());
    ui->lastNameLabel->setText(user.getLastName());
    ui->nationalCodeLabel->setText(user.getNationalCode());
}
