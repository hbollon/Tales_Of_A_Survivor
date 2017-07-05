#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <iostream>
#include <string>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "render_window.h"

class Personnage
{
public:
    Personnage();               //Constructeur
    int getX() const;
    int getY() const;
    float getTop() const;
    float getBottom() const;
    float getLeft() const;
    float getRight() const;
    sf::IntRect getBoundingBox() const;
    sf::Sprite getSprite() const; //recupere le sprite du personnage
    std::vector <sf::Vector2i> tiles;

    void moveRight();
    void moveLeft();
    void update();
    void colRight();
    void colLeft();
    void colTop();
    void colBottom();
    void jump();
    void moveUpdate();

private:
    sf::Texture m_persoTexture;
    sf::Texture m_persoTextureInv;
    sf::Sprite m_persoSprite;
    const float gravity = 1;
    int groundHeight = 615;
    float jumpSpeed = 15.f;
    float m_X;
    float m_Y;
    float top, left, right, bottom;

};

#endif // PERSONNAGE_H_INCLUDED
