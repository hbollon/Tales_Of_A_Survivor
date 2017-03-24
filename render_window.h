//Inutile pour le moment

#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "variablesglobs.h"

class Render_Window
{

public:
    Render_Window();

private:
    int m_Hauteur;
    int m_Largeur;
    bool m_fullscreen = 0;


};

#endif // RENDER_WINDOW_H
