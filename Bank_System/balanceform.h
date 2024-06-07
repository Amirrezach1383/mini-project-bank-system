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

    /// Set And Check Errors
    bool checkAllErrors();
    bool checkAccountComboBox();

    /// Show Balance Value
    void showBalanceValue ();

    /// Search BankAccount Function
    int searchBankAccount ();


private:
    Users user;
    Ui::BalanceForm *ui;


};

#endif // BALANCEFORM_H
