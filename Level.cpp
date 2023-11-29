/**
 * @file Level.cpp
 * @brief
 * @author  Liam, Karen, Jake, Emma
 * @bug no known bugs
 */
#include "Level.h"
#include <iostream>
#include <cmath>

using namespace std;

Level::Level(shared_ptr<sf::RenderWindow> window, string levelName) {

    string currLevelName = levelName;
    levelName.erase(0, 5);
    levelNum = stoi(levelName);
    gameClock; //start the game clock to time physics

    backgroundTexture.loadFromFile("Resources/Images/Background.png");

    load(currLevelName);
    //player = new Player(start, size, sf::Vector2f(GRIDSIZE, GRIDSIZE)); //initialize player

    for (int i=0; i<enemyStartPositions.size(); i++) {  // initialise enemies
        enemies.push_back(enemy = new Enemy(*enemyStartPositions.at(i), *enemyEndPositions.at(i), size, sf::Vector2f(GRIDSIZE, GRIDSIZE/2)));
    }

    //floor = sf::RectangleShape(sf::Vector2f(size.x, 5*GRIDSIZE));
    //floor.setPosition(sf::Vector2f(0, size.y));
    player = new Player(start, size, sf::Vector2f(GRIDSIZE, 2*GRIDSIZE)); //initialize player

    camera = new sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));

}

int Level::getLevel() {
    return levelNum;
}

int Level::play(shared_ptr<sf::RenderWindow> window) {
    sf::Event event;
    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            // pause menu
            else if (event.type == sf::Event::KeyPressed) {
                 if (event.key.scancode == sf::Keyboard::Scan::Escape) {
                     window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
                     int pauseSelect = PauseMenu(window);
                     if (pauseSelect == 1) {
                         // close level and open level select menu
                         // return 2;
                     }
                     else if (pauseSelect == 2) {
                         // open main menu again
                         return 3;
                     }
                     else if (pauseSelect == -1) {
                         window->close();
                         return -1;
                     }
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
        for (int i=0; i<rewardObjects.size(); i++) {
            /**
             * Want to change to checking first if in current view, then check for collision.
             * Will leave for later.
             */
            if (player->collides(rewardObjects.at(i))) {
                rewardObjects.at(i)->collect(); // Hide coin
                coinsCollect=true;
                scoreObjects.at(i)->show();
            }
        }
        for (int i=0; i<scoreObjects.size(); i++) {// Hide score
            /**
             * Want to change to checking first if in current view, then check for collision.
             * Will leave for later.
             */
            if (coinsCollect==false){
                scoreObjects.at(i)->collect();
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

        for (int i=0; i<enemies.size(); i++) {
            /**
             * Want to change to checking first if in current view, then check for collision.
             * Will leave for later.
             */
            if (player->collides(enemies.at(i))) {

                // player kills enemy by colliding with enemy from top
                if (player->getPrevPosition().y+player->getSize().y < enemies.at(i)->getPositionY()) {
                    enemies.at(i)->getShape()->setFillColor(sf::Color::Transparent);
                    enemies.erase(enemies.begin()+i);   // actually deletes enemy object
                }
                else {
                    return 0;       // any other kind of collision causes death
                }

            }
        }

        //get the time elapsed since last frame
        int elapsed = gameClock.restart().asMicroseconds();
        if (elapsed > 10000) elapsed = 0; // fixes teleportation for resizing window
        player->Update(elapsed);

        for (int i=0; i<enemies.size(); i++) {
            /**
             * Want to change to checking first if in current view, then check for collision.
             * Will leave for later.
             */
            enemies.at(i)->Update(elapsed);

        }

        //center the camera on the player
        camera->setCenter(sf::Vector2<float>(player->getPositionX(), player->getPositionY()));
        window->setView(*camera);

        //draw the objects in the game
        for (int i=0; i<backgrounds.size(); ++i) {
            window->draw(*backgrounds.at(i));
            //cout<<backgrounds.at(i)->getPosition().x<<endl;
        }
        //window->draw(floor);
        window->draw(*player->getShape());
        for (int i=0; i<deathObjects.size(); i++) {
            window->draw(*deathObjects.at(i)->getShape());
        }
        for (int i=0; i<rewardObjects.size(); i++) {
            window->draw(*rewardObjects.at(i)->getShape());
        }
        for (int i=0; i<scoreObjects.size(); i++) {
            window->draw(*scoreObjects.at(i)->getShape());
        }
        for (int i=0; i<terrain.size(); i++) {
            window->draw(*terrain.at(i)->getShape());
        }
        for (int i=0; i<goals.size(); i++) {
            window->draw(*goals.at(i)->getShape());
        }
     //   window->draw(scoring->getScore());
        for (int i=0; i<enemies.size(); i++) {
            window->draw(*enemies.at(i)->getShape());
        }

        // end the current frame
        window->display();
    }

    return -1;
}

/**
 * @brief loads levels from png images in resources
 * @param levelName the name of the level to load
 * @return true if the level is loaded, false if loading fails
 */
bool Level::load(std::string levelName) {

    //load the map from an image into an array of pixels
    string levelPath = "Resources/Levels/"+levelName+".png";
    sf::Image* map = new sf::Image();
    bool loadSuccess = map->loadFromFile(levelPath);
    if (!loadSuccess) return false; //return false if image isn't loaded correctly

    size = sf::Vector2f(map->getSize().x*GRIDSIZE, map->getSize().y*GRIDSIZE);//get the size for player boundaries

    int backgroundNum = ceil(float(map->getSize().x*GRIDSIZE)/float(BACKGROUND_WIDTH));
    for (int i = -1; i < backgroundNum+1; ++i) {
        backgrounds.push_back(new sf::Sprite(backgroundTexture));
        backgrounds.at(i+1)->setPosition(i*BACKGROUND_WIDTH,  size.y+BACKGROUND_HEIGHT);
    }

    for (unsigned int i = 0; i < map->getSize().x; ++i) {

        for (unsigned int j = 0; j < map->getSize().y; ++j) {

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
            else if (c==sf::Color::Yellow) { //Create coins
                rewardObjects.push_back(new Coin(sf::Vector2f(GRIDSIZE, GRIDSIZE), sf::Vector2f(i*GRIDSIZE, j*GRIDSIZE)));
            }
            else if (c==sf::Color(128,0,128)){//Create scores
                scoreObjects.push_back(new Coin(sf::Vector2f(GRIDSIZE, GRIDSIZE), sf::Vector2f(i*GRIDSIZE, j*GRIDSIZE)));
            }
            else if (c==sf::Color::Magenta) {//get enemy starting position and spawn enemies
                enemyStartPositions.push_back(new sf::Vector2f(i*GRIDSIZE, j*GRIDSIZE+GRIDSIZE/2));
            }
            else if (c==sf::Color::Cyan) {//get enemy ending position
                enemyEndPositions.push_back(new sf::Vector2f(i*GRIDSIZE, j*GRIDSIZE));

            }

        }

    }

    return true;

}
