/**
 * @file Level.h
 * @brief
 * @author Liam, Karen, Jake
 * @bug no known bugs
 */
#ifndef PLATFORMER_LEVEL_H
#define PLATFORMER_LEVEL_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"
#include "Obstacle.h"
#include "Goal.h"

class Level {
public:
    Level(std::shared_ptr<sf::RenderWindow> window);
    int play(std::shared_ptr<sf::RenderWindow> window);
private:
    //Initialize needed variables
    sf::Clock gameClock;
    Player* player;
    std::vector<Object*> deathObjects;
    Goal* goal;
    sf::View* camera;
};



#endif //PLATFORMER_LEVEL_H
