#ifndef INCLUDE_DECLARATIONS_H
#define INCLUDE_DECLARATIONS_H

#define DIM_STR 10
#define DIM_pile 56
#define DIM_main_joueur 5
#define NB_max_joueurs 8

#define CARTE_NULLE 100
#define CARTE_X2 101
#define CARTE_SENS 102

typedef struct joueur{
    char nom[DIM_STR];
    char cartes[5];
    char nb_jetons;
} S_joueur;

int pile[DIM_pile];
int defausse[DIM_pile];
S_joueur joueurs[NB_max_joueurs];
int nb_joueurs;
int index_donneur;
int index_pile;
int index_defausse;

#endif