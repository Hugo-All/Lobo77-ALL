#include "gestion_manche.h"

void manche(S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int pile[DIM_pile], int *index_pile)
{
    //Initialisation de la manche
    system("cls");

    int defausse[DIM_pile];
    int index_defausse = 0; //Nombre de cartes dans la défausse
    int total_defausse = 0; //Total numérique de la défausse
    int index_carte, valeur_carte; //Stoke la carte sélectionnée par le joueur et sa valeur
    int prochain_joueur_x2 = 0; //Indique si le prochain joueur doit jouer 2 fois
    int sens_jeu;

    for(int i = 0; i < DIM_pile; i++)
        defausse[i] = CARTE_VIDE; //Initialise la défausse avec des cartes vides

    printf("Melange des cartes");
    for(int i = 0; i < 5; i++)
    {
        usleep(500000);
        printf(".");
    }
    melanger_pile(pile, *index_pile);
    system("cls");
    printf("Melange des cartes termine\n");
    system("pause");

    for(int i = 0; i < nb_joueurs; i++)//Remise à 0 du sens du jeu et du joueur actuel
        joueurs[i].sens_jeu = 0;

    int index_donneur = get_donneur(joueurs, nb_joueurs);

    int index_joueur;//On prend le joueur après le donneur
    //TODO Checker que le joueur à gauche soit vivant
    if(index_donneur+1 < nb_joueurs)
        index_joueur = index_donneur + 1;
    else //Si le donneur est le dernier joueur le joueur qui commence est donc le premier
        index_joueur = 0;
    joueurs[index_joueur].sens_jeu = SENS_HORAIRE;

    printf("Le donneur est: %s, c'est le joueur a gauche qui commence, donc: %s\n", joueurs[index_donneur].nom, joueurs[index_joueur].nom);
    system("pause");

    while(total_defausse < 77)//TODO Carte x2
    {
        system("cls");
        afficher_joueurs(joueurs, nb_joueurs);
        printf("Laissez le clavier a %s\n", joueurs[index_joueur].nom);
        system("pause");
        index_carte = selectionner_carte(joueurs, joueurs[index_joueur], nb_joueurs, total_defausse);
        valeur_carte = joueurs[index_joueur].cartes[index_carte];

        //Le joueur se défausse de la carte qu'il vient de jouer
        defausse[index_defausse + 1] = valeur_carte;
        index_defausse++;
        defausse[index_defausse] = valeur_carte;
        joueurs[index_joueur].cartes[index_carte] = CARTE_VIDE;

        system("cls");
        if(valeur_carte == CARTE_SENS)//Inversion du sens de jeu
        {
            if(joueurs[index_joueur].sens_jeu == SENS_ANTIHORAIRE)
                joueurs[index_joueur].sens_jeu = SENS_HORAIRE;
            else
                joueurs[index_joueur].sens_jeu = SENS_ANTIHORAIRE;

            printf("Le sens de jeu a ete inverse.\n");
        }else if(valeur_carte == CARTE_X2)
        {
            prochain_joueur_x2 = 1;
            printf("Le prochain joueur devra jouer 2 cartes\n");
        }else //La carte a donc une valeur numérique
        {
            total_defausse += valeur_carte;
            printf("La carte %d a ete ajoutee au total qui atteint donc: %d\n", valeur_carte, total_defausse);
            if(total_defausse != 0 && total_defausse < 77 && total_defausse%11 == 0) //Si le total atteint un multiple de 11, le joueur perd un jeton.
            {
                //TODO Fonction retirer jeton avec conditions d'élimination
                joueurs[index_joueur].nb_jetons--;
                printf("Le total est un multiple de 11 donc vous avez perdu un jeton, vous n'en avez plus que %d\n", joueurs[index_joueur].nb_jetons);
            }
        }
        system("pause");

        printf("Vous avez 5 secondes pour piocher une carte.\n");
        if(attend_touche(5) == 1)
        {
            joueurs[index_joueur].cartes[index_carte] = pile[*index_pile];
            pile[*index_pile] = CARTE_VIDE;
            (*index_pile)--;
            printf("Vous avez pioche la carte %d\n", joueurs[index_joueur].cartes[index_carte]); //TODO Fonction afficher_carte
        }else
            printf("Vous n'avez pas pioche de carte.\n");
        system("pause");

        //TODO Fonction sélectionner prochain joueur
        sens_jeu = joueurs[index_joueur].sens_jeu;
        do{ //On sélectionne le prochain joueur
            joueurs[index_joueur].sens_jeu = 0;
            index_joueur += sens_jeu;

            if(index_joueur >= nb_joueurs)
                index_joueur = 0;
            else if(index_joueur < 0)
                index_joueur = nb_joueurs - 1;

            joueurs[index_joueur].sens_jeu = sens_jeu;
        }while(joueurs[index_joueur].nb_jetons < 0) //On recommence si le prochain joueur est éliminé

        printf("j%d %d", index_joueur, get_joueur_actuel(joueurs, nb_joueurs)); system("pause");
    }

}

void vider_defausse(int pile[DIM_pile], int defausse[DIM_pile], int *index_pile, int *index_defausse)
{
    for(int i = *index_defausse; i >= 0; i--)
    {
        (*index_pile)++; //Incrémente le nombre de carte dans la pile
        (*index_defausse)--; //Décrémente le nombre de carte dans la défausse

        pile[*index_pile] = defausse[i]; //Transfère la carte de la défausse vers la pile
        defausse[i] = CARTE_VIDE; //Remplace la carte transférée par la carte vide
    }
}
