#ifndef LOGINSIGNINFORM_H
#define LOGINSIGNINFORM_H

#include <QWidget>
#include <users.h>

namespace Ui {
class LoginSigninForm;
}

class LoginSigninForm : public QWidget {
    Q_OBJECT
private slots:
    void checkTheFieldsValue();
    void checkLoginFieldsValue();

    void showLoginPassword();
    void hideLoginPssword();

    void showSignUpPassword();
    void hideSignUpPssword();

public:
    explicit LoginSigninForm(Users, QWidget *parent = nullptr);
    ~LoginSigninForm();

private:

    Users user;
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
    bool checkUserExist();
    bool checkSignUpUsernameExist();

    /// Push Inputs
    void pushSignUpInputs();
    ///=============================================

    ///=========== Login =============

    bool checkValidLoginUsername();
    bool checkCorrectLoginUsername();
    bool checkEmptyLoginUsername();
    bool checkValidLoginPassword();
    bool checkCorrectLoginPassword();
    bool checkEmptyLoginPassword();


    void openUserPanelForm ();

    Ui::LoginSigninForm *ui;

};

#endif // LOGINSIGNINFORM_H
