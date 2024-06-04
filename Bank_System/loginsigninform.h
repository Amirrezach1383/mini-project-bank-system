#ifndef LOGINSIGNINFORM_H
#define LOGINSIGNINFORM_H

#include <QWidget>

namespace Ui {
class LoginSigninForm;
}

class LoginSigninForm : public QWidget
{
    Q_OBJECT
private slots:
    void pushSignUpInputs();
    void checkTheFieldsFilled();

public:
    explicit LoginSigninForm(QWidget *parent = nullptr);
    ~LoginSigninForm();

private:
    Ui::LoginSigninForm *ui;
};

#endif // LOGINSIGNINFORM_H
