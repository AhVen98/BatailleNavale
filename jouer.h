//
// Created by Paola.COSTA on 17.12.2019.
//

#ifndef BATTLESHIP_JOUER_H
#define BATTLESHIP_JOUER_H
int lancer();
void jouer();
void tourJoueur(int noTour);
void tourIA(int noTour);
void checkCoule(int personneJouant, int numBateau);
void checkFini();
#endif //BATTLESHIP_JOUER_H