#include "Mainwindow.h"
#include "Form_login.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form_Login w;
    w.show();

    return a.exec();
}
