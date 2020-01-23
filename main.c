/**
 *Title: BattleShip
 *Description: Projet en C dans le cadre du cours Ma-20, afin de mettre en pratique ce qui a été vu au cours ICT-403 lors du premier module.
 *@author Paola COSTA
 *Version: 0.1
 *CreationDate 10.12.19
 *DernieresModifications: 07.01.2020
*/

#include <stdio.h>
#include <windows.h>
#include "global.h"
#include <stdlib.h>
#include <time.h>

/**
 * fonction permettant de gérer le lancement des différents processus du jeu
 * @return 0
 */
int main() {
    message(BIENVENUE);
    lancer();
    return 0;
}