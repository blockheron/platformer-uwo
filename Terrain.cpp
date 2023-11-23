//
// Created by Liam on 2023-11-11.
//

#include "Terrain.h"

// Terrain constructor
Terrain::Terrain(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(position.x, position.y);
    shape->setFillColor(sf::Color::White);
}