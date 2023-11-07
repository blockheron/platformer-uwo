/**
 * @file Goal.cpp
 * @brief
 * @author Jake
 * @bug no known bugs
 */

#include "Goal.h"

Goal::Goal(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(position.x, position.y);
    shape->setFillColor(sf::Color::Green);
}