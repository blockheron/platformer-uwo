//
// Created by Liam on 2023-10-18.
// Edited by Karen 11/5/2023.
// Edited by Jake 2023/11/06
//
#include "Level.h"
#include <iostream>

using namespace std;

Level::Level(shared_ptr<sf::RenderWindow> window) {

    gameClock; //start the game clock to time physics
    player = new Player(window->getSize(), sf::Vector2f(50.f, 50.f)); //initialize player

    // Create obstacles that player must avoid.
    vector<Object*> deathObjects;
    deathObjects.push_back(new Obstacle(sf::Vector2f(60.f, 60.f), sf::Vector2f(500.f, 470.f)));
    deathObjects.push_back(new Obstacle(sf::Vector2f(60.f, 60.f), sf::Vector2f(1000.f, 500.f)));
    deathObjects.push_back(new Obstacle(sf::Vector2f(60.f, 60.f), sf::Vector2f(1500.f, 500.f)));
    deathObjects.push_back(new Obstacle(sf::Vector2f(60.f, 60.f), sf::Vector2f(2000.f, 460.f)));

    camera = new sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));

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

        bool collision = false;

        for (int i=0; i<deathObjects.size(); i++) {
            /**
             * Want to change to checking first if in current view, then check for collision.
             * Will leave for later.
             */
             if (player->collides(deathObjects.at(i))) {
                 collision = true;
                 break;
             }
        }

        // Player does not move if there's a collision
        if(!collision){
            player->Update(elapsed);
        } else{
           player->setToMove(false);
        }


        //center the camera on the player
        camera->setCenter(sf::Vector2<float>(player->getShape()->getPosition().x, camera->getCenter().y));
        window->setView(*camera);

        //draw the objects in the game
        window->draw(*player->getShape());
        for (int i=0; i<deathObjects.size(); i++) {
            window->draw(*deathObjects.at(i)->getShape());
        }

        // end the current frame
        window->display();
    }

    return;

}
