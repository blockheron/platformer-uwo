//
// Created by Liam on 2023-10-18.
//

#include "Player.h"

using namespace std;

Player::Player() {
    shape = new sf::RectangleShape(sf::Vector2f(50.f,50.f));
}

void Player::Update(int timeElapsed) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        shape->move(-speed*timeElapsed, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        shape->move(speed*timeElapsed, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        shape->move(0, -speed*timeElapsed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        shape->move(0, speed*timeElapsed);
    }
}

sf::Shape* Player::getShape() {
    return shape;
}
