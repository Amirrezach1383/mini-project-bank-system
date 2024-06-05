#include "changepasses.h"
#include "ui_changepasses.h"
#include "users.h"
#include "userpanel.h"

ChangePasses::ChangePasses(Users *users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::ChangePasses)
{
    ui->setupUi(this);

    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));

}
void ChangePasses::openUserPanelForm() {
    UserPanel *userPanel = new class UserPanel(user);
    userPanel->show();
    this->close();
}
ChangePasses::~ChangePasses()
{
    delete ui;
}
