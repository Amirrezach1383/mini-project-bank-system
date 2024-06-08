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
        BankAccount bankAccount = searchBankAccount();
        showBalanceValue(bankAccount);
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
BankAccount BalanceForm::searchBankAccount() {
    QString accountNum = ui->accountComboBox->currentText();

    Node<BankAccount> *tmp = user.userBankAccountsList.getHeadNode();
    while(tmp) {
        if(tmp->getData().getAccountNumber() == accountNum)
            return tmp->getData();

        tmp = tmp->getNextNode();
    }

    return *new BankAccount;
}

/// show Balance Value
void BalanceForm::showBalanceValue(BankAccount bankAccount) {

    ui->valueLabel->setText(bankAccount.getBalance());
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

    Node<BankAccount> *tmp = user.userBankAccountsList.getHeadNode();
    while(tmp) {
        ui->accountComboBox->addItem(tmp->getData().getAccountNumber());
        tmp = tmp->getNextNode();
    }

}



BalanceForm::~BalanceForm()
{
    delete ui;
}
