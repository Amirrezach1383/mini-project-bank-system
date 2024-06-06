#ifndef NEWACCOUNTFORM_H
#define NEWACCOUNTFORM_H

#include <QWidget>
#include "users.h"

namespace Ui {
class NewAccountForm;
}

class NewAccountForm : public QWidget
{
    Q_OBJECT

private slots:
    void openUserPanelForm();
    void makeAccountPushButton();

public:
    explicit NewAccountForm(Users, QWidget *parent = nullptr);
    ~NewAccountForm();

    void setUserInformation();

private:
    Users user;
    Ui::NewAccountForm *ui;
};

#endif // NEWACCOUNTFORM_H
