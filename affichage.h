#ifndef INCLUDE_AFFICHAGE_H
#define INCLUDE_AFFICHAGE_H

#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"
#include "util.h"

void banniere();
void afficher_joueurs(S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int index_donneur, int index_joueur, int sens_jeu);
void afficher_cartes(S_joueur joueur, int curseur);
void afficher_ligne_cartes(S_joueur joueur, char ligne[9], int curseur);

#endif