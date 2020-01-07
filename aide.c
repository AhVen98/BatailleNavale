//
// Created by Paola.COSTA on 17.12.2019.
//

#include "aide.h"
#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * fonction permettant d'afficher l'aide du jeu dans la console
 */
void aide(){
    printf("Comment jouer : \n");
    printf("- Il y a 5 bateaux caches dans une grille 10 par 10.\n");
    printf("- Il y a 1 bateau de 2 cases, 2 de 3 cases, 1 de 4 cases et 1 de 5 cases. Pour gagner, il faut tous les detruire.\n");
    printf("- On detruit un bateau en ayant cible toutes les cases sur lequel il est situe.\n");
    printf("- Pour cibler une case, lors de ton tour, ecrit la lettre (A-J) et le numero (1-10) associe a la case puis valider.\n");
    printf("La personne qui joue change apres chaque case ciblee, peu importe si un bateau a ete touche ou pas.\n");
}