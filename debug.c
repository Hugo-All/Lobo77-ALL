#include "debug.h"


void tableau_cartes(int pile[DIM_pile])
{

}

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

        for(int j = 0; j < DIM_main_joueur; j++)//Initialisation des cartes à CARTE_NULLE
            joueurs[i].cartes[j]=CARTE_NULLE;

        joueurs[i].nb_jetons = 3;
    }
}
