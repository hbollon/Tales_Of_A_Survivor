#include "variablesglobs.h"
#include "render_window.h"

Render_Window::Render_Window() //Création fenetre de jeu et boucle
{
    m_Largeur = l;
    m_Hauteur = h;           //Récupération des paramètres, ces paramètres sont réglé dans la fenetre Setting
    m_fullscreen = fullBox;

    int direction = 0;

    loadMusic();
    loadMap();          //Appel des fonctions de chargement
    loadCollision();

    music.play();
    music.setVolume(musicVolEtat);      //Fonction pour la musique
    music.setLoop(true);

    //Création de la fenètre

    if (fullBox == 1) //Mode plein écran
    {
        App = new sf::RenderWindow (sf::VideoMode(m_Largeur, m_Hauteur, 32), "Tales of a Survivor", sf::Style::Fullscreen);
    }

    else if (fullBox == 0) //Mode fenetré
    {
        App = new sf::RenderWindow (sf::VideoMode(m_Largeur, m_Hauteur, 32), "Tales of a Survivor");
    }

    App->setFramerateLimit(60); //Limite de la fenetre à 60fps
    App->setKeyRepeatEnabled(false);  //Désactive la répétition des évènements "KeyPressed" (ne pas confondre avec "isKeyPressed")

    Personnage player;
    monstre monster;        //Créations de nos objets
    sprites Sprite;

    sf::Vector2f center(player.getX(), player.getY() - 185);
    sf::Vector2f size(l, h);                                    //Création et paramétrage de la vue
    sf::View view(center, size);

    while (App->isOpen()) //Boucle de jeu
    {
        sf::Event Event;        //Crétion d'un évènement

        while (App->pollEvent(Event))  //Boucle de récupération de l'event
        {
            if (Event.type == sf::Event::Closed)
            {
                music.stop();
                App->close();
            }

            if (Event.type == sf::Event::KeyPressed)
            {
                if (Event.key.code == sf::Keyboard::Escape)
                {
                    music.stop();
                    App->close();
                }
            }

            if (Event.type == sf::Event::KeyPressed)
            {
                if (Event.key.code == sf::Keyboard::Space)
                {
                    if (testJump == 0)
                    {
                        player.jump();
                        direction = 3;
                        testJump = 1;
                    }
                    else if (testJump == 2)
                    {
                        player.jump();
                        direction = 3;
                        colJump = 0;
                        testJump = 1;
                    }
                }
            }
        }

        player.moveUpdate();    //Mise a jour de la position du personnage (utilisé pour le saut)

        if (sf::Keyboard::isKeyPressed((sf::Keyboard::D)))
        {
            if (testJump == 0)
            {
                direction = 1;
            }
            player.moveRight();
            view.setCenter(player.getX(), 360); //Centrage de la vue
            App->setView(view);
            Sprite.moveRight();
        }

        if (sf::Keyboard::isKeyPressed((sf::Keyboard::Q)))
        {
            if (testJump == 0)
            {
                direction = 2;
            }
            player.moveLeft();
            view.setCenter(player.getX(), 360); //Centrage de la vue
            App->setView(view);
            Sprite.moveLeft();
        }

        if ((sf::Keyboard::isKeyPressed((sf::Keyboard::D))) && (sf::Keyboard::isKeyPressed((sf::Keyboard::Space))))
        {
        }

        if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Q))) && (sf::Keyboard::isKeyPressed((sf::Keyboard::Space))))
        {
        }

        player.update();    //Récupération de la position du personnage (pour les collisions)

        for(int i = 0; i < player.tiles.size(); i++)    //Boucle de test collision
        {
            if(collision[player.tiles[i].y][player.tiles[i].x] == 1) //Si il y a collision
            {
                switch (direction)
                {
                case (1):
                        player.colRight();
                        Sprite.colPlayerRight();
                    break;

               case (2):
                        player.colLeft();
                        Sprite.colPlayerLeft();
                    break;

                case (3):
                        player.colBottom();
                    break;

                case (4):
                    break;

                default:
                    break;
                }
            }
            else
            {
                colJump = 0;
            }
        }

        //Déplacement monstre

        if (monster.getCounter() <= 230)
        {
            monster.moveRight();
            monster.incrementCounter();
        }
        else if (monster.getCounter() >=231 && monster.getCounter() != 461)
        {
            monster.moveLeft();
            monster.incrementCounter();
        }
        else if (monster.getCounter() == 461)
        {
            monster.resetCounter();
        }

        App->clear();

        App->draw(Sprite.getBackground());
        App->draw(player.getSprite());
        App->draw(monster.getSprite());

        for(int i=0; i<map.size(); i++)
                {
                for(int j=0; j<map[i].size(); j++)
                    {
                        if(map[i][j].x !=-1 && map[i][j].y !=-1)
                            {
                                tiles.setPosition(j*48, i*48);
                                tiles.setTextureRect(sf::IntRect(map[i][j].x *48, map[i][j].y *48, 48, 48));
                                App->draw(tiles);
                            }
                    }
                }

        view.setCenter(player.getX(), 360);
        App->setView(view);

        App->display();
    }
}

void Render_Window::loadMap() //Chargement de la map
{
    std::ifstream openfile(mapSelected);
    std::vector<sf::Vector2i> tempMap;
    map.clear();

    if(openfile.is_open())
    {
        std::string tileLocation;
        openfile >> tileLocation;
        tileTexture.loadFromFile(tileLocation);
        tiles.setTexture(tileTexture);

        while(!openfile.eof())
        {
            std::string str, value;
            std::getline(openfile, str);
            std::stringstream stream(str);

            while(std::getline(stream, value, ' '))
            {
                if(value.length() > 0)
                {
                    std::string xx = value.substr(0, value.find(','));
                    std::string yy = value.substr(value.find(',') + 1);

                    int x, y, i, j;

                    for(i = 0; i < xx.length(); i++)
                    {
                        if(!isdigit(xx[i]))
                            break;
                    }

                    for(j = 0; j < yy.length(); j++)
                    {
                        if(!isdigit(yy[j]))
                            break;
                    }

                    x = (i == xx.length()) ? atoi(xx.c_str()) : -1;
                    y = (j == yy.length()) ? atoi(yy.c_str()) : -1;

                    tempMap.push_back(sf::Vector2i(x, y));
                 }
            }
            if(tempMap.size() > 0)
            {
                map.push_back(tempMap);
                tempMap.clear();
            }
        }
     }
}

void Render_Window::loadCollision() //Chargement de la map de collision
{
    std::ifstream openfile(mapColSelected);
    std::vector<int> tempMap;
    collision.clear();

    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            std::string str, value;
            std::getline(openfile, str);
            std::stringstream stream(str);

            while(std::getline(stream, value, ' '))
            {
                if(value.length() > 0)
                {
                    int a = atoi(value.c_str());
                    tempMap.push_back(a);
                }
            }
                collision.push_back(tempMap);
                tempMap.clear();
        }
     }
}

int Render_Window::loadMusic() //Selection de la musique en fonction du niveau
{
    switch (levelSelected)
    {

    case 1:
        if (!music.openFromFile("Aeon_Metropolis.wav"))
            return -1;

        break;

    default:
        break;

    }

    return 0;
}
