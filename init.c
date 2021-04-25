#include "init.h"

#ifndef MODE_DEBUG
void initialiser_joueurs(S_joueur joueurs[NB_max_joueurs], int *nb_joueurs)//Sous-programme pour initialiser les joueurs en début de partie
{
    do{
        printf("Combien de joueurs autour de la table ? (2-8) ");//entré du nombre de joueurs
        scanf("%d", nb_joueurs);
        fflush(stdin);//Au cas où l'utilisateur n'écrit pas un entier
    }while(*nb_joueurs < 2 || *nb_joueurs > NB_max_joueurs);//procédure lorsque le nombre de joueurs ne convient pas au lancement de la partie

    system("cls");

    for(int i = 0; i < *nb_joueurs; i++)
    {
        printf("Veuillez entrer le nom du joueur %d (max %d caracteres):\n", i+1, DIM_STR);//attribution du nom des joueurs
        gets_limite(joueurs[i].nom, DIM_STR);
        printf("Le joueur %d s'appelle: %s\n\n", i+1, joueurs[i].nom);
        system("pause");
        system("cls");

        for(int j=0;  j < DIM_main_joueur; j++)//Initialisation des cartes à CARTE_VIDE
            joueurs[i].cartes[j]=CARTE_VIDE;

        joueurs[i].nb_jetons = 0;//Initialisation des jetons
    }
}
#endif

void initialiser_pile(int pile[DIM_pile])
{
    for(int i = 0; i < 4; i++)//4 cartes 0
        pile[i] = 0;

    for(int i = 0; i < 4; i++)//4 cartes -10
        pile[ i + 4 ] = -10;//i prend des valeurs de 0 à 4 donc i+5 de 5 à 8

    for(int i = 0; i < 4; i++)//4 cartes x2
        pile[ i + 8 ] = CARTE_X2;
    for(int i = 0 ; i < 5; i++)//5 cartes sens
        pile[ i + 12 ] = CARTE_SENS;
    for(int i = 0; i < 6 ; i++)//6 cartes multiple de 11
        pile[ i + 17 ] = (i+1)*11;//i prend des valeurs de 0 à 5 donc i+1 de 1 à 6
    for(int i = 0; i < 8; i++)//8 cartes 10
        pile[ i + 23 ] = 10;

    for(int i = 0; i < 8; i++) //Parcours les 8 valeurs de 2 à 9
    {
        for(int j = 0; j < 3; j++) //Distribue 3 cartes par valeur
            pile[ i*3 + 31 + j] = i+2;//i+2 prend des valeurs de 2 à 9
    }
    pile[55] = 76;
}

void initialiser_defausse(int defausse[DIM_pile])//initialisation de la défausse en début de partie
{
    for(int i = 0; i < DIM_pile; i++)
        defausse[i] = CARTE_VIDE;
}

#ifndef MODE_DEBUG
//Distribution des cartes
void distribuer_cartes(int pile[DIM_pile], int* index_pile, S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int index_donneur)
{
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs, index_donneur, -1, 0);
    printf("Distribution des cartes...\n");
    sleep(1);

    for(int i = 0; i < DIM_main_joueur; i++)
    {
        for(int j = 0; j < nb_joueurs; j++)
        {
            system("cls");
            afficher_joueurs(joueurs, nb_joueurs, index_donneur, -1, 0);
            printf("Distribution des cartes...\n");
            usleep(300000);
            joueurs[j].cartes[i] = pile[*index_pile];
            pile[*index_pile] = CARTE_VIDE;
            (*index_pile)--;
        }
    }
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs, index_donneur, -1, 0);
    printf("Fin de la distribution des cartes\n");
    sleep(2);
    system("cls");
}

void distribuer_jetons(int pile[DIM_pile], int* index_pile, S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int index_donneur)
{
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs, index_donneur, -1, 0);
    printf("Distribution des jetons...\n");
    sleep(1);

    for(int i = 0; i < NB_max_jetons; i++)
    {
        for(int j = 0; j < nb_joueurs; j++)
        {
            system("cls");
            afficher_joueurs(joueurs, nb_joueurs, index_donneur, -1, 0);
            printf("Distribution des jetons...\n");
            usleep(300000);
            joueurs[j].nb_jetons++;
        }
    }
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs, index_donneur, -1, 0);
    printf("Fin de la distribution des jetons\n");
    sleep(2);
    system("cls");
}
#endif