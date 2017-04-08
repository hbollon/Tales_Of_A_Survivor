#include "sprites.h"

sprites::sprites()
{
    loadTextures();
    createSprites();
}

void sprites::loadTextures()
{
    background;
    if (!background.loadFromFile("bkg.jpg"))
    {
        QMessageBox::critical(this, "Erreur", "Impossible de charger la texture bkg.jpg<br />Veuillez verifier la présence de ce fichier ou contactez un administrateur");
        system("PAUSE");
    }

}

void sprites::createSprites()
{
    spriteBackground.setTexture(background);
}

sf::Sprite sprites::getBackground()
{
    return spriteBackground;
}

