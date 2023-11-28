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
    titleTexture.loadFromFile("Resources/Images/mainTitle.png");
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

            window->clear(sf::Color::Black);
            window->draw(title);
            window->draw(playAgainButton);
            window->draw(exitButton);
            window->display();
        }
    }
}

int PauseMenu(std::shared_ptr<sf::RenderWindow> window) {
    // set background
    window->clear(sf::Color::Black);

    // set up title of game texture
    sf::Texture titleTexture;
    sf::Sprite title;
    titleTexture.loadFromFile("Resources/Images/pauseMenu.png");
    title.setTexture(titleTexture);
    title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
    title.setPosition(window->getSize().x/2, window->getSize().y/4);

    // set up play button for main menu
    sf::Texture resume;
    sf::Sprite resumeButton;
    resume.loadFromFile("Resources/Images/resume.png");
    resumeButton.setTexture(resume);
    resumeButton.setOrigin(resumeButton.getLocalBounds().width/2, resumeButton.getLocalBounds().height/2);
    resumeButton.setPosition(window->getSize().x/2, (window->getSize().y/2));

    sf::Texture levelSelect;
    sf::Sprite levelSelectButton;
    levelSelect.loadFromFile("Resources/Images/levelSelect.png");
    levelSelectButton.setTexture(levelSelect);
    levelSelectButton.setOrigin(levelSelectButton.getLocalBounds().width/2, levelSelectButton.getLocalBounds().height/2);
    levelSelectButton.setPosition(window->getSize().x/2, (window->getSize().y/10)*6);

    sf::Texture mainMenu;
    sf::Sprite mainMenuButton;
    mainMenu.loadFromFile("Resources/Images/mainMenu.png");
    mainMenuButton.setTexture(mainMenu);
    mainMenuButton.setOrigin(mainMenuButton.getLocalBounds().width/2, mainMenuButton.getLocalBounds().height/2);
    mainMenuButton.setPosition(window->getSize().x/2, (window->getSize().y/10)*7);

    sf::Texture help;
    sf::Sprite helpButton;
    help.loadFromFile("Resources/Images/help.png");
    helpButton.setTexture(help);
    helpButton.setOrigin(helpButton.getLocalBounds().width/2, helpButton.getLocalBounds().height/2);
    helpButton.setPosition(window->getSize().x/2, (window->getSize().y/10)*8);

    sf::Texture exit;
    sf::Sprite exitButton;
    exit.loadFromFile("Resources/Images/exitGame.png");
    exitButton.setTexture(exit);
    exitButton.setOrigin(exitButton.getLocalBounds().width/2, exitButton.getLocalBounds().height/2);
    exitButton.setPosition(window->getSize().x/2, (window->getSize().y/10)*9);

    window->draw(title);
    window->draw(resumeButton);
    window->draw(levelSelectButton);
    window->draw(mainMenuButton);
    window->draw(helpButton);
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
                if (resumeButton.getGlobalBounds().contains(MPos)) {
                    resumeButton.setColor(sf::Color(34, 139, 34));
                } else if (levelSelectButton.getGlobalBounds().contains(MPos)) {
                    levelSelectButton.setColor(sf::Color(34, 139, 34));
                }
                else if (mainMenuButton.getGlobalBounds().contains(MPos)) {
                    mainMenuButton.setColor(sf::Color(34, 139, 34));
                }
                else if (helpButton.getGlobalBounds().contains(MPos)) {
                    helpButton.setColor(sf::Color(34, 139, 34));
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    exitButton.setColor(sf::Color(34, 139, 34));
                } else {
                    resumeButton.setColor(sf::Color::White);
                    levelSelectButton.setColor(sf::Color::White);
                    mainMenuButton.setColor(sf::Color::White);
                    helpButton.setColor(sf::Color::White);
                    exitButton.setColor(sf::Color::White);
                }
            }
            else if (evt.type == sf::Event::MouseButtonPressed) {
                // to be added...Resume (to continue playing), Level Select, Help, Main Menu, Exit Game
                sf::Vector2f MPos;
                MPos.x = sf::Mouse::getPosition(*window).x;
                MPos.y = sf::Mouse::getPosition(*window).y;
                if (resumeButton.getGlobalBounds().contains(MPos)) {
                    return 0;
                }
                else if (levelSelectButton.getGlobalBounds().contains(MPos)) {
                    //return 1;
                }
                else if (mainMenuButton.getGlobalBounds().contains(MPos)) {
                    return 2;
                }
                else if (helpButton.getGlobalBounds().contains(MPos)) {
                    // open help menu within here
                    // return 0;
                }
                else if (exitButton.getGlobalBounds().contains(MPos)) {
                    return -1;
                }
            }

            window->clear(sf::Color::Black);
            window->draw(title);
            window->draw(resumeButton);
            window->draw(levelSelectButton);
            window->draw(mainMenuButton);
            window->draw(helpButton);
            window->draw(exitButton);
            window->display();
        }
    }
}
