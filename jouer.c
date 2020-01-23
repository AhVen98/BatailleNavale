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
    //variable qui va recuperer la valeur de la case attaquee et la transmettre a checkCoule() afin de determiner si le bateau correspondant est coule
    int bateau;
    printf("Tour numero %d : a l'IA de jouer\n", noTour);
    int numLigne = rand()%10;
    int numColonne = rand()%10;
    //check que les valeurs soient bien comprises entre 0 et 9, sinon, relance le tour pour l'IA
    if (numLigne >= 10 || numColonne >=10){
        tourIA(noTour);
    }
    //check si la case contient un bateau ou pas sur la grille du joueur (valeur == à 1, 2, 3, 4 ou 5, variable selon le bateau)
    if (grilleJoueur[numLigne][numColonne]==1 || grilleJoueur[numLigne][numColonne]==2 ||grilleJoueur[numLigne][numColonne]==3 ||grilleJoueur[numLigne][numColonne]==4 ||grilleJoueur[numLigne][numColonne]==5){
        printf("Touche en %c%d ", numLigne+97, numColonne);
        //assigne la valeur a la variable bateau, pour le checkCoule()
        bateau = grilleIA[numLigne][numColonne];
        grilleJoueur[numLigne][numColonne]= 8;
        //si le bateau est touché, check chez le joueur si le bateau est coulé
        checkCoule(IA , bateau);
    }
    else if (grilleJoueur[numLigne][numColonne]==8){
        tourIA(noTour);
    }
    else {
        printf("A l'eau en %c%d\n", numLigne+97, numColonne);
    }
    system("pause");
};

/**
 * fonction permettant de définir ce qui se passe lors du tour du joueur
 * @param noTour
 */
void tourJoueur(int noTour) {
    char emplacement[2] = {' ', ' '};
    int bateau=0;
    printf("Tour numero %d : au joueur de jouer\n", noTour);
    affichageGrille();
    fflush(stdin);
    message(ATTAQUE);
    scanf("%c%d", &emplacement[0], &emplacement[1]);
    fflush(stdin);
    printf("Case choisie : %c%d\n", emplacement[0], emplacement[1]);
    int numligne = emplacement[0]-97;
    int numcolonne = emplacement[1];
    //check si les valeurs données sont bien dans le tableau
    if (numligne >= 10 || numcolonne >=10){
        message(NA);
        tourJoueur(noTour);
    }

    //check si la case contient un bateau ou pas sur la grille de l'IA (valeur == à 1, 2, 3, 4 ou 5 selon le bateau)
    if (grilleIA[numligne][numcolonne]==1 || grilleIA[numligne][numcolonne]==2 ||grilleIA[numligne][numcolonne]==3 ||grilleIA[numligne][numcolonne]==4 ||grilleIA[numligne][numcolonne]==5){
        message(TOUCHE);
        bateau = grilleIA[numligne][numcolonne];
        emptygrid[numligne][numcolonne]=1;
        grilleIA[numligne][numcolonne]= 8;
        //si le bateau est touché, check chez l'IA si le bateau est coulé
        checkCoule(JOUEUR, bateau);
    }
        //check si la case a deja ete ciblee par le joueur. si oui, le dis et fais rejouer
    else if (grilleIA[numligne][numcolonne]==8){
        message(NA);
        tourJoueur(noTour);
    }
    else {
        emptygrid[numligne][numcolonne]=2;
        message(ALEAU);
    }
    system("pause");
    fflush(stdin);
    system("cls");
}

