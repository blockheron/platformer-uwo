/**
 * @file Coin.cpp
 * @brief Class for coin as scoring system
 * @author Karen
 * @bug no known bugs
 */

#include "Coin.h"

// Coin constructor
Coin::Coin(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(position.x, position.y);
    shape->setFillColor(sf::Color::Yellow);
}

/*void Coin::collect() {
    shape->setPosition(position.x, position.y);
    shape->setFillColor(sf::Color::Black);
}*/