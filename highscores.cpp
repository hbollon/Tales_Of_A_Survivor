#include "highscores.h"
#include "ui_highscores.h"

HighScores::HighScores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HighScores)
{
    ui->setupUi(this);
}

HighScores::~HighScores()
{
    delete ui;
}
