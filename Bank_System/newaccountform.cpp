#include "newaccountform.h"
#include "ui_newaccountform.h"

NewAccountForm::NewAccountForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NewAccountForm)
{
    ui->setupUi(this);
    ui->cardInformationGroupBox->hide();
    ui->accountInformationGroupBox->hide();
}

NewAccountForm::~NewAccountForm()
{
    delete ui;
}
