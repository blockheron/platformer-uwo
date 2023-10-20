//
// Created by Liam on 2023-10-18.
//

#ifndef PLATFORMER_PLAYER_H
#define PLATFORMER_PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void Update(int timeElapsed);
    sf::Shape* getShape();
private:
    sf::RectangleShape* shape;
    const float speed = 0.0005;
};


#endif //PLATFORMER_PLAYER_H
