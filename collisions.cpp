//
// Created by Karen on 11/5/2023.
//
#include <iostream>
#include "collisions.h"

//Create collision constructor and pass reference to player and obstacle
collisions::collisions(Player* player, obstacles* obstacle) {
  gamePlayer = player;
  gameObstacle = obstacle;
}

//Check for collision
void collisions::check() {
    collides = gamePlayer->getShape()->getGlobalBounds().intersects(gameObstacle->getShape()->getGlobalBounds());
}

//Return true if collision has happened
bool collisions::getCollisionCheck(){
    return collides;
}
