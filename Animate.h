/**
 * @file Animate.cpp
 * @brief
 * @author Emma, Jake
 * @bug no known bugs
 */

#ifndef PLATFORMER_ANIMATE_H
#define PLATFORMER_ANIMATE_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class Animate : public Object {
public:
    Animate(sf::Vector2f levelSize, sf::Vector2f size);
    void Update(int timeElapsed);
    void collided(Object* terrain); //assumed to be terrain for now
    virtual void move(int timeElapsed); // made virtual and public so children can access this
    virtual sf::Vector2<float> getPrevPosition();

//private:
//    const float speed = 0.002;
//    const unsigned int lowerXBound = 0; //temporary
//    unsigned int lowerYBound; //temporary
//    const float gravity = -0.0000002;
//    const float initialJumpVelocity = 0.008;
//    const float midJumpAcceleration = 0.0000001;
//    const float terminalVelocity = -0.1;
//    const float simSpeed = 0.25;
//    float vy = 0;
//    float ay = 0;
//    bool jumped = false;
//    sf::Vector2<float> prevPosition;

protected:
    const float speed = 0.002;
    const unsigned int lowerXBound = 0;
    unsigned int upperXBound;
    unsigned int lowerYBound;
    const float gravity = -0.0000002;
    const float initialJumpVelocity = 0.008;
    const float midJumpAcceleration = 0.0000001;
    const float terminalVelocity = -0.1;
    const float simSpeed = 0.25;
    float vy = 0;
    float ay = 0;
    bool jumped = false;
    sf::Vector2<float> prevPosition;
};


#endif //PLATFORMER_ANIMATE_H
