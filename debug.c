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

        for(int j = 0; j < DIM_main_joueur; j++)//Initialisation des cartes à CARTE_VIDE
            joueurs[i].cartes[j]=CARTE_VIDE;

        joueurs[i].nb_jetons = 3;
    }
}

void distribuer_cartes_DEBUG(int pile[DIM_pile], int* index_pile, S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int index_donneur)//distribution des cartes
{
    //system("cls");
    //printf("Distribution des cartes...\n");
    //sleep(2);
    for(int i = 0; i < DIM_main_joueur; i++)
    {
        for(int j = 0; j < nb_joueurs; j++)
        {
            //system("cls");
            //afficher_joueurs(joueurs, nb_joueurs, index_donneur);
            //usleep(300000);
            joueurs[j].cartes[i] = pile[*index_pile];
            pile[*index_pile] = CARTE_VIDE;
            (*index_pile)--;
        }
    }
    //system("cls");
    //afficher_joueurs(joueurs, nb_joueurs, index_donneur);
    //printf("Fin de la distribution des cartes\n");
    //sleep(2);
    //system("cls");
}
