/**
 * @file Goal.h
 * @brief
 * @author Jake
 * @bug no known bugs
 */

#ifndef PLATFORMER_GOAL_H
#define PLATFORMER_GOAL_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class Goal : public Object {
public:
    /**
     * @brief Goal constructor
     * @param size
     * @param pos
     */
    Goal(sf::Vector2f size, sf::Vector2f pos);

private:
    /**
     * @brief position variable
     */
    sf::Vector2f position;
};

#endif //PLATFORMER_GOAL_H
