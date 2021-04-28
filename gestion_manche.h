#ifndef INCLUDE_GESTION_MANCHE_H
#define INCLUDE_GESTION_MANCHE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "declarations.h"
#include "affichage.h"
#include "util.h"
#include "init.h"

void manche(S_joueur joueurs[NB_max_joueurs], int nb_joueursw, int pile[DIM_pile], int *index_pile);

void vider_defausse(int pile[DIM_pile], int defausse[DIM_pile], int *index_pile, int *index_defausse);

#endif