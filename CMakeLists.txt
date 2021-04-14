cmake_minimum_required(VERSION 3.15)
project(1c_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(1c_project main.cpp Card.hpp Deck.cpp Deck.h Game.cpp Game.h)