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

public:
    explicit Transfer(Users, QWidget *parent = nullptr);
    ~Transfer();

    Users user;
    ///========== Check And Set Functions ==========

    bool checkAllErrors ();

    bool checkOrirginCardNumComboBoxError();

    bool checkTransferAmountLineEditError();

    bool checkSecondPasswordLineEditError();

    bool checkDestinationCardNumLineEditError();

    bool checkCvv2LineEditError();
    bool checkCvv2LineEditValid();
    bool checkCvv2LineEditExist();

private:
    Ui::Transfer *ui;

    /// Set Users Informatioins In forms label
    void setUsersInformationInFormsLabels ();

};

#endif // TRANSFER_H
