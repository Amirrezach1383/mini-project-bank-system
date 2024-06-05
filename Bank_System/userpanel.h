#ifndef USERPANEL_H
#define USERPANEL_H

#include "users.h"
#include <QWidget>
#include <users.h>

namespace Ui {
class UserPanel;
}

class UserPanel : public QWidget
{
    Q_OBJECT
private slots:

    /// ====== Opening Forms Functions ======
    void openTransferForm();
    void openNewAccountForm();
    void openBalanceForm();
    void openChangePasswordForm();
    void openLoginSignUpForm();


public:
    explicit UserPanel(Users, QWidget *parent = nullptr);
    ~UserPanel();
    Users user;

private:
    Ui::UserPanel *ui;
};

#endif // USERPANEL_H
