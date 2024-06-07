#include "changepasses.h"
#include "ui_changepasses.h"
#include "users.h"
#include "userpanel.h"

ChangePasses::ChangePasses(Users users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::ChangePasses)
{
    ui->setupUi(this);

    /// Connect to UserPanelForm
    connect(ui->backPushButton, SIGNAL(clicked()), this, SLOT(openUserPanelForm()));

}

///========== Private Slots ============

void ChangePasses::openUserPanelForm() {
    UserPanel *userPanel = new class UserPanel(user);
    userPanel->show();
    this->close();
}

void ChangePasses::changeCardPasswordPushButton (){}
void ChangePasses::changeFixedSecondPasswordPushButton (){}

void ChangePasses::cardPasswordCheckBox(){}
void ChangePasses::fixedSecondCheckBox(){}

/// Check And Set Passwords Functions
bool ChangePasses::checkAllError(){}

bool ChangePasses::checkNewCardPasswordLineEditError(){}
bool ChangePasses::checkNewCardPasswordValid(){}

bool ChangePasses::checkNewFixedSecondPasswordLineEditError(){}
bool ChangePasses::checkNewFixedSecondPasswordValid(){}

bool ChangePasses::checkPreviousCardPasswordLineEditError(){}
bool ChangePasses::checkpreviousCardPasswordValid(){}
bool ChangePasses::checkpreviousCardPasswordExists(){}

bool ChangePasses::checkPreviousFixedSecondPasswordLineEditError(){}
bool ChangePasses::checkpreviousFixedSecondPasswordValid(){}
bool ChangePasses::checkpreviousFixedSecondPasswordExists(){}





ChangePasses::~ChangePasses()
{
    delete ui;
}
