#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "render_window.h"

class Personnage
{
public:
    Personnage();               //Constructeur
    float getX() const;
    float getY() const;
    sf::Sprite getSprite() const; //recupere le sprite du personnage

    float moveRight();
    float moveLeft();
    float jumpNoMove();
    float jumpMoveRight();
    float jumpMoveLeft();

private:
    sf::Texture m_persoTexture;
    sf::Texture m_persoTextureInv;
    sf::Sprite m_persoSprite;
    float m_X;
    float m_Y;

};

#endif // PERSONNAGE_H_INCLUDED
