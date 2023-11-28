/**
 * @file Enemy.cpp
 * @brief A subclass of Animate for enemies that harm the player but can be killed
 * @author Emma
 * @bug no known bugs
 */

#include "Enemy.h"

using namespace std;

/**
 * @brief the constructor for an Enemy object
 * @param enemyStart starting position of an enemy's walk cycle
 * @param enemyEnd ending position of an enemy's walk cycle
 * @param levelSize 2d size of the level
 * @param size size of the enemy
 */
Enemy::Enemy(sf::Vector2f enemyStart, sf::Vector2f enemyEnd, sf::Vector2f levelSize, sf::Vector2f size) : Animate(levelSize, size){

    this->enemyStartPosition = enemyStart;
    this->enemyEndPosition = enemyEnd;
    shape->move(enemyStartPosition);
    shape->setFillColor(sf::Color::Magenta);
}

/**
 * @brief controls enemy movement; it moves back and forth between 2 positions
 * @param timeElapsed time since the last frame
 */
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