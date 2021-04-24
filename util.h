#ifndef INCLUDE_UTIL_H
#define INCLUDE_UTIL_H
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "declarations.h"

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

#endif
