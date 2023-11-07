//
// Created by Karen on 2023-11-05
// Edited by Jake 2023/11/06
//

#include <iostream>
#include "Obstacle.h"
#include <SFML/Graphics/Color.hpp>

// Obstacles constructor
Obstacle::Obstacle(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(position.x, position.y);
    shape->setFillColor(sf::Color::Red);
}

