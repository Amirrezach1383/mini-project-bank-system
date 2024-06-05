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
    explicit Transfer(Users* , QWidget *parent = nullptr);
    ~Transfer();

private:
    Users *user;
    Ui::Transfer *ui;
};

#endif // TRANSFER_H
