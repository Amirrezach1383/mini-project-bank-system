#include "balanceform.h"
#include "ui_balanceform.h"
#include "users.h"
#include "userpanel.h"

BalanceForm::BalanceForm(Users *users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::BalanceForm)
{
    ui->setupUi(this);
    ui->footerBalanceLabel->hide();
    ui->valueLabel->hide();


    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));

    /// Show Title
    ui->firstNameLabel->setText(user->getFirstName());
    ui->lastNameLabel->setText(user->getLastName());
    ui->nationalCodeLabel->setText(user->getNationalCode());

}
void BalanceForm::openUserPanelForm() {
    UserPanel *userPanel = new class UserPanel(user);
    userPanel->show();
    this->close();
}


BalanceForm::~BalanceForm()
{
    delete ui;
}
