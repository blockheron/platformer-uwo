//
// Created by Liam on 2023-10-18.
//

#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(sf::Vector2<unsigned int> windowSize) {
    shape = new sf::RectangleShape(sf::Vector2f(50.f,50.f));
    upperXBound = windowSize.x-shape->getSize().x;
    lowerYBound = windowSize.y-shape->getSize().y;
    shape->move(0, lowerYBound);
}

void Player::Update(int timeElapsed) {
    //left and right motion
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && shape->getPosition().x-speed*timeElapsed > lowerXBound) {
        shape->move(-speed*timeElapsed, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && shape->getPosition().x-speed*timeElapsed < upperXBound) {
        shape->move(speed*timeElapsed, 0);
    }
    //

    //initial jump
    if(!jumped && ay < initialJumpAcceleration && ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))) {
        ay += initialJumpAcceleration;
        jumped = true;
    }
    //midair control (jump higher/delay landing)
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        ay += midJumpAcceleration;
    }

    //change velocity based on acceleration up to some terminal velocity
    if (vy + ay >= terminalVelocity) vy+=ay;
    else vy = terminalVelocity;
    //

    //change acceleration until matching gravity
    if (ay > gravity && ay + gravity > gravity) ay += gravity;
    else if (ay + gravity <= gravity) ay = gravity;
    //

    //change position until you hit the floor
    if (shape->getPosition().y-vy < lowerYBound) {
        shape->move(0, -vy*timeElapsed);
    }
    else {
        jumped = false; //reset jump
        shape->setPosition(shape->getPosition().x, lowerYBound);
    }
    //

}

sf::Shape* Player::getShape() {
    return shape;
}
