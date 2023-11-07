//
// Created by Jake Choi on 2023-11-07.
//

#include "Goal.h"

Goal::Goal(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(position.x, position.y);
    shape->setFillColor(sf::Color::Green);
}