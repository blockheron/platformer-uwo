//
// Created by Liam on 2023-11-11.
//

#ifndef PLATFORMER_TERRAIN_H
#define PLATFORMER_TERRAIN_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class Terrain : public Object {
public:
    Terrain(sf::Vector2f size, sf::Vector2f pos);

private:
    sf::Vector2f position;
};

#endif //PLATFORMER_TERRAIN_H
