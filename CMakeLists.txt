cmake_minimum_required(VERSION 3.5)

project(UNO LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(UNO
    UnoGame.cpp
    UnoHand.cpp
    UnoCard.cpp
    UnoHand.h
    UnoCard.h
)
