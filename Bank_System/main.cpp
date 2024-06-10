#include <loginsigninform.h>
#include <userpanel.h>
#include <balanceform.h>
#include <newaccountform.h>
#include <changepasses.h>
#include <QApplication>
#include <transfer.h>
#include <users.h>

int main(int argc, char *argv[]) {
    Users user;
    user.setUsername("amir1383");
    user.setFirstName("Amirreza");
    user.setLastName("Chami");
    user.setPassword("amir1383");
    user.setAge("25");
    user.setNationnalCode("1080711287");

    user.addUserToList();

    user.setUsername("amir1386");
    user.setFirstName("Amir");
    user.setLastName("Chami");
    user.setPassword("amir_1386");
    user.setAge("22");
    user.setNationnalCode("1020711287");

    user.addUserToList();

    QApplication a(argc, argv);
    LoginSigninForm w(user);
    // UserPanel u(new Users);
    // BalanceForm b;
    // NewAccountForm A(user);
    // ChangePasses p;
    // Transfer t;

    w.show();

    return a.exec();
}
