#include "variablesglobs.h"
#include "render_window.h"

Render_Window::Render_Window()
{
    m_Largeur = l;
    m_Hauteur = h;
    m_fullscreen = fullBox;

    if (fullBox == 1)
    {
        App = new sf::RenderWindow (sf::VideoMode(m_Largeur, m_Hauteur, 32), "Tales of a Survivor", sf::Style::Fullscreen);
    }

    else if (fullBox == 0)
    {
        App = new sf::RenderWindow (sf::VideoMode(m_Largeur, m_Hauteur, 32), "Tales of a Survivor");
    }

    Personnage player;
    sprites Sprite;

    while (App->isOpen())
    {
        sf::Event Event;
        while (App->pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                App->close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            App->close();
        }
        if (sf::Keyboard::isKeyPressed((sf::Keyboard::D)))
        {
            player.moveRight();
        }

        if (sf::Keyboard::isKeyPressed((sf::Keyboard::Q)))
        {
            player.moveLeft();
        }

        if (sf::Keyboard::isKeyPressed((sf::Keyboard::Space)))
        {
            player.jumpNoMove();
        }

        if ((sf::Keyboard::isKeyPressed((sf::Keyboard::D))) && (sf::Keyboard::isKeyPressed((sf::Keyboard::Space))))
        {
            player.jumpMoveRight();
        }

        if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Q))) && (sf::Keyboard::isKeyPressed((sf::Keyboard::Space))))
        {
            player.jumpMoveLeft();
        }

        App->clear();

        App->draw(Sprite.getBackground());
        App->draw(player.getSprite());
        loadMap();

        App->display();
    }
}

void Render_Window::loadMap()
{
    std::ifstream openfile("map.txt");

    sf::Texture tileTexture;
    sf::Sprite tiles;

    sf::Vector2i map[100][100];
    sf::Vector2i loadCounter = sf::Vector2i(0,0);

    if(openfile.is_open())
    {
        std::string tileLocation;
        openfile >> tileLocation;
        tileTexture.loadFromFile(tileLocation);
        tiles.setTexture(tileTexture);

        while(!openfile.eof())
        {
            std::string str;
            openfile >> str;
            char x = str[0], y = str[2];
            if(!isdigit(x) || !isdigit(y))
            {
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
            }
            else
            {
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(x-'0',y-'0');
            }

            if(openfile.peek() == '\n')
            {
                loadCounter.x = 0;
                loadCounter.y++;
            }
            else
            {
                loadCounter.x++;
            }
        }
        loadCounter.y++;
    }

    for(int i=0; i<loadCounter.x; i++)
            {
            for(int j=0; j<loadCounter.y; j++)
                {
                    if(map[i][j].x !=-1 && map[i][j].y !=-1)
                        {
                            tiles.setPosition(i*48, j*48);
                            tiles.setTextureRect(sf::IntRect(map[i][j].x *48,
                            map[i][j].y *48, 48,48));
                            App->draw(tiles);
                        }
                }
            }
}

