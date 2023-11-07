/**
 * @file Goal.cpp
 * @brief
 * @author Jake
 * @bug no known bugs
 */

#include "Goal.h"

/**
 * @brief sets the colour and position of end point
 * @param size
 * @param pos
 */
Goal::Goal(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(position.x, position.y);
    shape->setFillColor(sf::Color::Green);
}