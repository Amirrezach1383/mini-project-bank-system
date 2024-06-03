#include <loginsigninform.h>
#include <userpanel.h>

#include <QApplication>

#include <windows.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginSigninForm w;
    UserPanel u;
    w.show();
    u.show();
    return a.exec();
}
