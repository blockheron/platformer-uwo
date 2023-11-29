//
// Created by Jake Choi on 2023-11-28.
//

#ifndef PLATFORMER_USER_H
#define PLATFORMER_USER_H

#include <iostream>
#include <fstream>
#include "Level.h"
#include "Menu.h"

using namespace std;

class User {
public:
    User(string userName, shared_ptr<sf::RenderWindow> window);
    void saveState(int levelCompleted);
    void updateMeta();
    int getNumAccessibleLevels();

private:
    string user;
    vector<string> levels;
    vector<Level*> accessibleLevels;
    shared_ptr<sf::RenderWindow> mainWindow;
};

#endif //PLATFORMER_USER_H
