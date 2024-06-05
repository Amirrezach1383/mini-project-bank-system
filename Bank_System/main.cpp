#include <loginsigninform.h>
#include <userpanel.h>
#include <balanceform.h>
#include <newaccountform.h>
#include <changepasses.h>
#include <QApplication>
#include <transfer.h>
#include <users.h>

int main(int argc, char *argv[])
{
    Users user;
    QApplication a(argc, argv);
    //LoginSigninForm w(new Users);
    UserPanel u(new Users);
    // BalanceForm b;
    // NewAccountForm A;
    // ChangePasses p;
    // Transfer t;

    u.show();

    return a.exec();
}
