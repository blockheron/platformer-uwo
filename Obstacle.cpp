/**
 * @file Obstacle.cpp
 * @brief
 * @author Karen
 * @bug no known bugs
 */

#include "Obstacle.h"

// Obstacles constructor
Obstacle::Obstacle(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(position.x, position.y);
    shape->setFillColor(sf::Color::Red);
}

