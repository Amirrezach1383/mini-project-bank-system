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

public:
    explicit NewAccountForm(Users, QWidget *parent = nullptr);
    ~NewAccountForm();

private:
    Users user;
    Ui::NewAccountForm *ui;
};

#endif // NEWACCOUNTFORM_H
