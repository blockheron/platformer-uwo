/**
 * @file Menu.cpp
 * @brief
 * @author Jake
 * @bug no known bugs
 */

#include "Menu.h"

using namespace std;

int MainMenu(shared_ptr<sf::RenderWindow> window) {
    // set background
    window->clear(sf::Color::Black);

    // set up title of game texture
    sf::Texture titleTexture;
    sf::Sprite title;
    titleTexture.loadFromFile("Resources/Images/title.png");
    title.setTexture(titleTexture);
    title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
    title.setPosition(window->getSize().x/2, window->getSize().y/3);

    // set up play button for main menu
    sf::Texture playButtonText;
    sf::Sprite playButton;
    playButtonText.loadFromFile("Resources/Images/play_button.png");
    playButton.setTexture(playButtonText);
    playButton.setOrigin(playButton.getLocalBounds().width/2, playButton.getLocalBounds().height/2);
    playButton.setPosition(window->getSize().x/2, (window->getSize().y/3)*2);
    playButton.setColor(sf::Color(208, 169, 51));

    window->draw(title);
    window->draw(playButton);
    window->display();

    sf::Event evt;
    while (1) {
        while (window->pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window->close();
                return 0;
            }
            else if (evt.type == sf::Event::MouseMoved) {
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (playButton.getGlobalBounds().contains(MPos)) {
                    playButton.setColor(sf::Color(34, 139, 34));
                }
                else {
                    playButton.setColor(sf::Color(208, 169, 51));
                }
            }
            else if (evt.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (playButton.getGlobalBounds().contains(MPos)) {
                    return 2;
                }
            }
            else if (evt.type == sf::Event::Resized) {
                if (evt.size.width < DEFAULT_WINDOW_WIDTH || evt.size.height < DEFAULT_WINDOW_WIDTH) {
                    window->setSize(sf::Vector2u(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT));
                    window->setView(sf::View(sf::FloatRect(0, 0, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT)));
                    title.setPosition(DEFAULT_WINDOW_WIDTH/2, DEFAULT_WINDOW_HEIGHT/3);
                    playButton.setPosition(DEFAULT_WINDOW_WIDTH/2, (DEFAULT_WINDOW_HEIGHT/3)*2);
                }
                else {
                    window->setView(sf::View(sf::FloatRect(0, 0, evt.size.width, evt.size.height)));
                    title.setPosition(evt.size.width/2, evt.size.height/3);
                    playButton.setPosition(evt.size.width/2, (evt.size.height/3)*2);
                }
            }

            window->clear(sf::Color::Black);
            window->draw(title);
            window->draw(playButton);
            window->display();
        }
    }
}

int GameOver(shared_ptr<sf::RenderWindow> window) {
    // set background
    window->clear(sf::Color::Black);

    // set up title of game texture
    sf::Texture titleTexture;
    sf::Sprite title;
    titleTexture.loadFromFile("Resources/Images/gameover.png");
    title.setTexture(titleTexture);
    title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
    title.setPosition(window->getSize().x/2, window->getSize().y/4);

    // set up play button for main menu
    sf::Texture playAgain;
    sf::Sprite playAgainButton;
    playAgain.loadFromFile("Resources/Images/playagain_button.png");
    playAgainButton.setTexture(playAgain);
    playAgainButton.setOrigin(playAgainButton.getLocalBounds().width/2, playAgainButton.getLocalBounds().height/2);
    playAgainButton.setPosition(window->getSize().x/2, (window->getSize().y/8)*5);

    sf::Texture exit;
    sf::Sprite exitButton;
    exit.loadFromFile("Resources/Images/exit_button.png");
    exitButton.setTexture(exit);
    exitButton.setOrigin(exitButton.getLocalBounds().width/2, exitButton.getLocalBounds().height/2);
    exitButton.setPosition(window->getSize().x/2, (window->getSize().y/8)*7);

    window->draw(title);
    window->draw(playAgainButton);
    window->draw(exitButton);
    window->display();

    sf::Event evt;
    while (1) {
        while (window->pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window->close();
                return 0;
            }
            else if (evt.type == sf::Event::MouseMoved) {
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (playAgainButton.getGlobalBounds().contains(MPos)) {
                    playAgainButton.setColor(sf::Color(34, 139, 34));
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    exitButton.setColor(sf::Color(34, 139, 34));
                }
                else {
                    playAgainButton.setColor(sf::Color::White);
                    exitButton.setColor(sf::Color::White);
                }
            }
            else if (evt.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (playAgainButton.getGlobalBounds().contains(MPos)) {
                    return 0;
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    return 1;
                }
            }
            else if (evt.type == sf::Event::Resized) {
                if (evt.size.width < DEFAULT_WINDOW_WIDTH || evt.size.height < DEFAULT_WINDOW_WIDTH) {
                    window->setSize(sf::Vector2u(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT));
                    window->setView(sf::View(sf::FloatRect(0, 0, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT)));
                    title.setPosition(DEFAULT_WINDOW_WIDTH/2, DEFAULT_WINDOW_HEIGHT/4);
                    playAgainButton.setPosition(DEFAULT_WINDOW_WIDTH/2, (DEFAULT_WINDOW_HEIGHT/8)*5);
                    exitButton.setPosition(DEFAULT_WINDOW_WIDTH/2, (DEFAULT_WINDOW_HEIGHT/8)*7);
                }
                else {
                    window->setView(sf::View(sf::FloatRect(0, 0, evt.size.width, evt.size.height)));
                    title.setPosition(evt.size.width / 2, evt.size.height / 4);
                    playAgainButton.setPosition(evt.size.width / 2, (evt.size.height / 8) * 5);
                    exitButton.setPosition(evt.size.width / 2, (evt.size.height / 8) * 7);
                }
            }

            window->clear(sf::Color::Black);
            window->draw(title);
            window->draw(playAgainButton);
            window->draw(exitButton);
            window->display();
        }
    }
}

int LevelComplete(shared_ptr<sf::RenderWindow> window) {
    // set background
    window->clear(sf::Color::Black);

    // set up title of game texture
    sf::Texture titleTexture;
    sf::Sprite title;
    titleTexture.loadFromFile("Resources/Images/levelcomplete.png");
    title.setTexture(titleTexture);
    title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
    title.setPosition(window->getSize().x/2, window->getSize().y/4);

    // set up play button for main menu
    sf::Texture playAgain;
    sf::Sprite playAgainButton;
    playAgain.loadFromFile("Resources/Images/playagain_button.png");
    playAgainButton.setTexture(playAgain);
    playAgainButton.setOrigin(playAgainButton.getLocalBounds().width/2, playAgainButton.getLocalBounds().height/2);
    playAgainButton.setPosition(window->getSize().x/2, (window->getSize().y/8)*5);

    sf::Texture exit;
    sf::Sprite exitButton;
    exit.loadFromFile("Resources/Images/exit_button.png");
    exitButton.setTexture(exit);
    exitButton.setOrigin(exitButton.getLocalBounds().width/2, exitButton.getLocalBounds().height/2);
    exitButton.setPosition(window->getSize().x/2, (window->getSize().y/8)*7);

    window->draw(title);
    window->draw(playAgainButton);
    window->draw(exitButton);
    window->display();

    sf::Event evt;
    while (1) {
        while (window->pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window->close();
                return 0;
            }
            else if (evt.type == sf::Event::MouseMoved) {
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (playAgainButton.getGlobalBounds().contains(MPos)) {
                    playAgainButton.setColor(sf::Color(34, 139, 34));
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    exitButton.setColor(sf::Color(34, 139, 34));
                }
                else {
                    playAgainButton.setColor(sf::Color::White);
                    exitButton.setColor(sf::Color::White);
                }
            }
            else if (evt.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (playAgainButton.getGlobalBounds().contains(MPos)) {
                    return 0;
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    return 1;
                }
            }
            else if (evt.type == sf::Event::Resized) {
                if (evt.size.width < DEFAULT_WINDOW_WIDTH || evt.size.height < DEFAULT_WINDOW_WIDTH) {
                    window->setSize(sf::Vector2u(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT));
                    window->setView(sf::View(sf::FloatRect(0, 0, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT)));
                    title.setPosition(DEFAULT_WINDOW_WIDTH/2, DEFAULT_WINDOW_HEIGHT/4);
                    playAgainButton.setPosition(DEFAULT_WINDOW_WIDTH/2, (DEFAULT_WINDOW_HEIGHT/8)*5);
                    exitButton.setPosition(DEFAULT_WINDOW_WIDTH/2, (DEFAULT_WINDOW_HEIGHT/8)*7);
                }
                else {
                    window->setView(sf::View(sf::FloatRect(0, 0, evt.size.width, evt.size.height)));
                    title.setPosition(evt.size.width/2, evt.size.height/4);
                    playAgainButton.setPosition(evt.size.width/2, (evt.size.height/8)*5);
                    exitButton.setPosition(evt.size.width/2, (evt.size.height/8)*7);
                }
            }

            window->clear(sf::Color::Black);
            window->draw(title);
            window->draw(playAgainButton);
            window->draw(exitButton);
            window->display();
        }
    }
}
