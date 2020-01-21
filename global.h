//
// Created by Paola.COSTA on 10.12.2019.
//
#ifndef BATTLESHIP_GLOBAL_H
#define BATTLESHIP_GLOBAL_H

#include "grille.h"
#include "jouer.h"
#include "general.h"

/**
 * Déclaration des différentes constantes en ASCII étendu (appel par %c) pour pouvoir afficher une grille dans la console
 */
#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC 197 // ┼, Single Center
/**
 * déclaration de la taille des tableaux
 */
#define NBLIGNE 10
#define NBCOLONNE 10
/**
 *Définition des grilles de jeu
 */
#define GRID1 { /*ligne a*/ 0, 0, 0, 0, 2, 2, 2, 0, 0, 0,\
                /*ligne b*/ 3, 3, 3, 0, 0, 0, 0, 0, 1, 0,\
                /*ligne c*/ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,\
                /*ligne d*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
                /*ligne e*/ 0, 0, 0, 0, 0, 0, 0, 5, 0, 0,\
                /*ligne f*/ 0, 0, 0, 4, 0, 0, 0, 5, 0, 0,\
                /*ligneg */ 0, 0, 0, 4, 0, 0, 0, 5, 0, 0,\
                /*ligne h*/ 0, 0, 0, 4, 0, 0, 0, 5, 0, 0,\
                /*ligne i*/ 0, 0, 0, 4, 0, 0, 0, 5, 0, 0,\
                /*ligne j*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0\
                          /*0  1  2  3  4  5  6  7  8  9*/}
//grille vide sur lequel les coups du joueur s'affiche à l'écran
int emptygrid[NBCOLONNE][NBLIGNE];
//grille contenant la position des bateaux du joueur et sur laquelle l'ordinateur check les bateaux coules
int grilleJoueur[NBCOLONNE][NBLIGNE];
//grille contenant la position des bateaux de l'IA et sur laquelle l'ordinateur check les bateaux coules
int grilleIA[NBCOLONNE][NBLIGNE];

#endif //BATTLESHIP_GLOBAL_H