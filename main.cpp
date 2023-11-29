/**
 * @file main.cpp
 * @brief
 * @author Liam, Karen, Jake
 * @bug no known bugs
 */


#include <iostream>
#include <SFML/Graphics.hpp>

#include "Menu.h"

using namespace std;

int main() {

    //https://www.sfml-dev.org/tutorials/2.6/graphics-draw.php

    shared_ptr<sf::RenderWindow> mainWindow(nullptr);

    mainWindow = make_shared<sf::RenderWindow> (sf::VideoMode::getFullscreenModes()[0], "Platformer", sf::Style::Fullscreen);

    int select;

    while (mainWindow->isOpen())
    {
        mainWindow->setView(sf::View(sf::FloatRect(0, 0, mainWindow->getSize().x, mainWindow->getSize().y)));
        select = MainMenu(mainWindow);
        if (!mainWindow->isOpen()||select == 0) {
            break;
        }
        else if (select == 1) {
            int selectedLevel = LevelSelectMenu(mainWindow);
            if (selectedLevel < 0) {
                mainWindow->close();
                break;
            }
        }
    }

    return 0;

}

