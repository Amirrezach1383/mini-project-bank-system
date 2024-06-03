#include "balanceform.h"
#include "ui_balanceform.h"

BalanceForm::BalanceForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BalanceForm)
{
    ui->setupUi(this);
}

BalanceForm::~BalanceForm()
{
    delete ui;
}
