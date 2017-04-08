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

private:
    sf::Texture background;
    sf::Sprite spriteBackground;

};

#endif // SPRITES_H
