cmake_minimum_required(VERSION 3.10)
project(hw5)



include_directories(.)
include_directories(provided_files)

add_executable(hw5
        deck.cpp
        deck.h
        main.cpp
        node.h
        playing_card.cpp
        playing_card.h)
