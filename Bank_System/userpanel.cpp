#include "userpanel.h"
#include "ui_userpanel.h"

UserPanel::UserPanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserPanel)
{
    ui->setupUi(this);

}

UserPanel::~UserPanel()
{
    delete ui;
}
