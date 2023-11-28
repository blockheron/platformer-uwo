/**
 * @file Object.h
 * @brief
 * @author Jake, Karen
 * @bug no known bugs
 */

/**
 * Note for future: May create two other object classes that inherit from object.
 * It might be useful to have "animate" vs "inanimate" objects that so that animate
 * objects can check health or have a health specific to them, while inanimate objects don't.
 * We could have Players/other animate objects just inherit from two different classes as well.
 */

#ifndef PLATFORMER_OBJECT_H
#define PLATFORMER_OBJECT_H

#include <SFML/Graphics.hpp>

class Object {
public:
    Object(sf::Vector2f size);
    sf::Shape* getShape();
    sf::Vector2f getSize();
    int getPositionX();
    int getPositionY();
    bool collides(Object* otherObject);
    void collect();

protected:
    sf::RectangleShape* shape;
};

#endif //PLATFORMER_OBJECT_H
