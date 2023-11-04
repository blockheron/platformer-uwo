#include "Level.h"
#include <iostream>

using namespace std;

Level::Level(sf::RenderWindow* window) {

    gameClock; //start the game clock to time physics
    player = new Player(window->getSize()); //initialize player

    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // set the background
        window->clear(sf::Color::Black);

        //get the time elapsed since last frame
        int elapsed = gameClock.restart().asMicroseconds();

        // update the objects in the game
        player->Update(elapsed);

        //draw the objects in the game
        window->draw(*player->getShape());

        // end the current frame
        window->display();
    }
    //

}
