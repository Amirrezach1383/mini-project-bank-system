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
    Cards findDesCard(QString);

    Users findDesUser();

    /// Time Functions

    bool isBeforeNow(const std::tm& date);



private:
    Ui::Transfer *ui;

    /// Set Users Informatioins In forms label
    void setUsersInformationInFormsLabels ();

};

#endif // TRANSFER_H
