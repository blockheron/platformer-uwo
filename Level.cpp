//
// Created by Liam on 2023-10-18.
// Edited by Karen 11/5/2023.
//
#include "Level.h"
#include <iostream>

using namespace std;

Level::Level(sf::RenderWindow* window) {

    gameClock; //start the game clock to time physics
    player = new Player(window->getSize()); //initialize player
    obstacle = new obstacles(); //initialize obstacle
    obstacle2 = new obstacles(); //initialize obstacle
    obstacle3 = new obstacles(); //initialize obstacle
    obstacle4 = new obstacles(); //initialize obstacle
    collisions* collision = new collisions( player, obstacle); // Create collision instance

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

        collision->check(); // Check for collision
        // Player does nto move if there's a collision
        if(!collision->getCollisionCheck() ){
            player->Update(elapsed);
        } else{
           player->setToMove(false);
        }


        // Show the obstacles in the game
        obstacle->show(250.f, 545.f);
        obstacle3->show(250.f, 345.f);
        obstacle2->show(500.f, 545.f);
        obstacle4->show(500.f, 345.f);

        //draw the objects in the game
        window->draw(*player->getShape());
        window->draw(*obstacle->getShape());
        window->draw(*obstacle2->getShape());
        window->draw(*obstacle3->getShape());
        window->draw(*obstacle4->getShape());

        // end the current frame
        window->display();
    }
    //

}
