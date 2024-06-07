#include "balanceform.h"
#include "ui_balanceform.h"
#include "users.h"
#include "userpanel.h"

BalanceForm::BalanceForm(Users users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::BalanceForm)
{
    ui->setupUi(this);

    ui->footerBalanceLabel->hide();
    ui->valueLabel->hide();


    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));

}

///======== Private Slots ===========

void BalanceForm::openUserPanelForm() {
    UserPanel *userPanel = new class UserPanel(user);
    userPanel->show();
    this->close();
}

/// Set And Check Errors Functions

bool BalanceForm::checkAllErrors () {
    bool checkAllErrors = true;

    if(!checkAccountComboBox())
        checkAllErrors = false;


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
int BalanceForm::searchBankAccount(){

}



/// Set Users Informations
void BalanceForm::setUsersInformations (){
    ui->firstNameLabel->setText(user.getFirstName());
    ui->lastNameLabel->setText(user.getLastName());
    ui->nationalCodeLabel->setText(user.getNationalCode());

}


BalanceForm::~BalanceForm()
{
    delete ui;
}
