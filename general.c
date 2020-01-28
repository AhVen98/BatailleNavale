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
        message(PAGE);
        scanf("%d", &action);
        switch (action) {
            case 1 :
                system("cls");
                jouer();
                break;
            case 2 :
                system("cls");
                message(AIDE);
                lancer();
                break;
            case 3:
                system("cls");
                continuer = 0;
                break;
            case 4:
                system("cls");
                message(LOGIN);
                login();
                break;
            case 5:
                score();
                lancer();
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
        case BIENVENUE:
            printf("BattleShip\n");
            printf("May the luck be with you in your game\n");
            break;

        //message pour le choix de la page à afficher
        case PAGE:
            printf("Qu'est-ce que tu comptes faire ? jouer (1), afficher l'aide (2), quitter (3), se logger (4) ou afficher l'historique des scores (5)?\n");
            break;

        //affichage de l'aide
        case AIDE:
            printf("Comment jouer : \n");
            printf("- Il y a 5 bateaux caches dans une grille 10 par 10.\n");
            printf("- Il y a 1 bateau de 2 cases, 2 de 3 cases, 1 de 4 cases et 1 de 5 cases. Pour gagner, il faut tous les detruire.\n");
            printf("- On detruit un bateau en ayant cible toutes les cases sur lequel il est situe.\n");
            printf("- Pour cibler une case, lors de ton tour, ecrit la lettre (A-J) et le numero (1-10) associe a la case puis valider.\n");
            printf("La personne qui joue change apres chaque case ciblee, peu importe si un bateau a ete touche ou pas.\n");
            break;

        //case à attaquer
        case ATTAQUE:
            printf("Quelle case souhaitez-vous attaquer ? (a-j et 0-9)\n");
            break;

        //case non existante, il faut en cibler une autre
        case NA:
            printf("Cette valeur n'est pas ciblable. Choississez-en une autre, situee entre a et j, ainsi que 0 et 9.\n");

        //bateau touché
        case TOUCHE:
            printf("Touche ");
            break;

        //bateau coulé
        case COULE:
            printf("coule\n");
            break;

        //a l'eau
        case ALEAU:
            printf("A l'eau\n");
            break;

        //retour à la ligne
        case RETOURLIGNE:
            printf("\n");
            break;

        //victoire
        case GAGNE:
            printf("Felicitations, vous avez gagne la partie.\n");
            break;

        //défaite
        case PERDU:
            printf("Dommage, vous avez perdu. Peut-être une prochaine fois.");
            break;

        //se logger avec un pseudo
        case LOGIN:
            printf("Veuillez entrer votre pseudo : ");
            break;

        //afficher l'historique des parties
        case HISTORIQUE:
            printf("Voici l'historique des parties et le score correspondant : \n");
            break;

        default:
            break;
    }
}

/**
 * fonction permettant d'afficher l'historique des scores des autres parties
 */
void score(){
    message(HISTORIQUE);
    char i;
    FILE * scoresFichier;
    scoresFichier = fopen("scores_history.txt", "r");
    i = fgetc(scoresFichier);
    while(i!=EOF)
    {
        printf ("%c", i);
        i = fgetc(scoresFichier);
    }
    fclose(scoresFichier);
    system("pause");
}

/**
 * fonction permettant de checker la validité de la valeur entrée par le joueur pour l'emplacement
 * @param tour
 * @param ligne
 * @param colonne
 * @return si la case sélectionnée est effectivement présente dans la grille ou pas
 */
int checkValidite(int tour, int ligne, int colonne){
    int validite ;
    if ((ligne > 9) || (colonne > 9) || (ligne<0) || (colonne<0)){
        message(NA);
        validite = FAUX;
        tourJoueur(tour);
    }
    else{
        validite=VRAI;
    }
    return validite;
}

/**
 * fonction permettant de check s'il y a un bateau sur la case ciblée
 * @param personne
 * @param ligne
 * @param colonne
 * @param tour
 */
void checkBateau(int personne, int ligne, int colonne, int tour){
    int presenceBateau=-1;
    FILE * logsFichier;
    logsFichier = fopen("logs.txt", "a");
    if (personne == IA){
        //check si la case a déjà été ciblé par l'IA auparavant, relance le tour si oui
        if (grilleJoueur[ligne][colonne]==8){
            tourIA(tour);
        }
        //check si la case contient un bateau ou pas sur la grille du joueur (valeur == à 1, 2, 3, 4 ou 5, variable selon le bateau)
        else if (    (grilleJoueur[ligne][colonne]==1)
            ||  (grilleJoueur[ligne][colonne]==2)
            ||  (grilleJoueur[ligne][colonne]==3)
            ||  (grilleJoueur[ligne][colonne]==4)
            ||  (grilleJoueur[ligne][colonne]==5)){
            printf("Touche en %c%d ", ligne+97, colonne);
            fprintf(logsFichier, "L'IA touche en %c%d au tour %d\n", ligne+97, colonne, tour);
            //assigne la valeur a la variable touche, pour le checkCoule()
            presenceBateau = grilleIA[ligne][colonne];
            grilleJoueur[ligne][colonne]= 8;
            //si le bateau est touché, check chez le joueur si le bateau est coulé
            checkCoule(IA , presenceBateau);
        }
        else {
            printf("A l'eau en %c%d\n", ligne+97, colonne);
        }
    }
    else{
        if (    (grilleIA[ligne ][colonne]==1)
            ||  (grilleIA[ligne][colonne]==2)
            ||  (grilleIA[ligne][colonne]==3)
            ||  (grilleIA[ligne][colonne]==4)
            ||  (grilleIA[ligne][colonne]==5)){
            message(TOUCHE);
            fprintf(logsFichier, "Le joueur touche en %c%d au tour %d.\n", ligne+97, colonne, tour);
            presenceBateau = grilleIA[ligne][colonne];
            emptygrid[ligne][colonne]=1;
            grilleIA[ligne][colonne]= 8;
            //si le bateau est touché, check chez l'IA si le bateau est coulé
            checkCoule(JOUEUR, presenceBateau);
        }
        //check si la case a deja ete ciblee par le joueur. si oui, le dis et fais rejouer
        else if (grilleIA[ligne][colonne]==8){
            message(NA);
            tourJoueur(tour);
        }
        else {
            emptygrid[ligne][colonne]=2;
            message(ALEAU);
        }
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
    FILE * logsFichier;
    logsFichier = fopen("logs.txt", "a");
    if (personneJouant == JOUEUR) {
        for (nligne = 0; nligne < NBLIGNE; nligne++) {
            for (ncolonne = 0; ncolonne < NBCOLONNE; ncolonne++) {
                if (grilleIA[ncolonne][nligne] == numBateau) {
                    message(RETOURLIGNE);
                    partieBateauRestants = 1;
                    nligne = NBLIGNE;
                    ncolonne = NBCOLONNE;
                }
            }
        }
        if (partieBateauRestants == 0) {
            message(COULE);
            fprintf(logsFichier, "Le joueur coule le bateau.\n");
            checkFini();
        }
    } else {
        for (nligne = 0; nligne < NBLIGNE; nligne++) {
            for (ncolonne = 0; ncolonne < NBCOLONNE; ncolonne++) {
                if (grilleJoueur[ncolonne][nligne] == numBateau) {
                    message(RETOURLIGNE);
                    partieBateauRestants = 1;
                    nligne = NBLIGNE;
                    ncolonne = NBCOLONNE;
                }
            }
        }
        if (partieBateauRestants == 0) {
            message(COULE);
            fprintf(logsFichier, "L'IA coule le bateau.\n");
            checkFini();
        }
        message(RETOURLIGNE);
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
    FILE * logsFichier;
    FILE * scoresFichier;
    logsFichier = fopen("logs.txt", "a");
    scoresFichier = fopen("scores_history.txt", "a");
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
        message(GAGNE);
        fprintf(logsFichier, "Le joueur a gagne la partie !!! Felicitations.\n");
        fprintf(scoresFichier, "%s : 500points.\n");
        system("pause");
        lancer();
    }
    else if(bateauJoueur==0){
        message(PERDU);
        fprintf(logsFichier, "L'IA a gagne la partie !!! Dommage, ca sera pour une prochaine fois.\n");
        fprintf(scoresFichier, "%s : 0points.\n");
        system("pause");
        lancer();
    }
    else{
        message(RETOURLIGNE);
    }
}

/**
 * fonction permettant au joueur d'écrire son pseudo
 */
void login(){
    int i =0;
    fflush(stdin);
    scanf("%s", &pseudo);
    for(i=0;i<15;i++){
        printf("%c", pseudo[i]);
    }
    system("pause");
    lancer();
}