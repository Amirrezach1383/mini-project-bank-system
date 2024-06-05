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
void BalanceForm::openUserPanelForm() {
    UserPanel *userPanel = new class UserPanel(user);
    userPanel->show();
    this->close();
}


BalanceForm::~BalanceForm()
{
    delete ui;
}
