#include "variablesglobs.h"
#include "render_window.h"

Render_Window::Render_Window()
{
    m_Largeur = l;
    m_Hauteur = h;
    m_fullscreen = fullBox;

    sf::RenderWindow *App;

    if (fullBox == 1)
    {
        App = new sf::RenderWindow (sf::VideoMode(m_Largeur, m_Hauteur, 32), "Tales of a Survivor", sf::Style::Fullscreen);
    }

    else if (fullBox == 0)
    {
        App = new sf::RenderWindow (sf::VideoMode(m_Largeur, m_Hauteur, 32), "Tales of a Survivor");
    }

    sprites::init();

    while (App->isOpen())
    {
        sf::Event Event;
        while (App->pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                App->close();
        }

        App->clear();

        App->display();
    }
}

