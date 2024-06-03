#include <loginsigninform.h>
#include <userpanel.h>
#include <balanceform.h>
#include <newaccountform.h>
#include <changepasses.h>
#include <QApplication>

#include <windows.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginSigninForm w;
    UserPanel u;
    BalanceForm b;
    NewAccountForm A;
    ChangePasses p;

    w.show();
    u.show();
    b.show();
    A.show();
    p.show();
    return a.exec();
}
