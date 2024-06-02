#include "LoginSigninPage.h"
#include "ui_LoginSigninPage.h"

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}
