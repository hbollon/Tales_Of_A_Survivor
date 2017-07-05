#ifndef MONSTRE_H_INCLUDED
#define MONSTRE_H_INCLUDED

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "render_window.h"


class monstre
{
public:
    monstre();
    float getX() const;
    float getY() const;
    int getCounter() const;
    void incrementCounter();
    void resetCounter();
    sf::Sprite getSprite() const;

    void moveRight();
    void moveLeft();


private:
    sf::Texture m_monstreTexture;
    sf::Sprite m_monstreSprite;
    sf::Texture m_monstreTextureInv;

    float m_X;
    float m_Y;
    float m_counter;
};
#endif // MONSTRE_H_INCLUDED
