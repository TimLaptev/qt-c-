#include "mainwindow.h"
#include<QApplication>

#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QString>
#include <QLineEdit>
#include<QLabel>
#include<QClipboard>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

ui->setupUi(this);
ui->lineEdit->setText("");
ui->lineEdit->setStyleSheet(QString("QLineEdit {border-width: 2px;"
                                    "  border-style:transparent; "
                                                 "border-color::solid ;}"));


this->setFixedSize(162,122);
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_pushButton_clicked()
{
    delete statusBar();
  QString str;
  str=ui->lineEdit->text();
  int a=str.toInt();
  passwordgenetatorclass p(a);
  ui->lineEdit->setText(p.gener());

}

void MainWindow::on_pushButton_2_clicked()
{
            delete statusBar();
            QString str=ui->lineEdit->text();
           QApplication::clipboard()->setText(str);
           statusBar()->addWidget(new QLabel("Строка скопирована"));
}

