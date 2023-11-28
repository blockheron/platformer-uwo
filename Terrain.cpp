//
// Created by Liam on 2023-11-11.
//

#include "Terrain.h"

static sf::Texture* texture = new sf::Texture();
static bool texturesCreated = false;

// Terrain constructor
Terrain::Terrain(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(position.x, position.y);
    if (!texturesCreated) {
        texture->loadFromFile("Resources/Images/Smaller-Tiles.png");
        texturesCreated = true;
    }
    shape->setTexture(texture);
}

