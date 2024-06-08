#include "transfer.h"
#include "ui_transfer.h"
#include "users.h"
#include "userpanel.h"

Transfer::Transfer(Users users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::Transfer) {

    ui->setupUi(this);
    setUsersInformationInFormsLabels();

    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));


}

Transfer::~Transfer()
{
    delete ui;
}

/// Private Slots

void Transfer::openUserPanelForm() {
    UserPanel *userPanel = new UserPanel(user);
    userPanel->show();
    this->close();
}


/// Set Users Informations

void Transfer::setUsersInformationInFormsLabels () {
    ui->firstNameLabel->setText(user.getFirstName());
    ui->lastNameLabel->setText(user.getLastName());
    ui->nationalCodeLabel->setText(user.getNationalCode());
}
