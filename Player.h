//
// Created by Liam on 2023-10-18.
// Edited by Karen 2023/11/06
// Edited by Jake 2023/11/06
//

#ifndef PLATFORMER_PLAYER_H
#define PLATFORMER_PLAYER_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class Player : public Object {
public:
    Player(sf::Vector2<unsigned int> windowSize, sf::Vector2f size);
    void Update(int timeElapsed);
    void setToMove(bool val);
   // bool getToMove();

private:
    const float speed = 0.002;
    const unsigned int lowerXBound = 0; //temporary
    unsigned int lowerYBound; //temporary
    const float gravity = -0.0000002;
    const float initialJumpVelocity = 0.008;
    const float midJumpAcceleration = 0.0000001;
    const float terminalVelocity = -0.1;
    const float simSpeed = 0.25;
    float vy = 0;
    float ay = 0;
    bool jumped = false;
    bool toMove=true;
};


#endif //PLATFORMER_PLAYER_H
