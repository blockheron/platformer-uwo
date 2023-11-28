/**
 * @file Object.cpp
 * @brief
 * @author Jake, Karen
 * @bug no known bugs
 */

#include <iostream>
#include "Object.h"

using namespace std;

Object::Object(sf::Vector2f  size) {
    shape = new sf::RectangleShape(size);
}

sf::Shape* Object::getShape() {
    return shape;
}

sf::Vector2f Object::getSize() {
    return shape->getSize();
}

int Object::getPositionX() {
    return shape->getPosition().x;
}

int Object::getPositionY() {
    return shape->getPosition().y;
}

bool Object::collides(Object* otherObject) {
    return shape->getGlobalBounds().intersects(otherObject->getShape()->getGlobalBounds());
}


void Object::collect() {
   // shape->setFillColor(sf::Color::Black);
    shape->setSize(sf::Vector2f(0, 0));
}
