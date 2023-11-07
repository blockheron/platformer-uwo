//
// Created by Liam on 2023-10-18.
// Edited by Karen 2023/11/06
//

#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(sf::Vector2<unsigned int> windowSize) {
    shape = new sf::RectangleShape(sf::Vector2f(50.f,50.f));
    lowerYBound = windowSize.y-shape->getSize().y;
    shape->move(0, lowerYBound);
}

void Player::Update(int timeElapsed) {
    timeElapsed *= simSpeed;
    //Check if player has collided with obstacle
    if (toMove) {
        //left and right motion
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && shape->getPosition().x - speed * timeElapsed > lowerXBound) {
            shape->move(-speed * timeElapsed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
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

        //change acceleration until matching gravity
        //if (ay > gravity && ay + gravity > gravity) ay += gravity;
        //else if (ay + gravity <= gravity) ay = gravity;
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

}

sf::Shape* Player::getShape() {
    return shape;
}

// Return Player x position
int Player::getPositionX(){
    return shape->getPosition().x;
}

// Return Player y position
int Player::getPositionY(){
    return shape->getPosition().y;
}

//Set boolean to indicate whether player can move(has not encountered obstacle)
void Player::setToMove(bool val){
    toMove = val;
}

/*
//Get boolean to indicate whether player can move(has not encountered obstacle)
bool Player::getToMove(){
    return toMove;
}
 */