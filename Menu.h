/**
 * @file Menu.h
 * @brief This class actually just includes any and all menus.(Main Menu, Pause Menu, Settings Menu, Any End Screens/Game Over Screens, Option/Help Menu)
 * @author Jake
 * @bug no known bugs
 */

#ifndef PLATFORMER_MENU_H
#define PLATFORMER_MENU_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "User.h"

int MainMenu(std::shared_ptr<sf::RenderWindow> window);
int GameOver(std::shared_ptr<sf::RenderWindow> window);
int LevelComplete(std::shared_ptr<sf::RenderWindow> window);
int PauseMenu(std::shared_ptr<sf::RenderWindow> window);
int LevelSelectPause(std::shared_ptr<sf::RenderWindow> window);
int LevelSelectMenu(std::shared_ptr<sf::RenderWindow> window);

#endif //PLATFORMER_MENU_H
