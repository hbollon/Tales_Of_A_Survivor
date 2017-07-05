#ifndef SPRITES_H
#define SPRITES_H

#include <QWidget>
#include <QMessageBox>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "variablesglobs.h"

class sprites : public QWidget
{

public:
    sprites();
    void loadTextures();
    void createSprites();
    sf::Sprite getBackground();
    void moveRight();
    void moveLeft();
    void colPlayerRight();
    void colPlayerLeft();
    void jump();
    void moveUpdate();

private:
    sf::Texture background;
    sf::Sprite spriteBackground;
    const float gravity = 1;
    int groundHeight = 1280;
    float jumpSpeed = 15.f;

    float m_X;
    float m_Y;

};

#endif // SPRITES_H
