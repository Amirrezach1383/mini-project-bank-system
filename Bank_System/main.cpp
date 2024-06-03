#include <loginsigninform.h>
#include <userpanel.h>
#include <balanceform.h>
#include <newaccountform.h>

#include <QApplication>

#include <windows.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginSigninForm w;
    UserPanel u;
    BalanceForm b;
    NewAccountForm A;
    w.show();
    u.show();
    b.show();
    A.show();
    return a.exec();
}
