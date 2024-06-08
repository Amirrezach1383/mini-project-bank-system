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

public:
    explicit Transfer(Users, QWidget *parent = nullptr);
    ~Transfer();

    Users user;

    ///========== Check And Set Functions ==========
    bool checkAllErrors ();

    bool checkOrirginCardNumComboBoxError();
    bool checkOriginCardExpirationDate();

    bool checkTransferAmountLineEditError();
    bool checkTransferAmountLineEditValid();
    bool checkTransferAmountInRange();
    bool checkTransferAmountIn24Hour();


    bool checkSecondPasswordLineEditError();
    bool checkSecondPasswordLineEditValid();
    bool checkSecondPasswordLineEditExist();

    bool checkDestinationCardNumLineEditError();
    bool checkDestinationCardNumLineValid();
    bool checkDestinationCardNumLineEditExist();
    bool checkDestinationCardExpiration();


    bool checkCvv2LineEditError();
    bool checkCvv2LineEditValid();
    bool checkCvv2LineEditExist();

    /// Set Destination Account's User's INFO
    void setDesUserInfo();


    /// Search Function
    bool searchCard(QString);
    bool searchSecondPassword(QString);

    Cards findOrirginCard(QString);
    BankAccount findOriginCardBankAccount(QString);
    Cards findDesCard(QString);

    Users findDesUser();

    /// Time Functions

    bool isBeforeNow(const std::tm& date);
    bool checkPassed24hour(tm);

    /// Set Users Informatioins In forms label
    void setUsersInformationInFormsLabels ();

    void setUsersCardsInformation();





private:
    Ui::Transfer *ui;


};

#endif // TRANSFER_H
