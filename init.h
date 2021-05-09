#ifndef INCLUDE_INIT_H
#define INCLUDE_INIT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "util.h"
#include "declarations.h"
#include "affichage.h"

// Demande à l'utilisateur le nombre de joueurs et leurs noms
void initialiser_joueurs(S_joueur joueurs[NB_max_joueurs], int *nb_joueurs);

// Place dans "pioche" les cartes du jeu
void initialiser_pioche(int pioche[DIM_pile]);

// Sélectionne un joueur vivant aléatoire et le nomme donneur. Avec une animation
void donneur_aleatoire(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);

// Distribue aux joueurs vivants 5 cartes à partir de la pioche. Avec une animation
void distribuer_cartes(int poche[DIM_pile], int* index_pioche, S_joueur joueurs[NB_max_joueurs], int nb_joueurs);
// Distribue au joueurs un nombre "jetons_depart" (variable globale) de jetons. Avec une animation
void distribuer_jetons(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);

#endif
