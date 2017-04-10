#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QObject>
#include <QWidget>
#include <QTimer>
#include <SFML/Graphics.hpp>

class GameWindow : public QWidget, public sf::RenderWindow
{
    Q_OBJECT
public:
    GameWindow(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 0);

private:
    virtual void OnInit();

    virtual void OnUpdate();

    virtual QPaintEngine* paintEngine() const;

    virtual void showEvent(QShowEvent*);

    virtual void paintEvent(QPaintEvent*);

    QTimer myTimer;
    bool myInitialized;
};

#endif // GAMEWINDOW_H
