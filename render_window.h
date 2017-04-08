#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "sprites.h"
#include "variablesglobs.h"

class Render_Window
{

public:
    Render_Window();
    void loadMap();

private:
    sf::Sprite tiles;
    sf::Vector2i map[100][100];
    sf::Vector2i loadcounter;
    sf::RenderWindow *App;
    int m_Hauteur;
    int m_Largeur;
    bool m_fullscreen = 0;

};

#endif // RENDER_WINDOW_H
