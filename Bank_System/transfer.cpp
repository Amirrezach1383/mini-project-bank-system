#include "transfer.h"
#include "ui_transfer.h"
#include "users.h"

Transfer::Transfer(Users users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::Transfer) {

    ui->setupUi(this);
}

Transfer::~Transfer()
{
    delete ui;
}
