#ifndef INCLUDE_UTIL_H
#define INCLUDE_UTIL_H
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

#include "declarations.h"
#include "affichage.h"

// Change la couleur de la console en fonction des couleurs définies dans declarations.h
void color (int couleurDuTexte, int couleurDuFond);

// Retourne 1 si le joueur a appuyé sur une touche dans le temps imparti, 0 sinon
int attend_touche(int timeout); 

// Retourne l'index du joueur actuel dans la liste de joueur
int get_joueur_actuel(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);

// Retourne l'index du donneur actuel dans la liste de joueur
int get_donneur(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);

// Attend que l'utilisateur appuie sur n'importe quelle flèche ou enter. Et retourne la touche appuyée
char get_fleches();
char get_fleche_verticale(); // Même chose que get_fleches mais restreint aux flèches verticales
char get_fleche_horizontale(); // Même chose que get_fleches mais restreint aux flèches horizontales

// Demande à l'utilisateur une chaine de charactère non-vide et la tronque pour avoir "limite" caractères
void gets_limite(char *sortie, int limite);

// Trouve un joueur vivant à gauche ou à droite (en fonction du sens de jeu) du joueur actuel et le nomme joueur actuel
int joueur_suivant(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);
// Trouve un joueur vivant à gauche du donneur actuel et le nomme donneur
int donneur_suivant(S_joueur joueurs[NB_max_joueurs], int nb_joueurs);

// Mélange les "nb_cartes" premières cartes d'une pile grâce à l'algorithme de Fisher–Yates
void melanger_pile(int cartes[DIM_pile], int nb_cartes);

// Propose au joueur de sélectionner une carte parmi sa mains et retourne l'index de cette carte
int selectionner_carte(S_joueur joueurs[NB_max_joueurs], S_joueur joueur, int nb_joueurs, int total_defausse);

int nb_cartes_joueur(S_joueur joueur); // Renvoie le nombre de carte non-vides que possède un joueur
int nb_joueur_valide(S_joueur joueurs[NB_max_joueurs], int nb_joueurs); // Renvoie le nombre de joueurs qui sont vivants
int nb_joueurs_sans_cartes(S_joueur joueurs[NB_max_joueurs], int nb_joueurs); // Renvoie le nombre de joueurs qui n'ont plus de cartes

void retirer_jeton(S_joueur *joueur); // Retire un jeton à un joueur et le notifie

void annoncer_gagnant(S_joueur joueurs[NB_max_joueurs], int nb_joueurs); // Annonce le gagnant d'une partie
#endif
