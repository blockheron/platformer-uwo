/**
 * @file Level.cpp
 * @brief
 * @author  Liam, Karen, Jake
 * @bug no known bugs
 */
#include "Level.h"
#include <iostream>

using namespace std;

Level::Level(shared_ptr<sf::RenderWindow> window) {

    gameClock; //start the game clock to time physics
    player = new Player(window->getSize(), sf::Vector2f(50.f, 50.f)); //initialize player

    // Create obstacles that player must avoid.
    deathObjects.push_back(new Obstacle(sf::Vector2f(60.f, 60.f), sf::Vector2f(500.f, 470.f)));
    deathObjects.push_back(new Obstacle(sf::Vector2f(60.f, 100.f), sf::Vector2f(1000.f, 500.f)));
    deathObjects.push_back(new Obstacle(sf::Vector2f(60.f, 100.f), sf::Vector2f(1500.f, 500.f)));
    deathObjects.push_back(new Obstacle(sf::Vector2f(60.f, 60.f), sf::Vector2f(2000.f, 460.f)));

    // Other obstacles
    terrain.push_back(new Terrain(sf::Vector2f(60.f, 60.f), sf::Vector2f(2400.f, 470.f)));

    goal = new Goal(sf::Vector2f(100.f, 600.f), sf::Vector2f(2800.f, 0.f));

    camera = new sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));

}

int Level::play(shared_ptr<sf::RenderWindow> window) {
    sf::Event event;
    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            // May add resizing event here
        }
        // set the background
        window->clear(sf::Color::Black);

        //get the time elapsed since last frame
        int elapsed = gameClock.restart().asMicroseconds();

        bool deathCollision = false;

        for (int i=0; i<deathObjects.size(); i++) {
            /**
             * Want to change to checking first if in current view, then check for collision.
             * Will leave for later.
             */
            if (player->collides(deathObjects.at(i))) {
                return 0;
            }
        }
        for (int i=0; i<terrain.size(); i++) {
            /**
             * Want to change to checking first if in current view, then check for collision.
             * Will leave for later.
             */
            if (player->collides(terrain.at(i))) {
                player->collided(terrain.at(i));
            }
        }

        if (player->collides(goal) || player->getPositionX() > 2800.f) {
            return 1;
        }

        player->Update(elapsed);

        //center the camera on the player
        camera->setCenter(sf::Vector2<float>(player->getShape()->getPosition().x, camera->getCenter().y));
        window->setView(*camera);

        //draw the objects in the game
        window->draw(*player->getShape());
        for (int i=0; i<deathObjects.size(); i++) {
            window->draw(*deathObjects.at(i)->getShape());
        }
        for (int i=0; i<terrain.size(); i++) {
            window->draw(*terrain.at(i)->getShape());
        }
        window->draw(*goal->getShape());

        // end the current frame
        window->display();
    }
}
