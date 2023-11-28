/**
 * @file Obstacle.h
 * @brief
 * @author Karen, Jake
 * @bug no known bugs
 */

#ifndef PLATFORMER_OBSTACLE_H
#define PLATFORMER_OBSTACLE_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class Obstacle : public Object {
public:
    Obstacle(sf::Vector2f size, sf::Vector2f pos);

private:
    sf::Vector2f position;
};


#endif //PLATFORMER_OBSTACLE_H
