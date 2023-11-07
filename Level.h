//
// Created by Liam on 2023-11-04.
// Edited by Karen on 2023/11/05
// Edited by Jake 2023/11/06
//

#ifndef PLATFORMER_LEVEL_H
#define PLATFORMER_LEVEL_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"
#include "Obstacle.h"

class Level {
public:
    Level(std::shared_ptr<sf::RenderWindow> window);
private:
    //Initialize needed variables
    sf::Clock gameClock;
    Player* player;
    Obstacle* obstacle;
    Obstacle* obstacle2;
    Obstacle* obstacle3;
    Obstacle* obstacle4;
    sf::View* camera;
};



#endif //PLATFORMER_LEVEL_H
