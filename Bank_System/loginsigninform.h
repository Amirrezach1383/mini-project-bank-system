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
    void checkTheFieldsValue();

public:
    explicit LoginSigninForm(QWidget *parent = nullptr);
    ~LoginSigninForm();

private:
    void pushSignUpInputs();

    ///Check Value Functions
    bool checkCorrectAgeValue();
    bool checkCorrectNationalCodeValue();
    bool checkCorrectFirstName();
    bool checkCorrectLastName();
    bool checkCorrectUserName();
    bool checkCorrectPassword();


    Ui::LoginSigninForm *ui;
};

#endif // LOGINSIGNINFORM_H
