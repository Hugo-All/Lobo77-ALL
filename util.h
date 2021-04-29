#ifndef INCLUDE_UTIL_H
#define INCLUDE_UTIL_H
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

#include "declarations.h"
#include "affichage.h"

enum E_couleurs{NOIR,
            BLEU_FONCE,
            VERT_FONCE,
            TURQUOISE,
            ROUGE_FONCE,
            VIOLET,
            VERT_OIE,
            GRIS_CLAIR,
            GRIS_FONCE,
            BLEU,
            VERT,
            TURQUOISE_2,
            ROUGE,
            VIOLET_2,
            JAUNE,
            BLANC
            };
typedef enum E_couleurs couleurs;

void color (int couleurDuTexte, int couleurDuFond);

int attend_touche(int timeout);
char get_touche();
void gets_limite(char *sortie, int limite);

int get_joueur_actuel(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);
int get_donneur(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);

int joueur_suivant(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);
int donneur_suivant(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);

void melanger_pile(int cartes[DIM_pile], int nb_cartes);//Mélange les nb_cartes premières cartes d'une pile

int selectionner_carte(S_joueur joueurs[NB_max_joueurs], S_joueur joueur, int nb_joueurs, int total_defausse);

int nb_cartes_joueur(S_joueur joueur);
int nb_joueur_valide(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);

void retirer_jeton(S_joueur *joueur);
#endif
