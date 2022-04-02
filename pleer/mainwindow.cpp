#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QToolButton>
#include <QWidget>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_playListModel = new QStandardItemModel(this);//таблица плейлиста
     ui->tableView->setModel(m_playListModel);
     this->setFixedSize(297,276);


     m_playListModel->setHorizontalHeaderLabels(QStringList()  << tr("Audio Track")
                                                                << tr("File Path"));
        ui->tableView->hideColumn(1);    // Скрываем колонку, в которой хранится путь к файлу
        ui->tableView->verticalHeader()->setVisible(false);                  // Скрываем нумерацию строк
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);  // Включаем выделение строк
        ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // Разрешаем выделять только одну строку
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);   // Отключаем редактирование
        // Включаем подгонку размера последней видимой колонки к ширине TableView
        ui->tableView->horizontalHeader()->setStretchLastSection(true);



     m_player = new QMediaPlayer(this);          // Инициализируем плеер
     m_playlist = new QMediaPlaylist(m_player);  // Инициализируем плейлист
     m_player->setPlaylist(m_playlist);          // Устанавливаем плейлист в плеер
     m_player->setVolume(70);                    // Устанавливаем громкость воспроизведения треков
     m_playlist->setPlaybackMode(QMediaPlaylist::Loop);  // Устанавливаем циклический режим проигрывания плейлиста



         connect(ui->previous, &QToolButton::clicked, m_playlist, &QMediaPlaylist::previous);
         connect(ui->next, &QToolButton::clicked, m_playlist, &QMediaPlaylist::next);
         connect(ui->perf, &QToolButton::clicked, m_player, &QMediaPlayer::play);
         connect(ui->pause, &QToolButton::clicked, m_player, &QMediaPlayer::pause);
         connect(ui->stop, &QToolButton::clicked, m_player, &QMediaPlayer::stop);
         connect(ui->tableView, &QTableView::doubleClicked, [this](const QModelIndex &index){
                 m_playlist->setCurrentIndex(index.row());
             });



}
MainWindow::~MainWindow()
{
    delete ui;
    delete m_playListModel;
       delete m_playlist;
       delete m_player;
}






void MainWindow::on_plus_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                          tr("Open files"),
                                                          QString(),
                                                          tr("Audio Files (*.mp3)"));

        // Далее устанавливаем данные по именам и пути к файлам
        // в плейлист и таблицу отображающую плейлист


    foreach (QString filePath, files) {
            QList<QStandardItem *> items;
            items.append(new QStandardItem(QDir(filePath).dirName()));
            items.append(new QStandardItem(filePath));
            m_playListModel->appendRow(items);
            m_playlist->addMedia(QUrl(filePath));

        }


}



    void MainWindow::on_dial_valueChanged(int value)
    {

        m_player->setVolume(value);
    }




void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("");
    double i=m_player->duration();
    i/=(60*1000);
    ui->label->setText(QString::number(i));



}

void  MainWindow::updateCountdown(){


}
