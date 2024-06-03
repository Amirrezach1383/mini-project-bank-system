#ifndef CHANGEPASSES_H
#define CHANGEPASSES_H

#include <QWidget>

namespace Ui {
class ChangePasses;
}

class ChangePasses : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePasses(QWidget *parent = nullptr);
    ~ChangePasses();

private:
    Ui::ChangePasses *ui;
};

#endif // CHANGEPASSES_H
