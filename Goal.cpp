/**
 * @file Goal.cpp
 * @brief
 * @author Jake, Karen
 * @bug no known bugs
 */

#include "Goal.h"

static sf::Texture* texture = new sf::Texture();
static bool texturesCreated = false;

/**
 * @brief sets the colour and position of end point
 * @param size
 * @param pos
 */
Goal::Goal(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    //load textures
    if (!texturesCreated) {
        texture->loadFromFile("Resources/Images/door.png");
        texturesCreated = true;
    }

    shape->setTexture(texture);
    shape->setPosition(position.x, position.y);
    //shape->setFillColor(sf::Color::Green);
}