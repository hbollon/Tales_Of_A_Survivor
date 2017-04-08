#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <iostream>
#include <string>

class Personnage
{
public:
    Personnage();               //Constructeur
    float getX() const;
    float getY() const;
    sf::sprite getSprite() const; //récupère le sprite du personnage

    float moveRight();
    float moveLeft();
    float jumpNoMove();
    float jumpMoveRight();
    float jumpMoveLeft();

private:
    //sf::texture m_persoTexture;
    //sf::spirite m_persoSprite;
    float m_X;
    float m_Y;

};

#endif // PERSONNAGE_H_INCLUDED
