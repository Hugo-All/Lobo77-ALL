#include "debug.h"

void afficher_pile(int pile[DIM_pile])
{
    for(int i = 0; i < DIM_pile; i++)
    {
        printf("%d ", pile[i]);
    }
    printf("\n");
}

void initialiser_joueurs_DEBUG(S_joueur joueurs[NB_max_joueurs], int *nb_joueurs)
{
    *nb_joueurs=6;

    for(int i = 0; i < *nb_joueurs; i++)
    {
        sprintf(joueurs[i].nom,"joueur%d",i);

        for(int j = 0; j < DIM_main_joueur; j++)//Initialisation des cartes à CARTE_VIDE
            joueurs[i].cartes[j]=CARTE_VIDE;

        joueurs[i].nb_jetons = 0;
    }
}

//Distribution des cartes en mode débug
void distribuer_cartes_DEBUG(int pile[DIM_pile], int* index_pile, S_joueur joueurs[NB_max_joueurs], int nb_joueurs)
{
    for(int i = 0; i < DIM_main_joueur; i++)
    {
        for(int j = 0; j < nb_joueurs; j++)
        {
            joueurs[j].cartes[i] = pile[*index_pile];
            pile[*index_pile] = CARTE_VIDE;
            (*index_pile)--;
        }
    }
}

//Distribution des jetons en mode débug
void distribuer_jetons_DEBUG(S_joueur joueurs[NB_max_joueurs], int nb_joueurs)
{
    for(int i = 0; i < nb_joueurs; i++)
        joueurs[i].nb_jetons = jetons_depart;
}