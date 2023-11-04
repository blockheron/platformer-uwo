cmake_minimum_required(VERSION 3.23)
project(group14)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)
include_directories(${SFML_INCLUDE_DIRS})

find_package(SFML 2.6 COMPONENTS graphics audio system window REQUIRED)
add_executable(group14 main.cpp Player.cpp Player.h)
target_link_libraries(group14 sfml-graphics sfml-audio sfml-system sfml-window)