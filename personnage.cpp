#include "personnage.h"
#include <cmath>
#include "define.h"
using namespace std;

int textureChecker(0);
sf::Vector2f velocity(sf::Vector2f(0, 0));

Personnage::Personnage(): m_X(100.f), m_Y(545.f)
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
    m_persoSprite.setPosition(m_X, m_Y);
}

int Personnage::getX() const
{
    return m_X;
}
int Personnage::getY() const
{
    return m_Y;
}
float Personnage::getTop() const
{
    return top;
}
float Personnage::getBottom() const
{
    return bottom;
}
float Personnage::getLeft() const
{
    return left;
}
float Personnage::getRight() const
{
    return right;
}

sf::IntRect Personnage::getBoundingBox() const
{
    sf::IntRect boundingBox(m_persoSprite.getGlobalBounds());
    return boundingBox;
}

void Personnage::update()
{
    top = m_persoSprite.getPosition().y;
    left = m_persoSprite.getPosition().x;
    right = m_persoSprite.getPosition().x + 30;
    bottom = m_persoSprite.getPosition().y + 76;

    sf::Vector2i topLeft(sf::Vector2i((int)left / 48, (int)top / 48));
    sf::Vector2i topRight(sf::Vector2i((int)right / 48, (int)top / 48));
    sf::Vector2i bottomLeft(sf::Vector2i((int)left / 48, (int)bottom / 48));
    sf::Vector2i bottomRight(sf::Vector2i((int)right / 48, (int)bottom / 48));

    tiles.clear();

    tiles.push_back(topLeft);
    if(std::find(tiles.begin(), tiles.end(), topRight) == tiles.end()) tiles.push_back(topRight);
    if(std::find(tiles.begin(), tiles.end(), bottomLeft) == tiles.end()) tiles.push_back(bottomLeft);
    if(std::find(tiles.begin(), tiles.end(), bottomRight) == tiles.end()) tiles.push_back(bottomRight);
}

void Personnage::colRight()
{
    m_persoSprite.move(-4.5f, 0.f);
}
void Personnage::colLeft()
{
    m_persoSprite.move(4.5f, 0.f);
}

void Personnage::colTop()
{
    m_persoSprite.move(0.f, 0.f);
}

void Personnage::colBottom()
{
    colJump = 1;
}

void Personnage::moveUpdate()
{
    if (colJump != 1)
    m_persoSprite.move(velocity.x, velocity.y);

    if(m_persoSprite.getPosition().y + 68 < groundHeight && colJump != 1)
    {
        velocity.y += gravity;
    }
    else if (colJump != 1)
    {
        m_persoSprite.setPosition(m_persoSprite.getPosition().x, groundHeight - 68);
        velocity.y = 0;
        testJump = 0;
    }
    else if (colJump == 1)
    {
        testJump = 2;
    }
}


sf::Sprite Personnage::getSprite() const
{
    return m_persoSprite;
}

void Personnage::moveRight()
{
    if (textureChecker != 1)
    {
        textureChecker = 1;
        m_persoSprite.setTexture(m_persoTexture);
    }

    m_persoSprite.move(4.5f, 0.f);
    m_X = m_persoSprite.getPosition().x;
    m_Y = m_persoSprite.getPosition().y;
}

void Personnage::moveLeft()
{
    if (textureChecker == 1)
    {
        textureChecker = 0;
        m_persoSprite.setTexture(m_persoTextureInv);
    }

    m_persoSprite.move(-4.5f, 0.f);
    m_X = m_persoSprite.getPosition().x;
    m_Y = m_persoSprite.getPosition().y;
}

void Personnage::jump()
{
    velocity.y = -jumpSpeed;
}

