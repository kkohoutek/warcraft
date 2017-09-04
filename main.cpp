#include "mainwindow.h"
#include <QApplication>
#include <QDEBUG>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
