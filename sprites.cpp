#include "sprites.h"

sprites::sprites()
{
    loadTextures();
}

void sprites::loadTextures()
{
    sf::Texture dirt;
    if (!dirt.loadFromFile("dirt.png"))
    {
        QMessageBox::critical(this, "Erreur", "Impossible de charger la texture dirt.png<br />Veuillez verifier la présence de ce fichier ou contactez un administrateur");
        system("PAUSE");
    }

    sf::Texture grass;
    if (!grass.loadFromFile("grass.png"))
    {
        QMessageBox::critical(this, "Erreur", "Impossible de charger la texture grass.png<br />Veuillez verifier la présence de ce fichier ou contactez un administrateur");
        system("PAUSE");
    }
}

void sprites::init()
{
    sprites();
}
