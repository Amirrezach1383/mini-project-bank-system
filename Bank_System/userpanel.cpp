#include "userpanel.h"
#include "ui_userpanel.h"
#include <users.h>


UserPanel::UserPanel(Users users, QWidget *parent) : QWidget(parent) , user(users), ui(new Ui::UserPanel) {
    ui->setupUi(this);
    ui->firstNameLabel->setText(user.getUserName());
    ui->lastNameLabel->setText(user.getLastName());
    ui->nationalCodeLabel->setText(user.getNationalCode());
}

UserPanel::~UserPanel()
{
    delete ui;
}
