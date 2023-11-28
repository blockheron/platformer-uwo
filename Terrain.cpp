//
// Created by Liam on 2023-11-11.
//

#include "Terrain.h"

static sf::Texture* texture = new sf::Texture();

// Terrain constructor
Terrain::Terrain(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(position.x, position.y);
    if (texture != nullptr);
        texture->loadFromFile("Resources/Images/Smaller-Tiles.png");
    shape->setTexture(texture);
}

