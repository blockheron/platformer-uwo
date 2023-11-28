/**
 * @file Player.h
 * @brief A class for moving, animate objects
 * @author Liam, Karen, Jake, Emma
 * @bug no known bugs
 */

#ifndef PLATFORMER_PLAYER_H
#define PLATFORMER_PLAYER_H

#include "Animate.h"
#include <SFML/Graphics.hpp>

/**
 * @brief an Player object's methods and instances. It also inherits from Animate and Object
 */
class Player : public Animate {
public:
    using Animate::Animate;
    Player(sf::Vector2f start, sf::Vector2f levelSize, sf::Vector2f size);

private:
    void move(int timeElapsed) override;   // made private as it's inherited from Animate
};


#endif //PLATFORMER_PLAYER_H
