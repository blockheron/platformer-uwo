/**
 * @file Player.cpp
 * @brief
 * @author Liam, Karen, Jake
 * @bug no known bugs
 */

#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(sf::Vector2f start, sf::Vector2f levelSize, sf::Vector2f size) : Animate(levelSize, size) {

    shape->move(start);

}

void Player::move(int timeElapsed) {

    timeElapsed *= simSpeed;

    //left and right motion
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && shape->getPosition().x - speed * timeElapsed > lowerXBound) {
        shape->move(-speed * timeElapsed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && shape->getPosition().x + speed * timeElapsed < upperXBound) {
        shape->move(speed * timeElapsed, 0);
    }
    //

    //initial jump
    if (!jumped &&
        ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))) {
        vy = initialJumpVelocity;
        jumped = true;
    }

        //midair control (jump higher/delay landing)
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        ay = midJumpAcceleration + gravity;
    } else ay = gravity;

    //change velocity based on acceleration up to some terminal velocity
    if (vy + ay * timeElapsed >= terminalVelocity) vy += ay * timeElapsed;
    else vy = terminalVelocity;
    //

    //change position until you hit the floor
    if (shape->getPosition().y - vy < lowerYBound) {
        shape->move(0, -vy * timeElapsed);
    } else {
        jumped = false; //reset jump
        shape->setPosition(shape->getPosition().x, lowerYBound);
    }
    //

}