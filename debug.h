#ifndef INCLUDE_DEBUG_H
#define INCLUDE_DEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"

void afficher_pile(int pile[DIM_pile]);
void initialiser_joueurs_DEBUG(S_joueur joueurs[NB_max_joueurs], int *nb_joueurs);
void distribuer_cartes_DEBUG(int pioche[DIM_pile], int* index_pioche, S_joueur joueurs[NB_max_joueurs], int nb_joueurs);
void distribuer_jetons_DEBUG(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);
#endif