/**
 * @file Goal.cpp
 * @brief
 * @author Jake
 * @bug no known bugs
 */

#include "Goal.h"

/**
 * @brief creates a new goal/endpoint
 * @param size the size of the goal to be created
 * @param pos the position of the goal to be created
 */
Goal::Goal(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(position.x, position.y);
    shape->setFillColor(sf::Color::Green);
}