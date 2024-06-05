#include "newaccountform.h"
#include "ui_newaccountform.h"

NewAccountForm::NewAccountForm(Users users, QWidget *parent)  : QWidget(parent), user(users), ui(new Ui::NewAccountForm) {

    ui->setupUi(this);
    ui->cardInformationGroupBox->hide();
    ui->accountInformationGroupBox->hide();
}

NewAccountForm::~NewAccountForm()
{
    delete ui;
}
