#ifndef CHANGEPASSES_H
#define CHANGEPASSES_H

#include <QWidget>
#include "users.h"

namespace Ui {
class ChangePasses;
}

class ChangePasses : public QWidget
{
    Q_OBJECT
private slots:
    void openUserPanelForm ();

    void changeCardPasswordPushButton ();
    void changeFixedSecondPasswordPushButton ();

    void cardPasswordCheckBox();
    void fixedSecondCheckBox();



public:
    explicit ChangePasses(Users, QWidget *parent = nullptr);
    ~ChangePasses();
    Users user;

private:
    Ui::ChangePasses *ui;

    /// Check and Set Erros
    bool checkChangeCardPasswordAllError();
    bool checkChangeFixedSecondPasswordAllError();

    bool checkNewCardPasswordLineEditError();
    bool checkNewCardPasswordValid();
    bool checkNewCardPasswordDifference();

    bool checkNewFixedSecondPasswordLineEditError();
    bool checkNewFixedSecondPasswordValid();
    bool checkNewFixedSecondPasswordDifference();

    bool checkPreviousCardPasswordLineEditError();
    bool checkpreviousCardPasswordValid();
    bool checkpreviousCardPasswordExists();

    bool checkPreviousFixedSecondPasswordLineEditError();
    bool checkpreviousFixedSecondPasswordValid();
    bool checkpreviousFixedSecondPasswordExists();

    bool checkComboBoxError();

    /// Set NewPasses In User Information
    void setCardPasswordInformation();
    void setFixedSecondPasswordInformation();

    /// search user account
    BankAccount searchBankAccount ();

    void setNewBankAccountIinformation(BankAccount);

    void setAccountInformationInComboBox ();
};

#endif // CHANGEPASSES_H
