#include "changepasses.h"
#include "ui_changepasses.h"
#include "users.h"

ChangePasses::ChangePasses(Users users, QWidget *parent) : QWidget(parent), user(users), ui(new Ui::ChangePasses)
{
    ui->setupUi(this);


}

ChangePasses::~ChangePasses()
{
    delete ui;
}
