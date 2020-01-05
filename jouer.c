//
// Created by Paola.COSTA on 17.12.2019.
//

#include "jouer.h"
#include "global.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * fonction permettant à l'utilisateur de sélectionner l'aciton à effectuer au lancement : afficher l'aide, jouer ou quitter.
 */
int lancer() {
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
};

/**
 * fonction principale du jeu, qui englobe tout le fonctionnement du jeu
 */
int jouer() {
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
    return numeroTour;
};

/**
 * fonction permettant de définir ce qui se passe lors du tour de l'IA
 */
void tourIA(int noTour) {
    char caseIA[2] = {' ', ' '};
    printf("Tour numero %d : a l'IA de jouer\n", noTour);
    affichageGrille();
    system("pause");
};

/**
 * fonction permettant de vérifier si un bateau est coulé si une des cases contenant un bateau est touché
 * @param personneJouant
 */
void checkCoule(int personneJouant) {

};

/**
  * fonction permettant de définir ce qui se passe lors du tour du joueur
  * @param noTour
 */
void tourJoueur(int noTour) {
    char emplacement[2] = {' ', ' '};
    int joueur = 0;
    int IA = 1;
    printf("Tour numero %d : au joueur de jouer\n", noTour);
    affichageGrille();
    fflush(stdin);
    printf("Quelle ligne souhaitez-vous attaquer ? (a-j)\n");
    scanf("%c", &emplacement[0]);
    fflush(stdin);
    printf("Quelle colonne souhaitez-vous attaquer ? (0-9)\n");
    scanf("%c", &emplacement[1]);
    switch (emplacement[0]) {
        case 'a':
            switch (emplacement[1]) {
                case '0':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[0][0] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '1':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[1][0] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '2':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[2][0] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '3':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[3][0] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '4':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[4][0] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '5':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[5][0] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '6':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[6][0] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '7':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[7][0] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '8':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[8][0] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '9':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[9][0] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                default:
                    printf("Cette valeur n'est pas dans le tableau, veuillez en choisir une autre, en debutant par la lettre.\n");
                    system("pause");
                    tourJoueur(noTour);
                    break;
            }
        case 'b':
            switch (emplacement[1]) {
                case '0':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[0][1] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '1':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[1][1] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '2':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[2][1] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '3':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[3][1] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '4':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[4][1] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '5':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[5][1] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '6':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[6][1] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '7':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[7][1] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '8':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[8][1] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '9':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[9][1] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;

                default:
                    printf("Cette valeur n'est pas dans le tableau, veuillez en choisir une autre, en debutant par la lettre.\n");
                    system("pause");
                    tourJoueur(noTour);
                    break;
            }
        case 'c':
            switch (emplacement[1]) {
                case '0':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[0][2] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '1':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[1][2] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '2':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[2][2] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '3':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[3][2] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '4':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[4][2] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '5':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[5][2] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '6':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[6][2] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '7':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[7][2] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '8':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[8][2] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '9':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[9][2] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                default:
                    printf("Cette valeur n'est pas dans le tableau, veuillez en choisir une autre, en debutant par la lettre.\n");
                    system("pause");
                    tourJoueur(noTour);
                    break;
            }
        case 'd':
            switch (emplacement[1]) {
                case '0':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[0][3] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '1':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[1][3] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '2':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[2][3] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '3':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[3][3] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '4':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[4][3] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '5':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[5][3] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '6':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[6][3] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '7':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[7][3] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '8':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[8][3] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '9':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[9][3] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                default:
                    printf("Cette valeur n'est pas dans le tableau, veuillez en choisir une autre, en debutant par la lettre.\n");
                    system("pause");
                    tourJoueur(noTour);
                    break;
            }
        case 'e':
            switch (emplacement[1]) {
                case '0':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[0][4] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '1':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[1][4] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '2':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[2][4] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '3':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[3][4] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '4':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[4][4] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '5':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[5][4] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '6':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[6][4] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '7':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[7][4] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '8':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[8][4] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '9':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[9][4] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;

                default:
                    printf("Cette valeur n'est pas dans le tableau, veuillez en choisir une autre, en debutant par la lettre.\n");
                    system("pause");
                    tourJoueur(noTour);
                    break;
            }
        case 'f':
            switch (emplacement[1]) {
                case '0':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[0][5] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '1':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[1][5] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '2':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[2][5] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '3':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[3][5] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '4':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[4][5] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '5':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[5][5] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '6':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[6][5] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '7':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[7][5] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '8':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[8][5] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '9':
                    printf("Case choisie : %c%c\n", emplacement[0], emplacement[1]);
                    if (grilleJoueur[9][5] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;

                default:
                    printf("Cette valeur n'est pas dans le tableau, veuillez en choisir une autre, en debutant par la lettre.\n");
                    system("pause");
                    tourJoueur(noTour);
                    break;
            }
        case 'g':
            switch (emplacement[1]) {
                case '0':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[0][6] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '1':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[1][6] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '2':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[2][6] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '3':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[3][6] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '4':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[4][6] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '5':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[5][6] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '6':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[6][6] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '7':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[7][6] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '8':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[8][6] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '9':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[9][6] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                default:
                    printf("Cette valeur n'est pas dans le tableau, veuillez en choisir une autre, en debutant par la lettre.\n");
                    system("pause");
                    tourJoueur(noTour);
                    break;
            }
        case 'h':
            switch (emplacement[1]) {
                case '0':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[0][7] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '1':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[1][7] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '2':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[2][7] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '3':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[3][7] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '4':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[4][7] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '5':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[5][7] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '6':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[6][7] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '7':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[7][7] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '8':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[8][7] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '9':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[9][7] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                default:
                    printf("Cette valeur n'est pas dans le tableau, veuillez en choisir une autre, en debutant par la lettre.\n");
                    system("pause");
                    tourJoueur(noTour);
                    break;
            }
        case 'i':
            switch (emplacement[1]) {
                case '0':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[0][8] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '1':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[1][8] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '2':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[2][8] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '3':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[3][8] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '4':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[4][8] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '5':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[5][8] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '6':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[6][8] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '7':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[7][8] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '8':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[8][8] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '9':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[9][8] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                default:
                    printf("Cette valeur n'est pas dans le tableau, veuillez en choisir une autre, en debutant par la lettre.\n");
                    system("pause");
                    tourJoueur(noTour);
                    break;
            }
        case 'j':
            switch (emplacement[1]) {
                case '0':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[0][9] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '1':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[1][9] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '2':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[2][9] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);

                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '3':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[3][9] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '4':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[4][9] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '5':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[5][9] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '6':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[6][9] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '7':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[7][9] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '8':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[8][9] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                case '9':
                    printf("Case choisie : %c%c\n", emplacement[0],
                           emplacement[1]);
                    if (grilleJoueur[9][9] == 1) {
                        printf("Touche\n");
                        checkCoule(joueur);
                    } else {
                        printf("A l'eau\n");
                    }
                    system("pause");
                    break;
                default:
                    printf("Cette valeur n'est pas dans le tableau, veuillez en choisir une autre, en debutant par la lettre.\n");
                    system("pause");
                    tourJoueur(noTour);
                    break;
            }
        default:
            printf("Cette valeur n'est pas dans le tableau, veuillez en choisir une autre, en debutant par la lettre.\n");
            system("pause");
            fflush(stdin);
            tourJoueur(noTour);
            break;
    }
}