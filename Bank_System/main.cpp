#include <loginsigninform.h>
#include <userpanel.h>
#include <balanceform.h>
#include <newaccountform.h>
#include <changepasses.h>
#include <QApplication>
#include <transfer.h>
#include <users.h>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    LoginSigninForm w(*new Users);
    w.show();
    return a.exec();
}
