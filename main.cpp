#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w;
    w = new MainWindow(nullptr,Package::server);

    return a.exec();
}
