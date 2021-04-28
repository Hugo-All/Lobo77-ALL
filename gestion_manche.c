#include "gestion_manche.h"

void manche(S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int pile[DIM_pile], int *index_pile)
{
    //-------------------------Initialisation de la manche-------------------------
    system("cls");

    int defausse[DIM_pile];
    int index_defausse = 0; //Nombre de cartes dans la défausse
    int total_defausse = 0; //Total numérique de la défausse
    int index_carte, valeur_carte; //Stoke la carte sélectionnée par le joueur et sa valeur
    int joueur_suivant_x2 = 0; //Indique si le prochain joueur doit jouer 2 fois
    int carte_restant_a_jouer = 1; //Indique le nombre de cartes à jouer par le joueur

    for(int i = 0; i < DIM_pile; i++)
        defausse[i] = CARTE_VIDE; //Initialise la défausse avec des cartes vides

    system("cls");
    afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
    printf("Melange des cartes de la pile");

    for(int i = 0; i < 3; i++)
    {
        usleep(600000);
        printf(".");
    }
    melanger_pile(pile, *index_pile);
    system("cls");
    afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
    printf("Melange des cartes de la pile termine\n");
    usleep(600000);
    distribuer_cartes(pile, index_pile, joueurs, nb_joueurs);
    system("pause");

    for(int i = 0; i < nb_joueurs; i++)//Remise à 0 du sens du jeu et du joueur actuel
        joueurs[i].sens_jeu = 0;

    int index_donneur = get_donneur(joueurs, nb_joueurs);
    joueurs[index_donneur].sens_jeu = SENS_HORAIRE; //On dit que le joueur actuel est le donneur
    int index_joueur = joueur_suivant(joueurs, nb_joueurs); //Et on cherche un joueur vivant à gauche

    afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
    printf("Le donneur est: %s, c'est le joueur a gauche qui commence, donc: %s\n", joueurs[index_donneur].nom, joueurs[index_joueur].nom);
    system("pause");

    //-------------------------Boucle de jeu-------------------------
    while(total_defausse < 77 && nb_joueur_valide(joueurs, nb_joueurs) > 1)
    {
        afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
        printf("Laissez le clavier a %s\n", joueurs[index_joueur].nom);
        system("pause");

        if(joueur_suivant_x2 == 0) //Si le joueur précédent a joué une carte x2
            carte_restant_a_jouer = 1;
        else
        {
            carte_restant_a_jouer = 2;
            afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
            printf("Vous devez jouer 2 cartes.\n");
            system("pause");
        }
        joueur_suivant_x2 = 0;

        do{
            if(*index_pile == 0) //Si il ne reste plus de cartes dans la pile
            {
                vider_defausse(pile, defausse, index_pile, &index_defausse);
                melanger_pile(pile, *index_pile);
                afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                printf("La défausse a ete rajoutee a la pile et melangee.\n");
            }

            //-------------------------Selection carte-------------------------
            do{
                index_carte = selectionner_carte(joueurs, joueurs[index_joueur], nb_joueurs, total_defausse);
                valeur_carte = joueurs[index_joueur].cartes[index_carte];
                if(valeur_carte == CARTE_X2 && carte_restant_a_jouer == 2)
                {
                    printf("Vous ne pouvez pas jouer cette carte en premier alors que vous devez en poser 2.");
                    system("pause");
                }
            }while(valeur_carte == CARTE_X2 && carte_restant_a_jouer == 2); //Si le joueur doit jouer 2 cartes, il ne peut pas jouer un x2 en première carte

            //Le joueur se défausse de la carte qu'il vient de jouer
            defausse[index_defausse + 1] = valeur_carte;
            index_defausse++;
            defausse[index_defausse] = valeur_carte;
            joueurs[index_joueur].cartes[index_carte] = CARTE_VIDE;

            //Traitement de la carte jouée
            if(valeur_carte == CARTE_SENS) //Inversion du sens de jeu
            {
                if(joueurs[index_joueur].sens_jeu == SENS_ANTIHORAIRE)
                    joueurs[index_joueur].sens_jeu = SENS_HORAIRE;
                else
                    joueurs[index_joueur].sens_jeu = SENS_ANTIHORAIRE;

                afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                printf("Le sens de jeu a ete inverse.\n");
                carte_restant_a_jouer--;
            }else if(valeur_carte == CARTE_X2) //Le prochain joueur doit jouer
            {
                afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                joueur_suivant_x2 = 1;
                printf("Le prochain joueur devra jouer 2 cartes\n");
                carte_restant_a_jouer--;
            }else //La carte a donc une valeur numérique
            {
                total_defausse += valeur_carte;
                afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                printf("La carte %d a ete ajoutee au total qui atteint donc: %d\n", valeur_carte, total_defausse);
                if(total_defausse != 0 && total_defausse < 77 && total_defausse%11 == 0) //Si le total atteint un multiple de 11, le joueur perd un jeton.
                {
                    printf("\nLe total est un multiple de 11");
                    retirer_jeton(&joueurs[index_joueur]);
                }
                carte_restant_a_jouer--;
            }

            //Proposer au joueur de piocher si il est toujours vivant et que le total est inférieur à 77
            if(joueurs[index_joueur].nb_jetons >= 0 && total_defausse < 77)
            {
                printf("\nVous avez 5 secondes pour piocher une carte en appuyant sur une touche.\n");
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
                    if(nb_cartes_joueur(joueurs[index_joueur]) == 0) //TODO Ecrire prof à propos de la protection d'un joueur qui n'as plus de cartes
                        printf("Vous n'avez plus de cartes, vous ne perdez pas de jetons, mais vous devez attendre la prochaine manche.\n");
                }
                system("pause");
            }
        }while(carte_restant_a_jouer > 0 && joueurs[index_joueur].nb_jetons >= 0 && nb_cartes_joueur(joueurs[index_joueur]) > 0);

        index_joueur = joueur_suivant(joueurs, nb_joueurs);
    }

    if(total_defausse >= 77)
    {
        printf("Vous avez fait depasser la defausse au dessus de 76");
        retirer_jeton(&joueurs[index_joueur]);
        vider_main_joueurs(joueurs, nb_joueurs, pile, index_pile);
    }//Si cette condition n'est pas vérifiée alors: un seul joueur possède des cartes ou un seul joueur est vivant
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

void vider_main_joueurs(S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int pile[DIM_pile], int *index_pile)
{
    for(int i = DIM_main_joueur - 1; i >= 0; i--)
    {
        system("cls");
        afficher_joueurs(joueurs, nb_joueurs);
        printf("Vidage des mains des joueurs...");
        usleep(200000);
        for(int j = 0; j < nb_joueurs; j++)
        {
            (*index_pile)++;
            pile[*index_pile] = joueurs[j].cartes[i];
            joueurs[j].cartes[i] = CARTE_VIDE;
        }
    }

    system("cls");
    afficher_joueurs(joueurs, nb_joueurs);
}