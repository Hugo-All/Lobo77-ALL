#ifndef INCLUDE_DEBUG_H
#define INCLUDE_DEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"

void afficher_pile(int pile[DIM_pile]);
void initialiser_joueurs_DEBUG(S_joueur joueurs[NB_max_joueurs], int *nb_joueurs);
void distribuer_cartes_DEBUG(int pile[DIM_pile], int* index_pile, S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int index_donneur);
#endif