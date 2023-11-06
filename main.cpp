
//
// Created by Liam on 2023-10-18.
// Edited by Karen 11/5/2023.
//


#include <iostream>
#include <SFML/Graphics.hpp>

#include "Level.h"
#include "Interface.h"

using namespace std;

int main() {

    //https://www.sfml-dev.org/tutorials/2.6/graphics-draw.php

    shared_ptr<sf::RenderWindow> mainWindow(nullptr);

    mainWindow = make_shared<sf::RenderWindow> (sf::VideoMode(800, 600), "Main Menu");

    while (mainWindow->isOpen())
    {
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
