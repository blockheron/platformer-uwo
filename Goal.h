//
// Created by Jake Choi on 2023-11-07.
//

#ifndef _GOAL_H
#define _GOAL_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class Goal : public Object {
public:
    Goal(sf::Vector2f size, sf::Vector2f pos);

private:
    sf::Vector2f position;
};

#endif //_GOAL_H
