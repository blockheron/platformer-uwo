//
// Created by Liam on 2023-11-04.
//

#ifndef PLATFORMER_LEVEL_H
#define PLATFORMER_LEVEL_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Level {
public:
    Level(sf::RenderWindow*);
private:
    sf::Clock gameClock;
    Player* player;
};



#endif //PLATFORMER_LEVEL_H
