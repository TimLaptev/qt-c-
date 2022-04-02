#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{


    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits_numbers();
    void oper();
    void sq();
    void on_pushButton_zap_clicked();
    void math();
    void on_pushButton_rafens_clicked();
    void on_pushButton_ac_clicked();
    void on_comboBox_activated(int index);
};
#endif // MAINWINDOW_H
