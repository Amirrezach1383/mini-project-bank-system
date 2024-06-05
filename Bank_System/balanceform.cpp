#include "balanceform.h"
#include "ui_balanceform.h"
#include "users.h"

BalanceForm::BalanceForm(Users users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::BalanceForm)
{
    ui->setupUi(this);
    ui->footerBalanceLabel->hide();
    ui->valueLabel->hide();
}

BalanceForm::~BalanceForm()
{
    delete ui;
}
