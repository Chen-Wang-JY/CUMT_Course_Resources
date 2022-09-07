#include "Form_welcome.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Form_welcome w;
    w.show();

    return a.exec();
}
