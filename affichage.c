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

void barre_horizontale()
{
    for(int i = 0; i < 41; i++)
        printf("%c", 205);
    printf("\n\n");
}

void afficher_joueurs(S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int index_donneur, int index_joueur, int sens_jeu)
{
    banniere();
    printf("Sens  Nom      Donneur  Cartes       Jetons\n");
    for(int i = 0; i < nb_joueurs; i++) //Parcours chaque joueur
    {

        if(index_donneur == i)
        {
            if(sens_jeu == SENS_HORAIRE)
                printf("  ^   ");
            else
                printf("  v   ");
        }else
        {
            printf("      ");
        }

        printf("%-10s", joueurs[i].nom); //Affiche le nom du joueur

        //Affiche un (D) si le joueur est le donneur
        if(index_donneur == i)
        {
            printf(" (D)    ");
        }else
        {
            printf(" ( )    ");
        }
        
        //Affiche des carrés à la place des cartes du joueur
        for(int j = 0; j < DIM_main_joueur; j++)
        {
            if(joueurs[i].cartes[j] == CARTE_VIDE)
            {
                printf("%c ", 176);
            }else{
                printf("%c ", 219);
            }
        }
        printf("   ");

        //Affiche les jetons du joueur
        for(int j = 0; j < joueurs[i].nb_jetons; j++)
            printf("%c ", 254);
        printf("\n\n");
    }
}

void afficher_cartes(S_joueur joueur, int curseur)
{
    char buffer_ligne[9];
    
    //Affiche le haut de chaque cartes
    sprintf(buffer_ligne, "%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 187);
    afficher_ligne_cartes(joueur, buffer_ligne, curseur);

    //Affiche 2 lignes intermédiaires
    sprintf(buffer_ligne, "%c      %c", 186, 186);
    for(int i = 0; i < 2; i++)
        afficher_ligne_cartes(joueur, buffer_ligne, curseur);

    //Affiche la ligne contenant le type de carte
    for(int i_carte = 0; i_carte < DIM_main_joueur; i_carte++)
    {
        color(BLANC, NOIR);
        if(joueur.cartes[i_carte] != CARTE_VIDE)
        {
            if(i_carte == curseur) color(NOIR, BLANC);//Inverse les couleurs si carte sélectionnée
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

    //Affiche 2 lignes intermédiaires
    sprintf(buffer_ligne, "%c      %c", 186, 186);
    for(int i = 0; i < 2; i++)
        afficher_ligne_cartes(joueur, buffer_ligne, curseur);
        
    //Affiche le bas de chaque cartes
    sprintf(buffer_ligne, "%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 188);
    afficher_ligne_cartes(joueur, buffer_ligne, curseur);

    printf("\n");
    color(BLANC, NOIR); //Remet à 0 les couleurs
}

//Affiche une portion de chaque cartes
void afficher_ligne_cartes(S_joueur joueur, char ligne[9], int curseur)
{
    for(int i_carte = 0; i_carte < DIM_main_joueur; i_carte++) //Parcours chaque carte du joueur
    {
        color(BLANC, NOIR); //Remet à 0 les couleurs
        if(joueur.cartes[i_carte] != CARTE_VIDE)
        {
            if(i_carte == curseur) color(NOIR, BLANC); //Inverse les couleurs si carte sélectionnée
            printf("%s", ligne);
        }
        else
            printf("        "); //Si la carte est vide, imprimer des espaces
    }
    printf("\n");
}