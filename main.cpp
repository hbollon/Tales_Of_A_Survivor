#include "mainwindow.h"
#include "highscores.h"
#include <QApplication>

MainWindow *w;

void vol()
{
    w->setVol();
}

void mute()
{
    w->muteVolume();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    w = new MainWindow();
    w->show();

    int result = a.exec();

    delete w;
    w = NULL;

    return result;
}
