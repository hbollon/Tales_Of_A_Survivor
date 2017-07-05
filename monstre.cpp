#include <iostream>
#include <string>
#include <cmath>
#include "define.h"
#include "monstre.h"

using namespace std;

int textureCheckerMonstre(0);

monstre::monstre() : m_X(770), m_Y(474)
{
    if (!m_monstreTexture.loadFromFile("monstre.png"))
    {
        std::cout << "Error when loading monstre.png" << std::endl;
    }
    else
    {
        std::cout << "Loading monstre.png successful" << std::endl;
    }

    if (!m_monstreTextureInv.loadFromFile("monstreInv.png"))
    {
        std::cout << "Error when loading monstre.png" << std::endl;
    }
    else
    {
        std::cout << "Loading monstreInv.png successful" << std::endl;
    }

    m_monstreSprite.setTexture(m_monstreTexture);
    m_monstreSprite.setPosition(m_X, m_Y);

    m_counter = 0;

}

float monstre::getX() const
{
    return m_X;
}

float monstre::getY() const
{
    return m_Y;
}

int monstre::getCounter() const
{
    return m_counter;
}

void monstre::incrementCounter()
{
    m_counter++;
}

void monstre::resetCounter()
{
    m_counter = 0;
}

sf::Sprite monstre::getSprite() const
{
    return m_monstreSprite;
}

void monstre::moveRight()
{
    if (textureCheckerMonstre != 1)
    {
        textureCheckerMonstre = 1;
        m_monstreSprite.setTexture(m_monstreTexture);
    }

    m_monstreSprite.move(0.45f, 0.f);
    m_X = m_monstreSprite.getPosition().x;
    m_Y = m_monstreSprite.getPosition().y;

}

void monstre::moveLeft()
{
    if (textureCheckerMonstre != 0)
    {
        textureCheckerMonstre = 0;
        m_monstreSprite.setTexture(m_monstreTextureInv);
    }
    m_monstreSprite.move(-0.45f, 0.f);
    m_X = m_monstreSprite.getPosition().x;
    m_Y = m_monstreSprite.getPosition().y;
}
