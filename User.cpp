/**
 * @file User.cpp
 * @brief
 * @author Jake
 * @bug no known bugs
 */

#include "User.h"

User::User(string userName, shared_ptr<sf::RenderWindow> window) {
    mainWindow = window;
    user = userName;
    fstream savedData;
    savedData.open("Resources/Metadata/SavedUsers.txt", ios::in);
    if (!savedData) {
        cout << "Saved data was not found. Please ensure it's in the correct place.";
        window->close();
    }
    else {
        for (string line; getline(savedData, line); ) {
            string delimiter = " ";
            size_t pos = 0;
            string token;
            pos = line.find(delimiter);
            token = line.substr(0, pos);
            line.erase(0, pos+delimiter.length());
            if (token.find(user) != string::npos) {
                while ((pos = line.find(delimiter)) != string::npos) {
                    token = line.substr(0, pos);
                    levels.push_back(token);
                    line.erase(0, pos+delimiter.length());
                }
                break;
            }
        }
        if (!levels.empty()) {
            for (int i=0; i < levels.size(); i++) {
                accessibleLevels.push_back(new Level(mainWindow, levels[i]));
            }
        }
        else {
            levels.push_back("level1");
            accessibleLevels.push_back(new Level(mainWindow, levels[0]));
        }
    }
}

void User::saveState(int levelCompleted) {
    string nextLevel = "level" + (levelCompleted + 1);
    levels.push_back(nextLevel);
    accessibleLevels.push_back(new Level(mainWindow, levels.back()));
}

int User::getNumAccessibleLevels() {
    return accessibleLevels.size();
}

void User::updateMeta() {
    fstream savedData;
    savedData.open("Resources/Metadata/SavedUsers.txt", ios::out);
    if (!savedData) {
        cout << "Saved data was not found. Please ensure it's in the correct place.";
        mainWindow->close();
    }
    else {
        savedData << user << ": ";
        for (int i=0; i < levels.size(); ++i) {
            if (i == levels.size()-1) {
                savedData << levels[i] << "\n";
            }
            else {
                savedData << levels[i] << " ";
            }
        }
    }
}