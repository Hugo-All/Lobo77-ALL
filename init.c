#include "init.h"

// Demande à l'utilisateur le nombre de joueurs et leurs noms
void initialiser_joueurs(S_joueur joueurs[NB_max_joueurs], int *nb_joueurs) // Sous-programme pour initialiser les joueurs en début de partie
{
    do
    {
        printf("Combien de joueurs autour de la table ? (2-8) _\b");
        scanf("%d", nb_joueurs);
        fflush(stdin);
    }while(*nb_joueurs < 2 || *nb_joueurs > NB_max_joueurs); // Recommence si le joueur n'écris pas un nombre dans l'intervale souhaité

    system("cls");

    for(int i = 0; i < *nb_joueurs; i++) // Initialisation des cartes et des jetons avant l'affichage
    {
        for(int j=0;  j < DIM_main_joueur; j++) // Initialisation des cartes à CARTE_VIDE
            joueurs[i].cartes[j]=CARTE_VIDE;

        joueurs[i].nb_jetons = 0;
        joueurs[i].donneur = 0;
        joueurs[i].sens_jeu = 0;
        strcpy(joueurs[i].nom, ""); // Initialisation du nom
    }

    for(int i = 0; i < *nb_joueurs; i++)
    {
        afficher_joueurs(joueurs, *nb_joueurs);
        printf("Veuillez entrer le nom du joueur %d (max %d caract\x8Ares): ", i+1, DIM_STR); // attribution du nom des joueurs
        for (int j = 0; j < 10; j++) printf("_"); // Affiche 10 caractères _
        for (int j = 0; j < 10; j++) printf("\b"); // Ramène le curseur 10 caractères en arrière
        gets_limite(joueurs[i].nom, DIM_STR);
        system("cls");
    }

    afficher_joueurs(joueurs, *nb_joueurs);
    color(VERT, NOIR); afficher_petit_encadre("Fin de l'initialisation des joueurs"); color(BLANC, NOIR); 
    system("pause");
}

// Place dans "pioche" les cartes du jeu
void initialiser_pioche(int pioche[DIM_pile])
{
    for(int i = 0; i < 4; i++) // 4 cartes 0
        pioche[i] = 0;

    for(int i = 0; i < 4; i++) // 4 cartes -10
        pioche[ i + 4 ] = -10; // i prend des valeurs de 0 à 4 donc i+5 de 5 à 8

    for(int i = 0; i < 4; i++) // 4 cartes x2
        pioche[ i + 8 ] = CARTE_X2;
    for(int i = 0 ; i < 5; i++) // 5 cartes sens
        pioche[ i + 12 ] = CARTE_SENS;
    for(int i = 0; i < 6 ; i++) // 6 cartes multiple de 11
        pioche[ i + 17 ] = (i+1)*11; // i prend des valeurs de 0 à 5 donc i+1 de 1 à 6
    for(int i = 0; i < 8; i++) // 8 cartes 10
        pioche[ i + 23 ] = 10;

    for(int i = 0; i < 8; i++) // Parcours les 8 valeurs de 2 à 9
    {
        for(int j = 0; j < 3; j++) // Distribue 3 cartes par valeur
            pioche[ i*3 + 31 + j] = i+2; // i+2 prend des valeurs de 2 à 9
    }
    pioche[55] = 76;
}

// Sélectionne un joueur vivant aléatoire et le nomme donneur. Avec une animation
void donneur_aleatoire(S_joueur joueurs[NB_max_joueurs], int nb_joueurs)
{
    int donneur = 0;
    int nombre_aleatoire = (rand() % nb_joueurs) + nb_joueurs; // Au minimum un tour complet et au max 2

    for(int i = 0; i < nombre_aleatoire; i++)
    {
        donneur = donneur_suivant(joueurs, nb_joueurs);
        system("cls");
        afficher_joueurs(joueurs, nb_joueurs);
        afficher_petit_encadre("S\x82""lection d'un donneur al""\x82""atoire...");
        usleep(300000);
    }
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs);
    color(VERT, NOIR); afficher_encadre_str("Le donneur s\x82lectionn\x82 est %s", joueurs[donneur].nom); color(BLANC, NOIR);
    system("pause");
}

// Distribue aux joueurs vivants 5 cartes à partir de la pioche. Avec une animation
void distribuer_cartes(int pioche[DIM_pile], int* index_pioche, S_joueur joueurs[NB_max_joueurs], int nb_joueurs)
{
    int index_donneur = get_donneur(joueurs, nb_joueurs);

    for(int i = 0; i < DIM_main_joueur; i++)
    {
        for(int j = index_donneur + 1 ; j < index_donneur+1 + nb_joueurs; j++)
        {
            if(joueurs[j % nb_joueurs].nb_jetons >= 0) // On distribue des cartes uniquement aux joueurs vivants
            {
                system("cls");
                afficher_joueurs(joueurs, nb_joueurs);
                afficher_petit_encadre("Distribution des cartes par le donneur...");
                usleep(250000);
                joueurs[j % nb_joueurs].cartes[i] = pioche[*index_pioche];
                pioche[*index_pioche] = CARTE_VIDE;
                (*index_pioche)--;
            }
        }
    }
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs);
    color(VERT, NOIR); afficher_petit_encadre("Fin de la distribution des cartes"); color(BLANC, NOIR);
    system("pause");
}

// Distribue au joueurs un nombre "jetons_depart" (variable globale) de jetons. Avec une animation
void distribuer_jetons(S_joueur joueurs[NB_max_joueurs], int nb_joueurs)
{
    int index_donneur = get_donneur(joueurs, nb_joueurs);

    for(int j = index_donneur + 1 ; j < index_donneur+1 + nb_joueurs; j++)
    {
        for(int i = 0; i < jetons_depart; i++)
        {
            if(joueurs[j % nb_joueurs].nb_jetons >= 0) // On distribue des cartes uniquement aux joueurs vivants
            {
                system("cls");
                afficher_joueurs(joueurs, nb_joueurs);
                afficher_petit_encadre("Distribution des jetons par le donneur...");
                usleep(250000);
                joueurs[j % nb_joueurs].nb_jetons++;
            }
        }
    }
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs);
    color(VERT, NOIR); afficher_petit_encadre("Fin de la distribution des jetons"); color(BLANC, NOIR);
    system("pause");
}
