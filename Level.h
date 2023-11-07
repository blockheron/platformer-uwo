//
// Created by Liam on 2023-11-04.
// Edited by Karen on 2023/11/05
//

#ifndef PLATFORMER_LEVEL_H
#define PLATFORMER_LEVEL_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"
#include "obstacles.h"
#include "collisions.h"

class Level {
public:
    Level(std::shared_ptr<sf::RenderWindow> window);
private:
    //Initialize needed variables
    sf::Clock gameClock;
    Player* player;
    obstacles* obstacle;
    obstacles* obstacle2;
    obstacles* obstacle3;
    obstacles* obstacle4;
    sf::View* camera;
};



#endif //PLATFORMER_LEVEL_H
