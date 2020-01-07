//
// Created by Paola.COSTA on 17.12.2019.
//

#include "jouer.h"
#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * fonction permettant à l'utilisateur de sélectionner l'action à effectuer au lancement : afficher l'aide, jouer ou quitter le processus.
 */
int lancer() {
    srand(time(NULL));
    int continuer = 1;
    printf("BattleShip\n");
    while (continuer == 1) {
        int action;
        printf("Qu'est-ce que tu comptes faire ? jouer (1), afficher l'aide (2) ou quitter (3) ?\n");
        scanf("%d", &action);
        switch (action) {
            case 1 :
                jouer();
                break;
            case 2 :
                aide();
                lancer();
                break;
            case 3:
                continuer = 0;
                break;
            default:
                fflush(stdin);
                lancer();
                break;
        }
        fflush(stdin);
    }
    return 0;
}

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
    //variable qui permettra a la fonction checkCoule() de savoir qu'il s'agit de l'IA
    int IA = 1;
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
    int joueur = 0;
    int bateau=0;
    printf("Tour numero %d : au joueur de jouer\n", noTour);
    affichageGrille();
    fflush(stdin);
    printf("Quelle case souhaitez-vous attaquer ? (a-j et 0-9)\n");
    scanf("%c%d", &emplacement[0], &emplacement[1]);
    fflush(stdin);
    printf("Case choisie : %c%d\n", emplacement[0], emplacement[1]);
    int numligne = emplacement[0]-97;
    int numcolonne = emplacement[1];
    //check si les valeurs données sont bien dans le tableau
    if (numligne >= 10 || numcolonne >=10){
        printf("Cette valeur n'est pas presente dans le tableau. ciblez entre a et j, ainsi que 0 et 9.\n");
        tourJoueur(noTour);
    }

    //check si la case contient un bateau ou pas sur la grille de l'IA (valeur == à 1, 2, 3, 4 ou 5 selon le bateau)
    if (grilleIA[numligne][numcolonne]==1 || grilleIA[numligne][numcolonne]==2 ||grilleIA[numligne][numcolonne]==3 ||grilleIA[numligne][numcolonne]==4 ||grilleIA[numligne][numcolonne]==5){
        printf("Touche ");
        bateau = grilleIA[numligne][numcolonne];
        emptygrid[numligne][numcolonne]=1;
        grilleIA[numligne][numcolonne]= 8;
        //si le bateau est touché, check chez l'IA si le bateau est coulé
        checkCoule(joueur, bateau);
    }
        //check si la case a deja ete ciblee par le joueur. si oui, le dis et fais rejouer
    else if (grilleIA[numligne][numcolonne]==8){
        printf("Cette case a deja ete attaquee, choissisez-en une autre.");
        tourJoueur(noTour);
    }
    else {
        emptygrid[numligne][numcolonne]=2;
        printf("A l'eau\n");
    }
    system("pause");
    fflush(stdin);
}

/**
 * fonction permettant de vérifier si un bateau est coulé si une des cases contenant un bateau est touché
 * @param personneJouant
 * @param numBateau
 */
void checkCoule(int personneJouant, int numBateau) {
    int nligne = 0;
    int ncolonne = 0;
    int partieBateauRestants = 0;
    if (personneJouant == 0) {
        for (nligne = 0; nligne < NBLIGNE; nligne++) {
            for (ncolonne = 0; ncolonne < NBCOLONNE; ncolonne++) {
                if (grilleIA[ncolonne][nligne] == numBateau) {
                    printf("\n");
                    partieBateauRestants = 1;
                    nligne = NBLIGNE;
                    ncolonne = NBCOLONNE;
                }
            }
        }
        if (partieBateauRestants == 0) {
            printf("coule \n");
            checkFini();
        }
    } else {
        for (nligne = 0; nligne < NBLIGNE; nligne++) {
            for (ncolonne = 0; ncolonne < NBCOLONNE; ncolonne++) {
                if (grilleJoueur[ncolonne][nligne] == numBateau) {
                    printf("\n");
                    partieBateauRestants = 1;
                    nligne = NBLIGNE;
                    ncolonne = NBCOLONNE;
                }
            }
        }
        if (partieBateauRestants == 0) {
            printf("Coule \n");
            checkFini();
        }
        printf("\n");
    }
}

/**
 * fonction permettant ä l'ordinateur de verifier, une fois un bateau coule, si un des deux joueurs a gagne
 */
void checkFini(){
    int nligne =0;
    int ncolonne = 0;
    int bateauIA=0;
    int bateauJoueur=0;
    for (nligne = 0; nligne < NBLIGNE; nligne++) {
        for (ncolonne = 0; ncolonne < NBCOLONNE; ncolonne++) {
            if(grilleIA[nligne][ncolonne]!=0 || grilleIA[nligne][ncolonne]!=8){
                bateauJoueur+=1;
            }
            if (grilleJoueur[nligne][ncolonne]!=0 || grilleJoueur[nligne][ncolonne]!=8){
                bateauIA+=1;
            }
        }
    }
    if (bateauIA ==0){
        printf("Felicitations, vous avez gagne la partie.\n");
        system("pause");
        lancer();
    }
    else if(bateauJoueur==0){
        printf("Dommage, vous avez perdu. Peut-être une prochaine fois.");
        system("pause");
        lancer();
    }
    else{
        printf("\n");
    }
}