//
// Created by Paola.COSTA on 17.12.2019.
//

#include "jouer.h"
#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * fonction principale du jeu, qui englobe tout le fonctionnement du jeu
 */
void jouer() {
    //variable pour la boucle for afin de determiner si c'est le tour du joueur ou de l'IA
    int tour = 0;
    int numeroTour;
    grilleChoisie();
    for (tour = 0; tour < 200; tour++) {
        if (tour % 2 == 0) {
            //enregistrement du numero du tour dans une variable
            numeroTour = tour / 2 + 1;
            tourJoueur(numeroTour);
        } else {
            //enregistrement du numero du tour dans une variable
            numeroTour = (tour + 1) / 2;
            tourIA(numeroTour);
        }
    }
    affichageGrille();
}

/**
 * fonction permettant de définir ce qui se passe lors du tour de l'IA
 * @param noTour
 */
void tourIA(int noTour) {
    int numLigne = rand()%10;
    int numColonne = rand()%10;
    printf("Tour numero %d : a l'IA de jouer\n", noTour);
    printf("Case ciblee : %c%d\n", numLigne+97, numColonne);
    message(RETOURLIGNE);
	//check si la case ciblée contient un bateau ou non
    checkBateau(IA, numLigne, numColonne, noTour);
    system("pause");
}

/**
 * fonction permettant de définir ce qui se passe lors du tour du joueur
 * @param noTour
 */
void tourJoueur(int noTour) {
    char emplacement[2] = {' ', ' '};
    printf("Tour numero %d : au joueur de jouer\n", noTour);
    affichageGrille();
    fflush(stdin);
    message(ATTAQUE);
    scanf("%c%d", &emplacement[0], &emplacement[1]);
    fflush(stdin);
    printf("Case choisie : %c%d\n", emplacement[0], emplacement[1]);
    int numligne = emplacement[0]-97;
    int numcolonne = emplacement[1];
    int valide = checkValidite(noTour, numligne, numcolonne);
    if (valide == VRAI){
        checkBateau(JOUEUR, numligne, numcolonne, noTour);
    }
    //check si la case contient un bateau ou pas sur la grille de l'IA (valeur == à 1, 2, 3, 4 ou 5 selon le bateau)
    system("pause");
    fflush(stdin);
    system("cls");
}