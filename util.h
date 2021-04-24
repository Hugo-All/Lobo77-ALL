#ifndef INCLUDE_UTIL_H
#define INCLUDE_UTIL_H
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void gets_limite(char *sortie, int limite);

void melanger_pile(int cartes[DIM_pile],char nb_cartes);//Mélange les nb_cartes premières cartes d'une pile

int attend_touche(int timeout);

int selectionner_carte(S_joueur joueurs[NB_max_joueurs], S_joueur joueur, int nb_joueurs, int index_donneur, int index_joueur, int sens_jeu);

char get_touche();
#endif
