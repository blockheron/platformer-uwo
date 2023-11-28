/**
 * @file Level.h
 * @brief
 * @author Liam, Karen, Jake
 * @bug no known bugs
 */
#ifndef PLATFORMER_LEVEL_H
#define PLATFORMER_LEVEL_H

#define GRIDSIZE 64

#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"
#include "Obstacle.h"
#include "Coin.h"
#include "Score.h"
#include "Terrain.h"
#include "Goal.h"

class Level {
public:
    Level(std::shared_ptr<sf::RenderWindow> window, std::string levelName);
    int play(std::shared_ptr<sf::RenderWindow> window);
    bool load(std::string levelName);

private:
    // Initialize needed variables
    sf::Clock gameClock;
    Player* player;
    std::vector<Object*> deathObjects;
    std::vector<Object*> scoreObjects;
    std::vector<Object*> rewardObjects;
    std::vector<Object*> terrain;
  //  Score* scoring ;
    // sf::Font font;
    std::vector<Goal*> goals;
    sf::RectangleShape floor;
    sf::Vector2f start;
    sf::Vector2f size;
    // sf::Text score;
    // Goal* goal;
    sf::View* camera;
};



#endif //PLATFORMER_LEVEL_H
