#ifndef INCLUDE_AFFICHAGE_H
#define INCLUDE_AFFICHAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "declarations.h"
#include "util.h"

// Affiche une bannière avec le nom du jeu et le numéro de la manche si il est non nul
void banniere();

// Affiche une barre horizontale de largeur LARGEUR_AFFICHAGE
void barre_horizontale();

// Affiche le sens du jeu, le nom des joueurs, leurs jetons, leurs cartes et qui est le donneur
void afficher_joueurs(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);

// Affiche les cartes du joueur à l'horizontal
void afficher_cartes(S_joueur joueur, int curseur);
void afficher_carte(int carte);

/* 
   Pour chaque carte non-vide du joueur, affiche la portion de carte "ligne".
   Si la carte est sélectionnée, affiche la portion de carte en turquoise.
   Cette fonction permet d'afficher les cartes à l'horizontal:
   l'utilisation de la console nous oblige à écrire ligne par ligne.
*/
void afficher_ligne_cartes(S_joueur joueur, char ligne[9], int curseur);

// Affiche "ligne" dans un encadré centré avec une simple bordure
void afficher_petit_encadre(char ligne[]);
// Affiche "ligne" dans un encadré centré avec une double bordure
void afficher_encadre(char ligne[]);
// Affiche "format" dans un encadré centré à double bordure et remplace un %d par "donnee"
void afficher_encadre_int(char format[], int donnee);
// Affiche "format" dans un encadré centré à double bordure et remplace un %s par "donnee"
void afficher_encadre_str(char format[], char donnee[]);

// Affiche la bannière, les joueurs, le total de la défausse, puis une barre horizontale
void afficher_joueurs_et_total(S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int total_defausse);

// Joue une animation qui simule le mélange d'une pile
void animation_melanger_pile(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);

// Affiche la console en plein écran et applique un zoom de valeur "zoom"
void apparence_console(int zoom);
#endif