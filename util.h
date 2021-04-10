#ifndef INCLUDE_UTIL_H
#define INCLUDE_UTIL_H
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"

enum E_couleurs{noir,
            bleu_fonce,
            vert_fonce,
            turquoise,
            rouge_fonce,
            violet,
            vert_oie,
            gris_clair,
            gris_fonce,
            bleu,
            vert,
            turquoise_2,
            rouge,
            violet_2,
            jaune,
            blanc
            };
typedef enum E_couleurs couleurs;

void color (int couleurDuTexte, int couleurDuFond);

void gets_limite(int limite, char *sortie);

void melanger_pile(int cartes[DIM_pile],char nb_cartes);//Mélange les nb_cartes premières cartes d'une pile

#endif