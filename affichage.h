#ifndef INCLUDE_AFFICHAGE_H
#define INCLUDE_AFFICHAGE_H

#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"

void banniere();
void afficher_joueurs(S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int index_donneur);

#endif