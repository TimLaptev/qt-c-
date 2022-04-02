/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *plus;
    QPushButton *previous;
    QPushButton *perf;
    QPushButton *stop;
    QPushButton *pause;
    QPushButton *next;
    QTableView *tableView;
    QDial *dial;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(297, 276);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plus = new QPushButton(centralwidget);
        plus->setObjectName(QString::fromUtf8("plus"));
        plus->setGeometry(QRect(10, 10, 41, 23));
        previous = new QPushButton(centralwidget);
        previous->setObjectName(QString::fromUtf8("previous"));
        previous->setGeometry(QRect(50, 10, 41, 23));
        perf = new QPushButton(centralwidget);
        perf->setObjectName(QString::fromUtf8("perf"));
        perf->setGeometry(QRect(90, 10, 41, 23));
        stop = new QPushButton(centralwidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(170, 10, 41, 23));
        pause = new QPushButton(centralwidget);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(130, 10, 41, 23));
        next = new QPushButton(centralwidget);
        next->setObjectName(QString::fromUtf8("next"));
        next->setGeometry(QRect(210, 10, 41, 23));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 40, 256, 192));
        tableView->setStyleSheet(QString::fromUtf8("background: transparent"));
        dial = new QDial(centralwidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(240, 0, 61, 41));
        dial->setSingleStep(3);
        dial->setOrientation(Qt::Horizontal);
        dial->setWrapping(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 210, 47, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(245, 211, 21, 21));
        pushButton->setStyleSheet(QString::fromUtf8("background: transparent"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 297, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        previous->setText(QCoreApplication::translate("MainWindow", "<=", nullptr));
        perf->setText(QCoreApplication::translate("MainWindow", "forward", nullptr));
        stop->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        pause->setText(QCoreApplication::translate("MainWindow", "pause", nullptr));
        next->setText(QCoreApplication::translate("MainWindow", "=>", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
