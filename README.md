# Group 14 - Platformer Game

## Getting Started

### Dependencies and Set-Up

This program requires downloading SFML 2.6.0 or later. Please click [here](https://www.sfml-dev.org/download/sfml/2.6.1/) and download your compatible version.

Currently our program has been tested on Windows and Intel-based Macs.

To run on an application CLion, copy and paste the following in your CMakeLists.txt to build and run the program properly.

#### For Windows:
```

```

#### For Mac:
```
cmake_minimum_required(VERSION 3.23)
project(group14)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)
include_directories(${SFML_INCLUDE_DIRS})

find_package(SFML 2.6 COMPONENTS graphics audio system window REQUIRED)
add_executable(group14 main.cpp Player.cpp Player.h Level.cpp Level.h Menu.h Menu.cpp Obstacle.h Obstacle.cpp Object.h Object.cpp Goal.h Goal.cpp)
target_link_libraries(group14 sfml-graphics sfml-audio sfml-system sfml-window)
```

### Executing Program

To run the program, open the specific build folder and ensure it's in the main directory.
Open the executable and the game should run.

For mac we recommend the following:
* After opening the mac build folder and moving it into the main directory, go to the terminal.
* In the terminal, change directory to the directory with the executable.
* Run the executable with the following command:
```
./group14
```

## How to Play

Use 'A' and 'D' keys to move right and left. Use Space or 'W' key to jump. 

Avoid the red obstacles and move into the green obstacle to complete the game.