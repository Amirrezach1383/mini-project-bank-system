#include "transfer.h"
#include "ui_transfer.h"
#include "users.h"
#include "userpanel.h"

Transfer::Transfer(Users* users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::Transfer) {

    ui->setupUi(this);
    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));

}

void Transfer::openUserPanelForm() {
    UserPanel *userPanel = new class UserPanel(user);
    userPanel->show();
    this->close();
}

Transfer::~Transfer()
{
    delete ui;
}
