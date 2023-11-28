/**
 * @file Player.h
 * @brief A class for enemies that harm the player
 * @author Emma
 * @bug no known bugs
 */

#include <iostream>
#include "Enemy.h"

using namespace std;

Enemy::Enemy(sf::Vector2f enemyStart, sf::Vector2f enemyEnd, sf::Vector2f levelSize, sf::Vector2f size) : Animate(levelSize, size){

    this->enemyStartPosition = enemyStart;
    this->enemyEndPosition = enemyEnd;
    shape->move(enemyStartPosition);
    shape->setFillColor(sf::Color::Magenta);
}

void Enemy::move(int timeElapsed) {

    timeElapsed *= simSpeed;

    // move left and right between 2 points automatically
    if (shape->getPosition().x + speed * timeElapsed >= enemyEndPosition.x && !left) {
        left = true;
        shape->move(-speed * timeElapsed, 0);
    }

    else if (shape->getPosition().x - speed * timeElapsed <= enemyStartPosition.x && left) {
        left = false;
        shape->move(speed * timeElapsed, 0);
    }

    else if (shape->getPosition().x + speed * timeElapsed <= enemyEndPosition.x && !left) {
        shape->move(speed * timeElapsed, 0);
    }

    else if (shape->getPosition().x - speed * timeElapsed >= enemyStartPosition.x && left) {
        shape->move(-speed * timeElapsed, 0);
    }

}