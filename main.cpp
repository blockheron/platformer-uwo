
//
// Created by Liam on 2023-10-18.
// Edited by Karen 11/5/2023.
//


#include <iostream>
#include <SFML/Graphics.hpp>

#include "Level.h"
#include "Menu.h"

using namespace std;
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {

    //https://www.sfml-dev.org/tutorials/2.6/graphics-draw.php

    shared_ptr<sf::RenderWindow> mainWindow(nullptr);

    mainWindow = make_shared<sf::RenderWindow> (sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Platformer");
    sf::View* defaultCamera = new sf::View(sf::FloatRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT));

    while (mainWindow->isOpen())
    {
        mainWindow->setView(*defaultCamera);
        int select = MainMenu(mainWindow);
        /*
         * We will have different selections available in main menu. For now just a play button.
         */
        if (!mainWindow->isOpen()||select == 0) {
            break;
        }
        else if (select == 2) {
            Level* level = new Level(mainWindow);
        }
    }

    return 0;

}
