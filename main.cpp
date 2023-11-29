/**
 * @file main.cpp
 * @brief
 * @author Liam, Karen, Jake
 * @bug no known bugs
 */


#include <iostream>
#include <SFML/Graphics.hpp>

#include "Menu.h"
#include "User.h"

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
        /*
         * We will have different selections available in main menu. For now just a play button.
         */
        if (!mainWindow->isOpen()||select == 0) {
            break;
        }
        else if (select == 2) {
            Level* level = new Level(mainWindow, "level2");
            int gameEvent = level->play(mainWindow);
            if (gameEvent == 0) {
                mainWindow->setView(sf::View(sf::FloatRect(0, 0, mainWindow->getSize().x, mainWindow->getSize().y)));
                select = GameOver(mainWindow);
                if (select == 0) {
                    continue;
                }
                else if (select == 1) {
                    mainWindow->close();
                    break;
                }
            }
            else if (gameEvent == 1) {
                mainWindow->setView(sf::View(sf::FloatRect(0, 0, mainWindow->getSize().x, mainWindow->getSize().y)));
                select = LevelComplete(mainWindow);
                if (select == 0) {
                    continue;
                }
                else if (select == 1) {
                    mainWindow->close();
                    break;
                }
            }
            else if (gameEvent == 2) {
                //open level select menu...
            }
            else if (gameEvent == 3) {
                continue;
            }
            else if (gameEvent == -1) {
                break; //game was closed
            }
        }
    }

    return 0;

}

