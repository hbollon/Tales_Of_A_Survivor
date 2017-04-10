#include "personnage.h"
#include <cmath>
#include "define.h"
using namespace std;

int textureChecker(0);

Personnage::Personnage(): m_X(0.f), m_Y(545.f)
{
    if (!m_persoTexture.loadFromFile("player.png"))
    {
        std::cout << "Error when loading player.png" << std::endl;
    }
    else
    {
        std::cout << "Loading player.png successful" << std::endl;
    }

    if (!m_persoTextureInv.loadFromFile("playerInv.png"))
    {
        std::cout << "Error when loading playerInv.png" << std::endl;
    }
    else
    {
        std::cout << "Loading playerInv.png successful" << std::endl;
    }

    m_persoSprite.setTexture(m_persoTexture);
    m_persoSprite.setPosition(0.f, 545.f);
}

float Personnage::getX() const
{
    return m_X;
}
float Personnage::getY() const
{
    return m_Y;
}

sf::Sprite Personnage::getSprite() const
{
    return m_persoSprite;
}

float Personnage::moveRight()
{
    if (textureChecker != 1)
    {
        textureChecker = 1;
        m_persoSprite.setTexture(m_persoTexture);
    }

    m_persoSprite.move(0.2f, 0.f);
}

float Personnage::moveLeft()
{
    if (textureChecker != 0)
    {
        textureChecker = 0;
        m_persoSprite.setTexture(m_persoTextureInv);
    }
    m_persoSprite.move(-0.2f, 0.f);
}

float Personnage::jumpNoMove()
{

}

float Personnage::jumpMoveRight()
{

}

float Personnage::jumpMoveLeft()
{

}
