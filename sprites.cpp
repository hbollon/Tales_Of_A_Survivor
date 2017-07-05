#include "sprites.h"

sf::Vector2f velocityBkg(sf::Vector2f(0, 0));

sprites::sprites()
{
    loadTextures();
    createSprites();

    spriteBackground.setPosition(-540.f, 0.f);
    m_X = spriteBackground.getPosition().x;
    m_Y = spriteBackground.getPosition().y;


}

void sprites::loadTextures()
{
    if (!background.loadFromFile("bkg.jpg"))
    {
        QMessageBox::critical(this, "Erreur", "Impossible de charger la texture bkg.jpg<br />Veuillez verifier la présence de ce fichier ou contactez un administrateur");
        system("PAUSE");
    }

}

void sprites::colPlayerRight()
{
    spriteBackground.setPosition(m_X-4.5f, 0.f);
    m_X = spriteBackground.getPosition().x;
}
void sprites::colPlayerLeft()
{
    spriteBackground.setPosition(m_X+4.5f, 0.f);
    m_X = spriteBackground.getPosition().x;
}

void sprites::createSprites()
{
    spriteBackground.setTexture(background);
}

sf::Sprite sprites::getBackground()
{
    return spriteBackground;
}

void sprites::moveRight()
{
    spriteBackground.setPosition(m_X+4.5f, 0.f);
    m_X = spriteBackground.getPosition().x;
}

void sprites::moveLeft()
{
    spriteBackground.setPosition(m_X-4.5f, 0.f);
    m_X = spriteBackground.getPosition().x;
}

void sprites::moveUpdate()
{
    spriteBackground.move(velocityBkg.x, velocityBkg.y);

    if(spriteBackground.getPosition().y + 1280 < groundHeight)
    {
        velocityBkg.y += gravity;
    }
    else
    {
        spriteBackground.setPosition(spriteBackground.getPosition().x, groundHeight - 1280);
        velocityBkg.y = 0;
    }
}
void sprites::jump()
{
    velocityBkg.y = -jumpSpeed;
}

