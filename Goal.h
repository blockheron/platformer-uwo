/**
 * @file Goal.h
 * @brief the header file for Goal.cpp
 * @author Jake
 * @bug no known bugs
 */

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
