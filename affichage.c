#include "affichage.h"

void banniere()
{
    printf("%c", 200);
    for(int i = 0; i < 16; i++)
        printf("%c", 205);
    printf("LOBO 77");
    for(int i = 0; i < 16; i++)
        printf("%c", 205);
    printf("%c\n\n", 188);
}

void afficher_joueurs(S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int index_donneur)
{
    banniere();
    printf("Nom      Donneur  Cartes       Jetons\n");
    for(int i = 0; i < nb_joueurs; i++)
    {
        printf("%-10s", joueurs[i].nom);
        if(index_donneur == i)
        {
            printf(" (D)    ");
        }else
        {
            printf(" ( )    ");
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
        printf("   ");
        for(int j = 0; j < joueurs[i].nb_jetons; j++)
            printf("%c ", 254);
        printf("\n\n");
    }
}

void afficher_cartes(S_joueur joueur, int curseur) //TODO Refactor avec print line ?
{
    for(int i_carte = 0; i_carte < DIM_main_joueur; i_carte++)
    {
        color(BLANC, NOIR);
        if(joueur.cartes[i_carte] != CARTE_NULLE)
        {
            if(i_carte == curseur) color(NOIR, BLANC);
            printf("%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 187);
        }
        else
            printf("        ");
    }
    printf("\n");

    for(int i_ligne = 0; i_ligne < 2; i_ligne++)
    {
        for(int i_carte = 0; i_carte < DIM_main_joueur; i_carte++)
        {
            color(BLANC, NOIR);
            if(joueur.cartes[i_carte] != CARTE_NULLE)
            {
                if(i_carte == curseur) color(NOIR, BLANC);
                printf("%c      %c", 186, 186);
            }
            else
                printf("        ");
        }
        printf("\n");
    }
    
    for(int i_carte = 0; i_carte < DIM_main_joueur; i_carte++)
    {
        color(BLANC, NOIR);
        if(joueur.cartes[i_carte] != CARTE_NULLE)
        {
            if(i_carte == curseur) color(NOIR, BLANC);
            switch (joueur.cartes[i_carte])
            {
                case CARTE_SENS :
                    printf("%c SENS %c", 186, 186);
                    break;
                case CARTE_X2 :
                    printf("%c  X2  %c", 186, 186);
                    break;
                default :
                    printf("%c % 3d  %c", 186, joueur.cartes[i_carte], 186);
            }
        }   
        else
            printf("        ");
    }
    printf("\n");
    
    for(int i_ligne = 0; i_ligne < 2; i_ligne++)
    {
        for(int i_carte = 0; i_carte < DIM_main_joueur; i_carte++)
        {
            color(BLANC, NOIR);
            if(joueur.cartes[i_carte] != CARTE_NULLE)
            {
                if(i_carte == curseur) color(NOIR, BLANC);
                printf("%c      %c", 186, 186);
            }
            else
                printf("        ");
        }
        printf("\n");
    }
    
    for(int i_carte = 0; i_carte < DIM_main_joueur; i_carte++)
    {
        color(BLANC, NOIR);
        if(joueur.cartes[i_carte] != CARTE_NULLE)
        {
            if(i_carte == curseur) color(NOIR, BLANC);
            printf("%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 188);
        }
        else
            printf("        ");
    }
    printf("\n");
    color(BLANC, NOIR);
    
}