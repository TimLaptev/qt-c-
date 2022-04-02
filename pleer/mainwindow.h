#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QTimer>
#include <QTime>

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
    void on_plus_clicked();
    void on_dial_valueChanged(int value);
   void updateCountdown();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *tmr;
    QStandardItemModel  *m_playListModel;   // Модель данных плейлиста для отображения
       QMediaPlayer        *m_player;          // Проигрыватель треков
       QMediaPlaylist      *m_playlist;        // Плейлиста проигрывателя
};
#endif // MAINWINDOW_H
