#ifndef TRANSFER_H
#define TRANSFER_H

#include <QWidget>
#include "users.h"

namespace Ui {
class Transfer;
}

class Transfer : public QWidget
{
    Q_OBJECT
private slots:
    void openUserPanelForm ();
    void transferPushButton();
    void setUserBalanceInForm();
    void getSecondPassPushButton();

    void destinationCardNumberLineEdit();
    void cvv2LineEdit();
    // void secondPasswordLineEdit();
    void transferAmountLineEdit();
public:
    explicit Transfer(Users, QWidget *parent = nullptr);
    ~Transfer();

    Users user;

    QString secondTimePassword;

    void setRandomSecondPassword();

    void disableAllWidget();

    ///========== Check And Set Functions ==========
    bool checkAllErrors ();

    bool checkChangePasswordError ();

    bool checkTheCardsNumSame();

    bool checkOrirginCardNumComboBoxError();
    bool checkOriginCardExpirationDate();

    bool checkTransferAmountLineEditError();
    bool checkTransferAmountLineEditValid();
    bool checkTransferAmountInRange();
    bool checkTransferAmountIn24Hour();
    bool checkTransferAmountsRange();


    bool checkSecondPasswordLineEditError();
    bool checkSecondPasswordLineEditValid();
    bool checkSecondPasswordLineEditExist();
    bool checkGetSecondPasswordLineEditErorr();

    bool checkDestinationCardNumLineEditError();
    bool checkDestinationCardNumLineValid();
    bool checkDestinationCardNumLineEditExist();
    bool checkDestinationCardExpiration();


    bool checkCvv2LineEditError();
    bool checkCvv2LineEditValid();
    bool checkCvv2LineEditExist();

    /// Set Destination Account's User's INFO
    void setDesUserInfo();

    /// Set Changes in Users BankAccounts
    void setChangeInDestinationAccount();
    void setChangeInOriginAccount();
    void setChangesInLastTransactionBankAccount();

    void updateUsersBankAccount(BankAccount);

    void setDateAndAmountLastTransacion(BankAccount&);

    /// Search Function
    bool searchCard(QString);
    bool searchSecondPassword(QString);

    Cards findOrirginCard(QString);
    Cards findDesCard(QString);

    BankAccount findOriginCardBankAccount(QString);
    BankAccount findDesCardBankAccount(QString);

    Users findDesUser();

    /// Time Functions

    bool isBeforeNow(const std::tm& date);
    bool checkPassed24hour(tm);

    void checkAndUpdateLastTransactionDate ();

    /// Get Random Number
    int getRandomNumber ();

    /// Set Users Informatioins In forms label
    void setUsersInformationInFormsLabels ();

    void setUsersCardsInformation();





private:
    Ui::Transfer *ui;


};

#endif // TRANSFER_H
