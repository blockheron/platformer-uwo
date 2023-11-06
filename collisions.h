//
// Created by Karen on 11/5/2023.
//

#ifndef PLATFORMER_COLLISIONS_H
#define PLATFORMER_COLLISIONS_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "obstacles.h"
#include "Level.h"

class collisions {
public:
    //Initialize needed functions
    collisions(Player* player, obstacles* obstacle);
    void check();
    bool getCollisionCheck();
    Player* gamePlayer;
    obstacles* gameObstacle;

private:
    //Initialize needed variable
    bool collides = false;
};

#endif //PLATFORMER_COLLISIONS_H

