#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"

using namespace std;

int main() {

    //https://www.sfml-dev.org/tutorials/2.6/graphics-draw.php
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platformer");
    sf::Clock gameClock; //start the game clock to time physics

    Player* player = new Player(window.getSize());

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // set the background
        window.clear(sf::Color::Black);

        //get the time elapsed since last frame
        int elapsed = gameClock.restart().asMicroseconds();

        // update the objects in the game
        player->Update(elapsed);

        //draw the objects in the game
        window.draw(*player->getShape());

        // end the current frame
        window.display();
    }
    //

    return 0;

}
