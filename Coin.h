/**
 * @file Coin.h
 * @brief Header for Coin.cpp
 * @author Karen
 * @bug no known bugs
 */

#ifndef PLATFORMER_COIN_H
#define PLATFORMER_COIN_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class Coin : public Object {
public:
    Coin(sf::Vector2f size, sf::Vector2f pos);
    //void collect(); // Collect coin

private:
    sf::Vector2f position;
};


#endif //PLATFORMER_COIN_H
