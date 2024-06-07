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

    void checkBoxChangeLineEditEnableOrDisable();

public:
    explicit NewAccountForm(Users, QWidget *parent = nullptr);
    ~NewAccountForm();

private:
    Users user;
    Ui::NewAccountForm *ui;

    void setUserInformation();

    /// Set Users Account And Card Information
    Cards setUsersCardInformation();
    void setUsersAccountInformation();

    void addNewDataToUserLists();

    void setCardsInformationInFormsLabels();
    void setAccountInformationInFormsLabels();

    /// Make Account and Card Information
    QString makeAccountNum();
    QString makeShabaNumber(QString);

    QString makeCardNum();
    QString makeCardExpirationDate();
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
    bool checkFixedSecondPasswordValid();

    bool checkComboBox();
};

#endif // NEWACCOUNTFORM_H
