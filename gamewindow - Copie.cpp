#include "gamewindow.h"
#include <SFML/Window.hpp>

GameWindow::GameWindow(QWidget *Parent, const QPoint &Position, const QSize &Size, unsigned int FrameTime) :
QWidget       (Parent),
myInitialized (false)
{
        setAttribute(Qt::WA_PaintOnScreen);
        setAttribute(Qt::WA_OpaquePaintEvent);
        setAttribute(Qt::WA_NoSystemBackground);

        setFocusPolicy(Qt::StrongFocus);

        move(Position);
        resize(Size);

        myTimer.setInterval(FrameTime);
}


void GameWindow::showEvent(QShowEvent*)
{
    if (!myInitialized)
    {

        Create(winId());

        OnInit();

        connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
        myTimer.start();

        myInitialized = true;
    }
}

QPaintEngine* GameWindow::paintEngine() const
{
    return 0;
}


void GameWindow::paintEvent(QPaintEvent*)
{
    OnUpdate();

    Display();
}
