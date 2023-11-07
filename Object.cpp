/**
 * @file Object.cpp
 * @brief
 * @author Jake
 * @bug no known bugs
 */

#include <iostream>
#include "Object.h"

using namespace std;

Object::Object(sf::Vector2f size) {
    shape = new sf::RectangleShape(size);
}

sf::Shape* Object::getShape() {
    return shape;
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


