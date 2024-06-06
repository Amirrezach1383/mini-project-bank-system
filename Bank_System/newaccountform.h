#ifndef NEWACCOUNTFORM_H
#define NEWACCOUNTFORM_H

#include <QWidget>
#include "users.h"
#include <ctime>

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

    /// Set Users Account And Card Information
    void setUsersCardInformation();
    void setUsersAccountInformation();

    /// Make Account and Card Information
    QString makeAccountNum();
    QString makeCardNum();
    QString makeCardExpirationDate();
    QString makeShabaNumber();
    QString makeCvv2();

    int findAccountType();
    int getRandomNumber ();

    /// Check and set Errors In form
    bool checkAllError();
    bool checkInitialBalanceLineEdit();
    bool checkInitialBalanceValid();
    bool checkPasswordLineEdit();
    bool checkPasswordValid();
    bool checkFixedSecondPassword();



private:
    Users user;
    Ui::NewAccountForm *ui;
};

#endif // NEWACCOUNTFORM_H
