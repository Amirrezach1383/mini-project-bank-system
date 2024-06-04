#include <loginsigninform.h>
#include <userpanel.h>
#include <balanceform.h>
#include <newaccountform.h>
#include <changepasses.h>
#include <QApplication>
#include <transfer.h>

#include <windows.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginSigninForm w;
    // UserPanel u;
    // BalanceForm b;
    // NewAccountForm A;
    // ChangePasses p;
    // Transfer t;

    w.show();

    return a.exec();
}
