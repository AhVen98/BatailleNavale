//
// Created by Paola.COSTA on 10.12.2019.
//
#ifndef BATTLESHIP_GLOBAL_H
#define BATTLESHIP_GLOBAL_H

#include "grille.h"
#include "jouer.h"
#include "aide.h"

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
 * déclaration de la longueur des tableaux 2D
 */
#define NBLIGNE 10
#define NBCOLONNE 10
/**
 *Définition des grilles de jeu
 */
#define GRID1 {/*ligne1*/ 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, /*ligne2*/ 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, /*ligne3*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /*ligne4*/ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, /*ligne5*/ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, /*ligne6*/ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, /*ligne7*/ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, /*ligne8*/ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, /*ligne9*/ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, /*ligne10*/ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1}
int emptygrid[NBCOLONNE][NBLIGNE];
int grilleJoueur[NBCOLONNE][NBLIGNE];
int grilleIA[NBCOLONNE][NBLIGNE];

/**
 * Définition des différentes grilles de la partie
 *                bateau à 2      bateau à 3          bateau à 4              bateau à 5
 */
#define GRID_1     A2, A3,         C5, C6, C7,         F1, F2, F3, F4,         A8, B8, C8, D8, E8


#endif //BATTLESHIP_GLOBAL_H
