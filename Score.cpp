/**
 * @file Score.cpp
 * @brief Class for scoring system
 * @author Karen
 * @bug no known bugs
 */

#include "Score.h"

// Score constructor
Score::Score(sf::Vector2f size, sf::Vector2f pos) : position(pos), Object(size) {
    shape->setPosition(800, 600);
    shape->setFillColor(sf::Color::Yellow);
    /*score.setString("0");
    score.setCharacterSize(500);
    score.setStyle(sf::Text::Bold);
    score.setFillColor(sf::Color::Red);
    score.setPosition(sf::Vector2f(200, 400));*/
}

/*void Score::increment()  {
    // Cannot change const string so have to "convert" to non-cost
    nonConstStr = score.getString();
    score.setString(std::to_string(1+std::stoi(nonConstStr))) ; //Increase
    // return score;

}*/

/*sf::Text Score::getScore()  {
    // cout << score << end1;
    return score;
}*/