//
// Created by Paola.COSTA on 10.12.2019.
//
#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * fonction permettant d'afficher la grille vide et une legende dans la console. Tous les coups faits par le joueur s'afficheront ensuite sur cette grille
 */
void affichageGrille() {
    //affichage des numeros de colonnes
    printf("     0     1     2     3     4     5     6     7     8     9   \n");
    //affichage de la premiere ligne du tableau
    printf("  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", STLC, SHSB, SHTB, SHSB, SHTB, SHSB, SHTB, SHSB, SHTB, SHSB, SHTB, SHSB, SHTB, SHSB, SHTB, SHSB, SHTB, SHSB, SHTB, SHSB, STRC);
    //affichage de la ligne avec caractère
    printf("a %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c\n", SVSB, emptygrid[0][0], SVSB, emptygrid[0][1], SVSB, emptygrid[0][2], SVSB, emptygrid[0][3], SVSB, emptygrid[0][4], SVSB, emptygrid[0][5], SVSB, emptygrid[0][6], SVSB, emptygrid[0][7], SVSB, emptygrid[0][8], SVSB, emptygrid[0][9], SVSB);
    //affichage des lignes entre les lignes à caractères
    printf("  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", SVLB, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SVRB);
    //affichage de la ligne avec caractère
    printf("b %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c\n", SVSB, emptygrid[1][0], SVSB, emptygrid[1][1], SVSB, emptygrid[1][2], SVSB, emptygrid[1][3], SVSB, emptygrid[1][4], SVSB, emptygrid[1][5], SVSB, emptygrid[1][6], SVSB, emptygrid[1][7], SVSB, emptygrid[1][8], SVSB, emptygrid[1][9], SVSB);
    //affichage des lignes entre les lignes à caractères
    printf("  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", SVLB, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SVRB);
    //affichage de la ligne avec caractère
    printf("c %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c\n", SVSB, emptygrid[2][0], SVSB, emptygrid[2][1], SVSB, emptygrid[2][2], SVSB, emptygrid[2][3], SVSB, emptygrid[2][4], SVSB, emptygrid[2][5], SVSB, emptygrid[2][6], SVSB, emptygrid[2][7], SVSB, emptygrid[2][8], SVSB, emptygrid[2][9], SVSB);
    //affichage des lignes entre les lignes à caractères
    printf("  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", SVLB, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SVRB);
    //affichage de la ligne avec caractère
    printf("d %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c\n", SVSB, emptygrid[3][0], SVSB, emptygrid[3][1], SVSB, emptygrid[3][2], SVSB, emptygrid[3][3], SVSB, emptygrid[3][4], SVSB, emptygrid[3][5], SVSB, emptygrid[3][6], SVSB, emptygrid[3][7], SVSB, emptygrid[3][8], SVSB, emptygrid[3][9], SVSB);
    //affichage des lignes entre les lignes à caractères
    printf("  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", SVLB, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SVRB);
    //affichage de la ligne avec caractère
    printf("e %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c\n", SVSB, emptygrid[4][0], SVSB, emptygrid[4][1], SVSB, emptygrid[4][2], SVSB, emptygrid[4][3], SVSB, emptygrid[4][4], SVSB, emptygrid[4][5], SVSB, emptygrid[4][6], SVSB, emptygrid[4][7], SVSB, emptygrid[4][8], SVSB, emptygrid[4][9], SVSB);
    //affichage des lignes entre les lignes à caractères
    printf("  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", SVLB, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SVRB);
    //affichage de la ligne avec caractère
    printf("f %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c\n", SVSB, emptygrid[5][0], SVSB, emptygrid[5][1], SVSB, emptygrid[5][2], SVSB, emptygrid[5][3], SVSB, emptygrid[5][4], SVSB, emptygrid[5][5], SVSB, emptygrid[5][6], SVSB, emptygrid[5][7], SVSB, emptygrid[5][8], SVSB, emptygrid[5][9], SVSB);
    //affichage des lignes entre les lignes à caractères
    printf("  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", SVLB, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SVRB);
    //affichage de la ligne avec caractère
    printf("g %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c\n", SVSB, emptygrid[6][0], SVSB, emptygrid[6][1], SVSB, emptygrid[6][2], SVSB, emptygrid[6][3], SVSB, emptygrid[6][4], SVSB, emptygrid[6][5], SVSB, emptygrid[6][6], SVSB, emptygrid[6][7], SVSB, emptygrid[6][8], SVSB, emptygrid[6][9], SVSB);
    //affichage des lignes entre les lignes à caractères
    printf("  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", SVLB, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SVRB);
    //affichage de la ligne avec caractère
    printf("h %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c\n", SVSB, emptygrid[7][0], SVSB, emptygrid[7][1], SVSB, emptygrid[7][2], SVSB, emptygrid[7][3], SVSB, emptygrid[7][4], SVSB, emptygrid[7][5], SVSB, emptygrid[7][6], SVSB, emptygrid[7][7], SVSB, emptygrid[7][8], SVSB, emptygrid[7][9], SVSB);
    //affichage des lignes entre les lignes à caractères
    printf("  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", SVLB, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SVRB);
    //affichage de la ligne avec caractère
    printf("i %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c\n", SVSB, emptygrid[8][0], SVSB, emptygrid[8][1], SVSB, emptygrid[8][2], SVSB, emptygrid[8][3], SVSB, emptygrid[8][4], SVSB, emptygrid[8][5], SVSB, emptygrid[8][6], SVSB, emptygrid[8][7], SVSB, emptygrid[8][8], SVSB, emptygrid[8][9], SVSB);
    //affichage des lignes entre les lignes à caractères
    printf("  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", SVLB, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SC, SHSB, SVRB);
    //affichage de la ligne avec caractère
    printf("j %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c  %d  %c\n", SVSB, emptygrid[9][0], SVSB, emptygrid[9][1], SVSB, emptygrid[9][2], SVSB, emptygrid[9][3], SVSB, emptygrid[9][4], SVSB, emptygrid[9][5], SVSB, emptygrid[9][6], SVSB, emptygrid[9][7], SVSB, emptygrid[9][8], SVSB, emptygrid[9][9], SVSB);
    //affichage de la dernière ligne du tableau
    printf("  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", SBLC, SHSB, SHBB, SHSB, SHBB, SHSB, SHBB, SHSB, SHBB, SHSB, SHBB, SHSB, SHBB, SHSB, SHBB, SHSB, SHBB, SHSB, SHBB, SHSB, SBRC);
    //affichage de la légende de la grille
    printf("0 : aucune info sur la case\n");
    printf("1 : case ciblee, avec un bateau\n");
    printf("2 : case ciblee, vide\n");
}

/**
 *fonction permettant à l'ordinateur de choisir la grille pour le joueur et l'IA (1 seule possibilité en version 0.1) et de creer le tableau associe
 */
void grilleChoisie(){
    //Sélection de la grille (fixe en v0.1)
    int grille[NBCOLONNE][NBLIGNE] = GRID1;
    //variables pour les boucles for
    int ligne=0;
    int colonne=0;
    //boucle pour assigner les valeurs de la grille aux cases des tableaux joueur et IA
    for (ligne=0;ligne<10;ligne++){
        for (colonne=0;colonne<10;colonne++){
            //création de la grille avec les bateaux du joueur
            grilleJoueur[colonne][ligne]=grille[colonne][ligne];
            //création de la grille avec les bateaux de l'IA
            grilleIA[colonne][ligne]=grille[colonne][ligne];
        }
    }
}