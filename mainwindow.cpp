#include "mainwindow.h"
#include "variablesglobs.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QResource::registerResource("ressourcesqtdesign.qrc");

    setWindowTitle("Tales Of A Survivor");

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage("bkg.jpg")));
    this->setPalette(palette);

    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("intro.mp3"));
    player->setVolume(50);
    player->play();

    pushButton_4 = new QPushButton("HIGHSCORES", this);
    pushButton_4 -> move(540, 260);
    pushButton_4 -> setMinimumSize(151, 61);

    pushButton = new QPushButton("PLAY", this);
    pushButton -> move(540, 160);
    pushButton -> setMinimumSize(151, 61);

    QObject::connect(pushButton_4, SIGNAL(clicked()), this, SLOT(openHighScores()));
    QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(openRenderWindow()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openHighScores()
{
    HighScore = new HighScores();
    HighScore -> show();
}

void MainWindow::openCredits()
{
    Credit = new Credits();
    Credit -> show();
}

void MainWindow::openSettings()
{
    Setting = new Settings();
    Setting -> show();
}


void MainWindow::openRenderWindow()
{
    player->stop();
    Render_Window *renderWindow = new Render_Window();
}

void MainWindow::muteVolume()
{
    player->setVolume(0);
}

void MainWindow::setVol()
{
    player->setVolume(musicVolEtat);
}
