//
// Created by Liam on 2023-10-18.
// Edited by Karen 11/5/2023.
//
/**
 * This is a test comment to commit and push.
 */

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Level.h"
#include "obstacles.h"

using namespace std;

int main() {

    //https://www.sfml-dev.org/tutorials/2.6/graphics-draw.php
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platformer");

    Level* level = new Level(&window);

    return 0;

}
