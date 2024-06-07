#include "balanceform.h"
#include "ui_balanceform.h"
#include "users.h"
#include "userpanel.h"

BalanceForm::BalanceForm(Users users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::BalanceForm)
{
    ui->setupUi(this);

    ui->footerBalanceLabel->hide();
    ui->valueLabel->hide();

    setUsersInformations();
    setAccountComboBoxValue();

    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));

    /// Connect ShowBalance PushButton
    connect(ui->showBalancePushButton, SIGNAL(clicked()), this, SLOT(showBalancePushButton()));

}

///======== Private Slots ===========

void BalanceForm::openUserPanelForm() {
    UserPanel *userPanel = new class UserPanel(user);
    userPanel->show();
    this->close();
}

void BalanceForm::showBalancePushButton() {
    if(checkAllErrors()) {
        int i = searchBankAccount();
        showBalanceValue(i);
    }
}

/// Set And Check Errors Functions

bool BalanceForm::checkAllErrors () {
    bool checkAllErrors = true;

    if(!checkAccountComboBox())
        checkAllErrors = false;

    if(checkAllErrors)
        return true;

    return false;
}

bool BalanceForm::checkAccountComboBox() {
    if(ui->accountComboBox->currentText() == "") {
        ui->accountComboBoxErrorLabel->setText("Please Choose One Account");
        return false;
    }
    ui->accountComboBoxErrorLabel->clear();
    return true;
}

/// Search BankAccount Function
int BalanceForm::searchBankAccount() {
    QString accountNum = ui->accountComboBox->currentText();
    int i = 0;

    while(i < user.getNumOfUserAccount()) {
        if(user.getBankAccount(i).getAccountNumber() == accountNum)
            return i;
        i++;
    }
    return -1;
}

/// show Balance Value
void BalanceForm::showBalanceValue(int i) {

    ui->valueLabel->setText(QString::number(user.getBankAccount(i).getBalance()));
    ui->footerBalanceLabel->show();
    ui->valueLabel->show();
}

/// Set Users Informations
void BalanceForm::setUsersInformations (){
    ui->firstNameLabel->setText(user.getFirstName());
    ui->lastNameLabel->setText(user.getLastName());
    ui->nationalCodeLabel->setText(user.getNationalCode());

}
// Set AccountComboBox Value
void BalanceForm::setAccountComboBoxValue() {
    int i = 0;

    while(i < user.getNumOfUserAccount()) {
        ui->accountComboBox->addItem(user.getBankAccount(i).getAccountNumber());
        i++;
    }

}



BalanceForm::~BalanceForm()
{
    delete ui;
}
