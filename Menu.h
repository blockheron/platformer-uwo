/**
 * @file Menu.h
 * @brief This class actually just includes any and all menus.(Main Menu, Pause Menu, Settings Menu, Any End Screens/Game Over Screens, Option/Help Menu)
 * @author Jake
 * @bug no known bugs
 */

#ifndef PLATFORMER_MENU_H
#define PLATFORMER_MENU_H

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600

#include <SFML/Graphics.hpp>
#include <memory>

int MainMenu(std::shared_ptr<sf::RenderWindow> window);
int GameOver(std::shared_ptr<sf::RenderWindow> window);
int LevelComplete(std::shared_ptr<sf::RenderWindow> window);

#endif //PLATFORMER_MENU_H
