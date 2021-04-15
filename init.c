#include "init.h"

void initialiser_joueurs(S_joueur joueurs[NB_max_joueurs], int *nb_joueurs)
{
    do{
        printf("Combien de joueurs autour de la table ? (2-8) ");
        scanf("%d", nb_joueurs);
        fflush(stdin);//Au cas où l'utilisateur n'écrit pas un entier
    }while(*nb_joueurs < 2 || *nb_joueurs > NB_max_joueurs);

    system("pause");
    system("cls");

    for(int i = 0; i < *nb_joueurs; i++)
    {
        printf("Veuillez entrer le nom du joueur %d (max %d caracteres):\n", i+1, DIM_STR);
        gets_limite(joueurs[i].nom, DIM_STR);
        printf("Le joueur %d s'appelle: %s\n\n", i+1, joueurs[i].nom);
        system("pause");
        system("cls");

        for(int j=0; j<DIM_main_joueur; j++)//Initialisation des cartes à CARTE_NULLE
            joueurs[i].cartes[j]=CARTE_NULLE;

        joueurs[i].nb_jetons = 3;
    }
}

void initialiser_pile(int pile[DIM_pile])
{
    for(int i = 0; i < 4; i++)//4 cartes 0
        pile[i]=0;
    for(int i = 0; i < 4; i++)//4 cartes -10
        pile[i+4]=-10;//i prend des valeurs de 0 à 4 donc i+5 de 5 à 8
    for(int i = 0; i < 4; i++)//4 cartes x2
        pile[i+8]=CARTE_X2;
    for(int i=0;i<5; i++)//5 cartes sens
        pile[i+12]=CARTE_SENS;
    for(int i=0;i<6; i++)//6 cartes multiple de 11
        pile[i+17]=(i+1)*11;//i prend des valeurs de 0 à 5 donc i+1 de 1 à 6
    for(int i=0;i<8; i++)//8 cartes 10
        pile[i+23]=10;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
            pile[i*3+31+j]=i+2;//i+2 prend des valeurs de 2 à 9
    }
    pile[55]=76;
}

void initialiser_defausse(int defausse[DIM_pile])
{
    for(int i = 0; i < DIM_pile; i++)
        defausse[i] = CARTE_NULLE;
}

void distribuer_cartes(int pile[DIM_pile], int index_pile, S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int index_donneur)
{
    system("cls");
    printf("Distribution des cartes...\n");
    sleep(2);
    for(int i = 0; i < DIM_main_joueur; i++)
    {
        for(int j = 0; j < nb_joueurs; j++)
        {
            system("cls");
            afficher_joueurs(joueurs, nb_joueurs, index_donneur);
            usleep(300000);
            joueurs[j].cartes[i] = pile[index_pile];
            pile[index_pile] = CARTE_NULLE;
            index_pile--;
        }
    }
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs, index_donneur);
    printf("Fin de la distribution des cartes\n");
    sleep(2);
}
