#ifndef LOGINSIGNINFORM_H
#define LOGINSIGNINFORM_H

#include <QWidget>

namespace Ui {
class LoginSigninForm;
}

class LoginSigninForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginSigninForm(QWidget *parent = nullptr);
    ~LoginSigninForm();

private:
    Ui::LoginSigninForm *ui;
};

#endif // LOGINSIGNINFORM_H
