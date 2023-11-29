
/**
 * @file Coin.cpp
 * @brief Class for coin as scoring system
 * @author Karen
 * @bug no known bugs
 */
#include "Coin.h"

static sf::Texture* texture = new sf::Texture();
static bool texturesCreated = false;

// Coin constructor
Coin::Coin(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    //load textures
    if (!texturesCreated) {
        texture->loadFromFile("Resources/Images/coin.png");
        texturesCreated = true;
    }
    shape->setTexture(texture);
    //

    shape->setPosition(position.x, position.y);
    //shape->setFillColor(sf::Color::Yellow);
}
/*void Coin::collect() {
    shape->setPosition(position.x, position.y);
    shape->setFillColor(sf::Color::Black);
}*/
