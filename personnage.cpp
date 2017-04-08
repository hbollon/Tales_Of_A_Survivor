#include "personnage.h"
using namespace std;

Personnage::Personnage() m_X(0.f), m_Y(0.f)
    //sf::texture m_persoTexture; //Texture du Personnage
    if (!m_persoTexture.loadFromFile("sprites/player.png"))
    {
        std::cout << "Error loading personnage.png" << std::endl;
    }
    else
    {
        std::cout << "Loarding personnage.png successful" << std::endl;
    }

    spiritPerso.setTexture(m_persoTexture);
    spritePerso.setPosition(0.f, 0.f),
}

Personnage::getX() const
{
    return m_X;
}
Personnage::getY() const
{
    return m_Y;
}

//sf:sprite getSprite() const
{
    return persoSprite;
}

Personnage::moveRight()
{
    spritePerso.move(5.f, 0.f)
}

Personnage::moveLeft()
{
    spritePerso.move(-5.f, 0.f)
}

Personnage::jumpNoMove()
{

}

Personnage::jumpMoveRight()
{

}

Personnage::jumpMoveLeft()
{

}
