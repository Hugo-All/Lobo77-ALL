#ifndef INCLUDE_INIT_H
#define INCLUDE_INIT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "util.h"
#include "declarations.h"
#include "affichage.h"

void initialiser_joueurs(S_joueur joueurs[NB_max_joueurs], int *nb_joueurs);

void initialiser_pile(int pile[DIM_pile]);

void distribuer_cartes(int pile[DIM_pile], int* index_pile, S_joueur joueurs[NB_max_joueurs], int nb_joueurs);
void distribuer_jetons(int pile[DIM_pile], int* index_pile, S_joueur joueurs[NB_max_joueurs], int nb_joueurs);

#endif