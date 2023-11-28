/**
 * @file Level.cpp
 * @brief
 * @author  Liam, Karen, Jake
 * @bug no known bugs
 */
#include "Level.h"
#include <iostream>
#include <cmath>

using namespace std;

Level::Level(shared_ptr<sf::RenderWindow> window, string levelName) {

    gameClock; //start the game clock to time physics

    backgroundTexture.loadFromFile("Resources/Images/Background.png");

    load(levelName);
    player = new Player(start, size, sf::Vector2f(GRIDSIZE, 2*GRIDSIZE)); //initialize player

    camera = new sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));

    //background.setTexture(backgroundTexture);
    //background.setPosition(sf::Vector2f(0,size.y+BACKGROUND_HEIGHT));


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
            else if (event.type == sf::Event::Resized) {
                if (event.size.width < DEFAULT_WINDOW_WIDTH || event.size.height < DEFAULT_WINDOW_HEIGHT) {
                    window->setSize(sf::Vector2u(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT));
                    camera->setSize(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
                }
                else {
                    camera->setSize(event.size.width, event.size.height);
                }
            }
        }
        // set the background
        window->clear(sf::Color(45,33,21));

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
        for (int i=0; i<goals.size(); i++) {
            /**
             * Want to change to checking first if in current view, then check for collision.
             * Will leave for later.
             */
            if (player->collides(goals.at(i))) {
                return 1;
            }
        }

        //get the time elapsed since last frame
        int elapsed = gameClock.restart().asMicroseconds();
        if (elapsed > 10000) elapsed = 0; // fixes teleportation for resizing window
        player->Update(elapsed);

        //center the camera on the player
        camera->setCenter(sf::Vector2<float>(player->getShape()->getPosition().x, player->getShape()->getPosition().y));
        //center the camera on the player
        camera->setCenter(sf::Vector2<float>(player->getPositionX(), player->getPositionY()));
        window->setView(*camera);

        //draw the objects in the game
        for (int i=0; i<backgrounds.size(); ++i) {
            window->draw(*backgrounds.at(i));
            //cout<<backgrounds.at(i)->getPosition().x<<endl;
        }
        window->draw(floor);
        window->draw(*player->getShape());
        for (int i=0; i<deathObjects.size(); i++) {
            window->draw(*deathObjects.at(i)->getShape());
        }
        for (int i=0; i<terrain.size(); i++) {
            window->draw(*terrain.at(i)->getShape());
        }
        for (int i=0; i<goals.size(); i++) {
            window->draw(*goals.at(i)->getShape());
        }

        // end the current frame
        window->display();
    }

    return -1;
}

bool Level::load(std::string levelName) {

    //load the map from an image into an array of pixels
    string levelPath = "Resources/Levels/"+levelName+".png";
    sf::Image* map = new sf::Image();
    bool loadSuccess = map->loadFromFile(levelPath);
    if (!loadSuccess) return false; //return false if image isn't loaded correctly

    size = sf::Vector2f(map->getSize().x*GRIDSIZE, map->getSize().y*GRIDSIZE);//get the size for player boundaries

    int backgroundNum = ceil(float(map->getSize().y*GRIDSIZE)/float(BACKGROUND_WIDTH));
    for (int i = -1; i < backgroundNum+1; ++i) {
        backgrounds.push_back(new sf::Sprite(backgroundTexture));
        backgrounds.at(i+1)->setPosition(i*BACKGROUND_WIDTH,  size.y+BACKGROUND_HEIGHT);
    }

    for (unsigned int i = 0; i < map->getSize().y; ++i) {

        for (unsigned int j = 0; j < map->getSize().x; ++j) {

            sf::Color c = map->getPixel(i, j); //get the colour of each pixel
            if (c == sf::Color::White) {//create terrain
                terrain.push_back(new Terrain(sf::Vector2f(GRIDSIZE, GRIDSIZE), sf::Vector2f(i*GRIDSIZE, j*GRIDSIZE)));
            }
            else if (c==sf::Color::Red) {//create obstacles
                deathObjects.push_back(new Obstacle(sf::Vector2f(GRIDSIZE, GRIDSIZE), sf::Vector2f(i*GRIDSIZE, j*GRIDSIZE)));
            }
            else if (c==sf::Color::Green) {//create goals
                goals.push_back(new Goal(sf::Vector2f(GRIDSIZE, GRIDSIZE), sf::Vector2f(i*GRIDSIZE, j*GRIDSIZE)));
            }
            else if (c==sf::Color::Blue) {//get player starting position
                start = sf::Vector2f(i*GRIDSIZE, j*GRIDSIZE);
            }

        }

    }

    return true;

}
