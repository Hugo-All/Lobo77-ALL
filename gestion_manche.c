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

    for(int i = 0; i < DIM_pile; i++)
        defausse[i] = CARTE_VIDE; //Initialise la défausse avec des cartes vides

    printf("Melange des cartes de la pile");
    for(int i = 0; i < 5; i++)
    {
        usleep(500000);
        printf(".");
    }
    melanger_pile(pile, *index_pile);
    system("cls");
    printf("Melange des cartes de la pile termine\n");
    system("pause");

    for(int i = 0; i < nb_joueurs; i++)//Remise à 0 du sens du jeu et du joueur actuel
        joueurs[i].sens_jeu = 0;

    int index_donneur = get_donneur(joueurs, nb_joueurs);
    joueurs[index_donneur].sens_jeu = SENS_HORAIRE; //On dit que le joueur actuel est le donneur
    int index_joueur = joueur_suivant(joueurs, nb_joueurs); //Et on cherche un joueur vivant à gauche

    afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
    printf("Le donneur est: %s, c'est le joueur a gauche qui commence, donc: %s\n", joueurs[index_donneur].nom, joueurs[index_joueur].nom);
    system("pause");

    while(total_defausse < 77 && nb_joueur_valide(joueurs, nb_joueurs) > 1)//TODO Carte x2
    {

        if(*index_pile == 0) //Si il ne reste plus de cartes dans la pile
        {
            vider_defausse(pile, defausse, index_pile, &index_defausse);
            afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
            printf("La défausse a ete rajoutee a la pile et melangee.\n");
        }

        afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
        printf("Laissez le clavier a %s\n", joueurs[index_joueur].nom);
        system("pause");
        index_carte = selectionner_carte(joueurs, joueurs[index_joueur], nb_joueurs, total_defausse);
        valeur_carte = joueurs[index_joueur].cartes[index_carte];

        //Le joueur se défausse de la carte qu'il vient de jouer
        defausse[index_defausse + 1] = valeur_carte;
        index_defausse++;
        defausse[index_defausse] = valeur_carte;
        joueurs[index_joueur].cartes[index_carte] = CARTE_VIDE;


        if(valeur_carte == CARTE_SENS)//Inversion du sens de jeu
        {
            if(joueurs[index_joueur].sens_jeu == SENS_ANTIHORAIRE)
                joueurs[index_joueur].sens_jeu = SENS_HORAIRE;
            else
                joueurs[index_joueur].sens_jeu = SENS_ANTIHORAIRE;

            afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
            printf("Le sens de jeu a ete inverse.\n");
        }else if(valeur_carte == CARTE_X2)
        {
            afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
            prochain_joueur_x2 = 1;
            printf("Le prochain joueur devra jouer 2 cartes\n");
        }else //La carte a donc une valeur numérique
        {
            total_defausse += valeur_carte;
            afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
            printf("La carte %d a ete ajoutee au total qui atteint donc: %d\n", valeur_carte, total_defausse);
            if(total_defausse != 0 && total_defausse < 77 && total_defausse%11 == 0) //Si le total atteint un multiple de 11, le joueur perd un jeton.
            {
                printf("\nLe total est un multiple de 11. ");
                retirer_jeton(&joueurs[index_joueur]);
            }
        }

        //Si le joueur est toujours vivant et que le total est inférieur à 77
        if(joueurs[index_joueur].nb_jetons >= 0 && total_defausse < 77)
        {
            printf("Vous avez 5 secondes pour piocher une carte.\n");
            if(attend_touche(5) == 1)
            {
                joueurs[index_joueur].cartes[index_carte] = pile[*index_pile];
                pile[*index_pile] = CARTE_VIDE;
                (*index_pile)--;

                afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                printf("Vous avez pioche la carte:\n\n");
                afficher_carte(joueurs[index_joueur].cartes[index_carte]);

            }else
            {
                afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                printf("Vous n'avez pas pioche de carte.\n");
                if(nb_cartes_joueur(joueurs[index_joueur]) == 0)
                    printf("Vous n'avez plus de cartes, vous ne perdez pas de jetons, mais vous devez attendre la prochaine manche.\n");
            }
        }
        system("pause");

        index_joueur = joueur_suivant(joueurs, nb_joueurs);

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
