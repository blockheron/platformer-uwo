cmake_minimum_required(VERSION 3.23)
project(Platformer)

set(CMAKE_CXX_STANDARD 14)
include_directories(../libraries)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "libraries/SFML-2.6.0/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS graphics audio system window REQUIRED)
add_executable(Platformer main.cpp Player.cpp Player.h)
target_link_libraries(Platformer sfml-graphics sfml-audio sfml-system sfml-window)