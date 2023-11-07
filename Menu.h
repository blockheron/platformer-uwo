//
// Created by Jake Choi on 2023-11-04.
// Note: I'm thinking this class actually just includes any and all menus.
// Main Menu, Pause Menu, Settings Menu, Any End Screens/Game Over Screens, Option/Help Menu, etc.
//

#ifndef PLATFORMER_MENU_H
#define PLATFORMER_MENU_H

#include <SFML/Graphics.hpp>
#include <memory>

int MainMenu(std::shared_ptr<sf::RenderWindow> window);
int GameOver(std::shared_ptr<sf::RenderWindow> window);
int LevelComplete(std::shared_ptr<sf::RenderWindow> window);

#endif //PLATFORMER_MENU_H