#ifndef USERPANEL_H
#define USERPANEL_H

#include "users.h"
#include <QWidget>
#include <users.h>

namespace Ui {
class UserPanel;
}

class UserPanel : public QWidget
{
    Q_OBJECT

public:
    explicit UserPanel(Users, QWidget *parent = nullptr);
    ~UserPanel();

private:
    Users user;
    Ui::UserPanel *ui;
};

#endif // USERPANEL_H
