#ifndef INCLUDE_DECLARATIONS_H
#define INCLUDE_DECLARATIONS_H

//----------------DEFINES---------------
// Définition des dimensions des tableaux
#define DIM_STR 10 // Taille maximum du nom d'un joueur
#define DIM_pile 56
#define DIM_main_joueur 5
#define NB_max_joueurs 8
#define NB_max_jetons 3

// Définition des cartes spéciales
#define CARTE_VIDE 100
#define CARTE_X2 101
#define CARTE_SENS 102

// Touches
#define TOUCHE_DROITE 77
#define TOUCHE_GAUCHE 75
#define TOUCHE_HAUT 80
#define TOUCHE_BAS 72
#define TOUCHE_ENTER 13

// Sens de jeu
#define SENS_HORAIRE 1
#define SENS_ANTIHORAIRE -1

#define LARGEUR_AFFICHAGE 45

#define DELAI_PIOCHE_MIN 2 // Temps minimum pour piocher une carte

/* Caractères à remplacer
é = \x82
è = \x8A
à = \x85
ç = \x87
ê = \x88
*/

//------------- Structure ---------------
typedef struct joueur{
    char nom[DIM_STR + 1];
    char cartes[5];
    char nb_jetons;
    char donneur;
    char sens_jeu; //0 si le joueur n'est pas en train de jouer, SENS_HORAIRE ou SENS_ANTIHORAIRE sur le joueur courant
} S_joueur;

//-------- Variables globales --------
int jetons_depart;
int num_manche;
int delai_pioche;

//-------- Couleurs --------

enum E_couleurs{NOIR,
            BLEU_FONCE,
            VERT_FONCE,
            TURQUOISE,
            ROUGE_FONCE,
            VIOLET,
            VERT_OIE,
            GRIS_CLAIR,
            GRIS_FONCE,
            BLEU,
            VERT,
            TURQUOISE_2,
            ROUGE,
            VIOLET_2,
            JAUNE,
            BLANC
            };
typedef enum E_couleurs couleurs;

#endif
