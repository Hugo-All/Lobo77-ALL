#include "affichage.h"

void banniere()
{
    printf("%c", 200);
    for(int i = 0; i < 20; i++)
        printf("%c", 205);
    printf("LOBO 77");
    for(int i = 0; i < 20; i++)
        printf("%c", 205);
    printf("%c\n\n", 188);
}

void afficher_joueurs(S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int index_donneur)
{
    for(int i = 0; i < nb_joueurs; i++)
    {
        printf("%-10s",joueurs[i].nom);
        if(index_donneur==i)
        {
            printf("(D) ");
        }else
        {
            printf("( ) ");
        }

        for(int j = 0; j < DIM_main_joueur; j++)
        {
            if(joueurs[i].cartes[j] == CARTE_NULLE)
            {
                printf("%c ", 176);
            }else{
                printf("%c ", 219);
            }
        }

        for(int j = 0; j < joueurs[i].nb_jetons; j++)
            printf("%c ", 254);
        printf("\n\n");
    }
}