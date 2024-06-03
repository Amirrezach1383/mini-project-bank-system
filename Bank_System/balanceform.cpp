#include "balanceform.h"
#include "ui_balanceform.h"

BalanceForm::BalanceForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BalanceForm)
{
    ui->setupUi(this);
    ui->footerBalanceLabel->hide();
    ui->valueLabel->hide();
}

BalanceForm::~BalanceForm()
{
    delete ui;
}
