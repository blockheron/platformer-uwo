//
// Created by Karen on 2023-11-05
//

#ifndef PLATFORMER_OBSTACLES_H
#define PLATFORMER_OBSTACLES_H

#include <SFML/Graphics.hpp>

class obstacles {
public:
    //Initialize needed variables ad functions
    obstacles();
    void show(float xPass, float yPass);
    sf::Shape* getShape();
    int getPositionX();
    int getPositionY();

private:
    //Initialize needed variables
    sf::RectangleShape* shape;
    sf::RectangleShape* shape2;
};


#endif //PLATFORMER_PLAYER_H
