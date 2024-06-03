#include "loginsigninform.h"
#include "ui_loginsigninform.h"

LoginSigninForm::LoginSigninForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginSigninForm)
{
    ui->setupUi(this);
}

LoginSigninForm::~LoginSigninForm()
{
    delete ui;
}
