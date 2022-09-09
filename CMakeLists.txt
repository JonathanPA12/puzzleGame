cmake_minimum_required(VERSION 3.23)
project(puzzleGame C)

set(CMAKE_C_STANDARD 99)

add_executable(puzzleGame main.c juego.h juego.c)
