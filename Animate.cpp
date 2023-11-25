/**
 * @file Animate.cpp
 * @brief
 * @author Emma, Jake
 * @bug no known bugs
 */

#include <iostream>
#include "Animate.h"

using namespace std;

Animate::Animate(sf::Vector2f levelSize, sf::Vector2f size) : Object(size) {
    lowerYBound = levelSize.y-shape->getSize().y;
    shape->move(0, lowerYBound);
}

void Animate::Update(int timeElapsed) {

    prevPosition = shape->getPosition();
    move(timeElapsed);

}

void Animate::move(int timeElapsed) {

    timeElapsed *= simSpeed;

    //left and right motion
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && shape->getPosition().x - speed * timeElapsed > lowerXBound) {
//        shape->move(-speed * timeElapsed, 0);
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//        shape->move(speed * timeElapsed, 0);
//    }
    //

    //initial jump
//    if (!jumped &&
//        ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))) {
//        vy = initialJumpVelocity;
//        jumped = true;
//    }

        //midair control (jump higher/delay landing)
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
//        ay = midJumpAcceleration + gravity;
//    } else ay = gravity;

    //change velocity based on acceleration up to some terminal velocity
//    if (vy + ay * timeElapsed >= terminalVelocity) vy += ay * timeElapsed;
//    else vy = terminalVelocity;
    //

    //change position until you hit the floor
//    if (shape->getPosition().y - vy < lowerYBound) {
//        shape->move(0, -vy * timeElapsed);
//    } else {
//        jumped = false; //reset jump
//        shape->setPosition(shape->getPosition().x, lowerYBound);
//    }
    //

}

void Animate::collided(Object* terrain) {

    float xdif, ydif;

    if (prevPosition.x < shape->getPosition().x)
        xdif = terrain->getShape()->getPosition().x - (shape->getPosition().x + shape->getSize().x); //difference from left of terrain to right of player
    else xdif = terrain->getShape()->getPosition().x + terrain->getSize().x - shape->getPosition().x; //difference from right of terrain to left of player

    if (prevPosition.y < shape->getPosition().y)
        ydif = terrain->getShape()->getPosition().y - (shape->getPosition().y + shape->getSize().y); //difference from top of terrain to bottom of player
    else ydif = terrain->getShape()->getPosition().y + terrain->getSize().y - shape->getPosition().y; //difference from bottom of terrain to top of player

    //move the player as little as possible (towards its last position)
    if (abs(xdif) < abs(ydif))
        shape->move(xdif,0);
    else {
        shape->move(0, ydif);
        vy = 0; //set the y velocity to 0 if there's a mostly vertical collision
        if (ydif<0) jumped = false; //allow the player to jump if it's on top of a block
    }

}