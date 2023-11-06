//
// Created by Karen on 2023-11-05
//

#include <iostream>
#include "obstacles.h"
#include <SFML/Graphics/Color.hpp>

// Obstacles constructor
obstacles::obstacles() {
    shape = new sf::RectangleShape(sf::Vector2f(60.f,60.f));
}

// Create obstacles at needed positions by passing x and y coordinates of position
void obstacles::show(float xPass, float yPass) {
    shape->setPosition(xPass, yPass);
    shape->setFillColor(sf::Color::Red);
}

//Return obstacle shape
sf::Shape* obstacles::getShape() {
    return shape;
}

//Return obstacle x position
int obstacles::getPositionX(){
    return shape->getPosition().x;
}

// Return obstacle y position
int obstacles::getPositionY(){
    return shape->getPosition().y;
}

