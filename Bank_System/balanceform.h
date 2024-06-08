#ifndef BALANCEFORM_H
#define BALANCEFORM_H

#include <QWidget>
#include <users.h>

namespace Ui {
class BalanceForm;
}

class BalanceForm : public QWidget
{
    Q_OBJECT
private slots:
    void openUserPanelForm();
    void showBalancePushButton();

public:
    explicit BalanceForm(Users, QWidget *parent = nullptr);
    ~BalanceForm();

    /// Set Users Informations
    void setUsersInformations();
    // Set ComboBox Value
    void setAccountComboBoxValue();

    /// Set And Check Errors
    bool checkAllErrors();
    bool checkAccountComboBox();

    /// Show Balance Value
    void showBalanceValue (BankAccount);

    /// Search BankAccount Function
    BankAccount searchBankAccount ();


private:
    Users user;
    Ui::BalanceForm *ui;


};

#endif // BALANCEFORM_H
