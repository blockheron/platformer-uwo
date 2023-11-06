//
// Created by Jake Choi on 2023-11-04.
//

#include "Interface.h"

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

            window->clear(sf::Color::Black);
            window->draw(title);
            window->draw(playButton);
            window->display();
        }
    }
}
