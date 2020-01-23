//
// Created by Paola.COSTA on 21.01.2020.
//

#ifndef BATTLESHIP_GENERAL_H
#define BATTLESHIP_GENERAL_H
int lancer();
void message(int action);
int checkValidite(int tour, int ligne, int colonne);
void checkBateau(int personne, int ligne, int colonne, int tour);
void checkCoule(int personneJouant, int numBateau);
void checkFini();
void logs(int action, int personne);
void login();
#endif //BATTLESHIP_GENERAL_H
