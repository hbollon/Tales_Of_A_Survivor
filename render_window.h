#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "personnage.h"
#include "monstre.h"
#include "define.h"
#include "sprites.h"
#include "variablesglobs.h"

class Render_Window
{

public:
    Render_Window();
    void loadMap();
    void loadCollision();
    int loadMusic();

private:
    sf::Texture tileTexture;
    sf::Sprite tiles;
    std::vector <std::vector<sf::Vector2i>> map;
    std::vector <std::vector<int>> collision;
    sf::RenderWindow *App;
    sf::Music music;
    int m_Hauteur;
    int m_Largeur;
    bool m_fullscreen = 0;

};

#endif // RENDER_WINDOW_H
