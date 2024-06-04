#ifndef LOGINSIGNINFORM_H
#define LOGINSIGNINFORM_H

#include <QWidget>

namespace Ui {
class LoginSigninForm;
}

class LoginSigninForm : public QWidget {
    Q_OBJECT
private slots:
    void checkTheFieldsValue();

public:
    explicit LoginSigninForm(QWidget *parent = nullptr);
    ~LoginSigninForm();

private:

    /// ========= Sign Up ==========
    /// hide Error Functions
    void hideAllError();

    /// Clean SignUp Fields
    void cleanFields ();

    ///Check Value Functions
    bool checkCorrectAgeValue();
    bool checkCorrectNationalCodeValue();
    bool checkCorrectFirstName();
    bool checkCorrectLastName();
    bool checkCorrectUserName();
    bool checkCorrectPassword();
    // void setUsernameExistErrorInForm();

    /// Push Inputs
    void pushSignUpInputs();
    ///=============================================

    ///=========== Login =============
    void checkLoginFieldsValue();
    bool checkValidLoginUsername();
    bool checkValidLoginPassword();


    Ui::LoginSigninForm *ui;

};

#endif // LOGINSIGNINFORM_H
