cmake_minimum_required(VERSION 3.5)
project(Snaze VERSION 0.1 LANGUAGES CXX )

include_directories( include )
# set (CMAKE_CXX_FLAGS "-fsanitize=address -g -O3")

add_executable( snaze
                src/main.cpp
                src/Player.cpp
                src/Interface.cpp
                src/Game.cpp
                src/Maze.cpp
                )