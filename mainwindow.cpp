#include "mainwindow.h"
#include "settings.h"
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

    Render_Window *renderWindow = new Render_Window();
}
