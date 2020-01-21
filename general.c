//
// Created by Paola.COSTA on 21.01.2020.
//

#include "general.h"
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
    while (continuer == 1) {
        int action;
        message(1);
        scanf("%d", &action);
        switch (action) {
            case 1 :
                system("cls");
                jouer();
                break;
            case 2 :
                system("cls");
                message(2);
                lancer();
                break;
            case 3:
                system("cls");
                continuer = 0;
                break;
            default:
                fflush(stdin);
                system("cls");
                lancer();
                break;
        }
        fflush(stdin);
    }
    return 0;
}

/**
 * fonction pour afficher les différents messages selon la situation
 * @param action
 */
void message(int action){
    switch(action){
        //message de bienvenue
        case 0:
            printf("BattleShip\n");
            printf("May the luck be with you in your game\n");
            break;
            //message pour le choix de la page à afficher
        case 1:
            printf("Qu'est-ce que tu comptes faire ? jouer (1), afficher l'aide (2) ou quitter (3) ?\n");
            break;
            //affichage de l'aide
        case 2:
            printf("Comment jouer : \n");
            printf("- Il y a 5 bateaux caches dans une grille 10 par 10.\n");
            printf("- Il y a 1 bateau de 2 cases, 2 de 3 cases, 1 de 4 cases et 1 de 5 cases. Pour gagner, il faut tous les detruire.\n");
            printf("- On detruit un bateau en ayant cible toutes les cases sur lequel il est situe.\n");
            printf("- Pour cibler une case, lors de ton tour, ecrit la lettre (A-J) et le numero (1-10) associe a la case puis valider.\n");
            printf("La personne qui joue change apres chaque case ciblee, peu importe si un bateau a ete touche ou pas.\n");

            //case à attaquer
        case 3:
            printf("Quelle case souhaitez-vous attaquer ? (a-j et 0-9)\n");
            break;
            //case non existante, il faut en cibler une autre
        case 4:
            printf("Cette valeur n'est pas ciblable. Choississez-en une autre, situee entre a et j, ainsi que 0 et 9.\n");
            //bateau touché
        case 5:
            printf("Touche ");
            break;
            //bateau coulé
        case 6:
            printf("coule\n");
            break;
            //a l'eau
        case 7:
            printf("A l'eau\n");
            break;
            //retour à la ligne
        case 8:
            printf("\n");
            break;
        default:
            break;
    }
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
            message(6);
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
            message(6);
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