cmake_minimum_required(VERSION 3.15)


project(BattleShip C)



set(CMAKE_C_STANDARD 99)



add_executable(BattleShip main.c grille.c grille.h global.h jouer.c jouer.h general.c general.h)