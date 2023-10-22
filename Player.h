//
// Created by Liam on 2023-10-18.
//

#ifndef PLATFORMER_PLAYER_H
#define PLATFORMER_PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(sf::Vector2<unsigned int> windowSize);
    void Update(int timeElapsed);
    sf::Shape* getShape();
private:
    sf::RectangleShape* shape;
    const float speed = 0.0005;
    const unsigned int lowerXBound = 0; //temporary
    unsigned int upperXBound; //temporary
    unsigned int lowerYBound; //temporary
    const float gravity = -0.000002;
    const float initialJumpAcceleration = 0.00003;
    const float midJumpAcceleration = 0.0000005;
    const float terminalVelocity = -0.001;
    float vy = 0;
    float ay = 0;
    bool jumped = false;
};


#endif //PLATFORMER_PLAYER_H
