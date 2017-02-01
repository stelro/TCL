#include "splashdialog.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SplashDialog w;
    w.show();

    return a.exec();
}
