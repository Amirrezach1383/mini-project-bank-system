#include "changepasses.h"
#include "ui_changepasses.h"

ChangePasses::ChangePasses(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangePasses)
{
    ui->setupUi(this);
}

ChangePasses::~ChangePasses()
{
    delete ui;
}
