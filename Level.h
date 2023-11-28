/**
 * @file Level.h
 * @brief
 * @author Liam, Karen, Jake, Emma
 * @bug no known bugs
 */
#ifndef PLATFORMER_LEVEL_H
#define PLATFORMER_LEVEL_H

#define GRIDSIZE 64

#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"
#include "Obstacle.h"
#include "Terrain.h"
#include "Goal.h"
#include "Enemy.h"

class Level {
public:
    Level(std::shared_ptr<sf::RenderWindow> window, std::string levelName);
    int play(std::shared_ptr<sf::RenderWindow> window);
    bool load(std::string levelName);
private:
    //Initialize needed variables
    sf::Clock gameClock;
    Player* player;
    std::vector<Object*> deathObjects;
    std::vector<Object*> terrain;
    std::vector<Goal*> goals;
    sf::RectangleShape floor;
    sf::Vector2f start;
    sf::Vector2f size;
    //Goal* goal;
    sf::View* camera;
    Enemy* enemy;
    std::vector<Enemy*> enemies;
    std::vector<sf::Vector2f> enemyStartPositions;  // setting points where enemy walks
    std::vector<sf::Vector2f> enemyEndPositions;

};



#endif //PLATFORMER_LEVEL_H
