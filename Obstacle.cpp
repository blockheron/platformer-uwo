/**
 * @file Obstacle.cpp
 * @brief
 * @author Karen
 * @bug no known bugs
 */

#include "Obstacle.h"

/**
 * @brief Constructor for the Obstacle class
 * @param size The size of the Obstacle to create
 * @param pos The position to create the Obstacle at
 */
Obstacle::Obstacle(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(position.x, position.y);
    shape->setFillColor(sf::Color::Red);
}

