#include "mainwindow.h"
#include <QtCore/QCoreApplication>

#include <QApplication>
#include <QLineEdit>
#include<random>
#include<string>
#include<ctime>
#include<QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QFile::link("generatorpassword.exe","generatorpassword.exe.lnk");

    return a.exec();
}
