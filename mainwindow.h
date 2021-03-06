#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBrush>
#include <QPalette>
#include <QPixmap>
#include <QResource>
#include <QMediaPlayer>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "highscores.h"
#include "credits.h"
#include "settings.h"
#include "render_window.h"
#include "sprites.h"
#include "level.h"
#include "editeur.h"
#include "variablesglobs.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setVol();
    void muteVolume();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    HighScores *HighScore;
    Credits *Credit;
    Settings *Setting;
    Level *Levels;
    Editeur *Editor;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *selectLevel;
    QPushButton *pushEditeur;
    QMediaPlayer *player;

private slots:
    void openHighScores();
    void openCredits();
    void openRenderWindow();
    void openSettings();
    void openLevelWindow();
    void openEditor();

};

#endif // MAINWINDOW_H
