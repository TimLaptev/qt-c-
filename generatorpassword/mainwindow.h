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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
class passwordgenetatorclass
{
public:
    QString gener() {
        gen();
        return reselt;
    }
    passwordgenetatorclass(int size) {
        this->size = size;
    };


private:
    QString s1 = "abcdefghijklmnopqrstuvwxyz";
    QString s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString reselt;
    QString s;
    int size;
    void gen() {
        srand(time(NULL));
        int a = rand() % 24 + 0;
        reselt += s2[a];

        for (int i = 0; i < size - 1; i++) {
            int a = rand() % 3 + 0;
            if (a == 0)
            {
                int b = rand() % 24 + 0;
                reselt += s2[b];
            }
            else if (a == 2) {
                int b = rand() % 24 + 0;
                reselt += s1[b];
            }
            else
            {
                int b = rand() % 9 + 0;
                reselt +=QString::number(b);
            }
        }
    }//генератор без введенного слова






};
