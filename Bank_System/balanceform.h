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

public:
    explicit BalanceForm(Users, QWidget *parent = nullptr);
    ~BalanceForm();
    Users user;

private:
    Ui::BalanceForm *ui;
};

#endif // BALANCEFORM_H
