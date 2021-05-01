#ifndef INCLUDE_AFFICHAGE_H
#define INCLUDE_AFFICHAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "declarations.h"
#include "util.h"

void banniere();
void barre_horizontale();

void afficher_joueurs(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);

void afficher_cartes(S_joueur joueur, int curseur);
void afficher_carte(int carte);
void afficher_ligne_cartes(S_joueur joueur, char ligne[9], int curseur);

void afficher_encadree_int(char format[], int donnee);
void afficher_encadree_str(char format[], char donnee[]);
void afficher_encadree(char ligne[]);
void afficher_petit_encadree(char ligne[])

void afficher_joueurs_et_total(S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int total_defausse);

void apparence_console();
#endif