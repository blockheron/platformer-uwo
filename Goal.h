//
// Created by Jake Choi on 2023-11-07.
//

#ifndef PLATFORMER_GOAL_H
#define PLATFORMER_GOAL_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class Goal : public Object {
public:
    Goal(sf::Vector2f size, sf::Vector2f pos);

private:
    sf::Vector2f position;
};

#endif //PLATFORMER_GOAL_H
