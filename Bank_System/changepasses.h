#ifndef CHANGEPASSES_H
#define CHANGEPASSES_H

#include <QWidget>
#include "users.h"

namespace Ui {
class ChangePasses;
}

class ChangePasses : public QWidget
{
    Q_OBJECT
private slots:
    void openUserPanelForm ();

public:
    explicit ChangePasses(Users, QWidget *parent = nullptr);
    ~ChangePasses();
    Users user;

private:
    Ui::ChangePasses *ui;
};

#endif // CHANGEPASSES_H
