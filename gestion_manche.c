#include "gestion_manche.h"

void manche(S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int pile[DIM_pile], int *index_pile)
{
    //-------------------------Initialisation de la manche-------------------------
    system("cls");

    int defausse[DIM_pile];
    int index_defausse = -1; //Nombre de cartes dans la défausse
    int total_defausse = 0; //Total numérique de la défausse
    int index_carte, valeur_carte; //Stoke la carte sélectionnée par le joueur et sa valeur
    int joueur_suivant_x2 = 0; //Indique si le prochain joueur doit jouer 2 fois
    int carte_restant_a_jouer = 1; //Indique le nombre de cartes à jouer par le joueur
    int cartes_a_piocher = 0;

    for(int i = 0; i < DIM_pile; i++)
        defausse[i] = CARTE_VIDE; //Initialise la défausse avec des cartes vides

    animation_melanger_pile(joueurs, nb_joueurs);
    melanger_pile(pile, *index_pile);
    distribuer_cartes(pile, index_pile, joueurs, nb_joueurs);

    for(int i = 0; i < nb_joueurs; i++)//Remise à 0 du sens du jeu et du joueur actuel
        joueurs[i].sens_jeu = 0;

    int index_donneur = get_donneur(joueurs, nb_joueurs);
    joueurs[index_donneur].sens_jeu = SENS_HORAIRE; //On dit que le joueur actuel est le donneur
    int index_joueur = joueur_suivant(joueurs, nb_joueurs); //Et on cherche un joueur vivant à gauche

    afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
    printf("Le donneur est: %s\nC'est le joueur \x85 gauche qui commence, donc: %s\n\n", joueurs[index_donneur].nom, joueurs[index_joueur].nom);
    system("pause");

    //-------------------------Boucle de jeu-------------------------
    while(total_defausse < 77 && nb_joueur_sans_cartes(joueurs, nb_joueurs) == 0 && nb_joueur_valide(joueurs, nb_joueurs) > 1)
    {
        cartes_a_piocher = 0;
        afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
        color(JAUNE, NOIR); afficher_encadre_str("Laissez le clavier \x85 %s", joueurs[index_joueur].nom); color(BLANC, NOIR);

        if(joueur_suivant_x2 == 0) //Si le joueur précédent a joué une carte x2
            carte_restant_a_jouer = 1;
        else
        {
            carte_restant_a_jouer = 2;
            color(ROUGE, NOIR); afficher_petit_encadre("Vous devez jouer 2 cartes."); color(BLANC, NOIR);
        }
        joueur_suivant_x2 = 0;

        system("pause");
        do{
            if(*index_pile == 0) //Si il ne reste plus de cartes dans la pile
            {
                afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                afficher_petit_encadre("Il n'y a plus de cartes dans la pile");
                system("pause");

                vider_defausse(pile, defausse, index_pile, &index_defausse);
                animation_melanger_pile(joueurs, nb_joueurs);
                melanger_pile(pile, *index_pile);
                
                afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                printf("La d""\x82""fausse a \x82""t\x82 rajout\x82""e \x85 la pile et m\x82""lang""\x82""e.\n\n");
                system("pause");
            }

            //-------------------------Selection carte-------------------------
            do{
                index_carte = selectionner_carte(joueurs, joueurs[index_joueur], nb_joueurs, total_defausse);
                valeur_carte = joueurs[index_joueur].cartes[index_carte];
                if(valeur_carte == CARTE_X2 && carte_restant_a_jouer == 2)
                {
                    afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                    color(ROUGE, NOIR); printf("Vous ne pouvez pas jouer cette carte en premier alors que vous devez en poser 2.\n"); color(BLANC, NOIR);
                    system("pause");
                }
            }while(valeur_carte == CARTE_X2 && carte_restant_a_jouer == 2); //Si le joueur doit jouer 2 cartes, il ne peut pas jouer un x2 en première carte

            //Le joueur se défausse de la carte qu'il vient de jouer
            index_defausse++;
            defausse[index_defausse] = valeur_carte;
            joueurs[index_joueur].cartes[index_carte] = CARTE_VIDE;
            cartes_a_piocher++; //Le joueur aura la possibilité de piocher une carte

            //Traitement de la carte jouée
            if(valeur_carte == CARTE_SENS) //Inversion du sens de jeu
            {
                if(joueurs[index_joueur].sens_jeu == SENS_ANTIHORAIRE)
                    joueurs[index_joueur].sens_jeu = SENS_HORAIRE;
                else
                    joueurs[index_joueur].sens_jeu = SENS_ANTIHORAIRE;

                afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                color(VERT, NOIR); printf("Le sens de jeu a \x82t\x82 invers\x82.\n\n"); color(BLANC, NOIR);
                carte_restant_a_jouer--;
            }else if(valeur_carte == CARTE_X2) //Le prochain joueur doit jouer
            {
                afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                joueur_suivant_x2 = 1;
                color(VERT, NOIR); printf("Le prochain joueur devra jouer 2 cartes\n\n"); color(BLANC, NOIR);
                carte_restant_a_jouer--;
            }else //La carte a donc une valeur numérique
            {
                total_defausse += valeur_carte;
                afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                color(VERT, NOIR); printf("La carte %d a ""\x82""t\x82 ajout""\x82""e au total qui atteint donc: %d\n\n", valeur_carte, total_defausse); color(BLANC, NOIR);

                //Si le total atteint un multiple de 11, le joueur perd un jeton. Ne retire pas de jeton si le joueur vient de poser une carte sans valeur numérique
                if(total_defausse%11 == 0 && total_defausse != 0 && total_defausse < 77 && valeur_carte != 0 && valeur_carte < 77)
                {
                    color(ROUGE, NOIR); printf("\nLe total est un multiple de 11"); color(BLANC, NOIR);
                    retirer_jeton(&joueurs[index_joueur]);
                    if(carte_restant_a_jouer == 0) system("pause"); //Evite d'avoir une double pause si le doit jouer 2 cartes
                }
                carte_restant_a_jouer--;
            }
            if(carte_restant_a_jouer > 0) system("pause"); //Si c'est sa dernière carte à jouer, on passe directement à la pioche
        }while(carte_restant_a_jouer > 0 && joueurs[index_joueur].nb_jetons >= 0 && nb_cartes_joueur(joueurs[index_joueur]) > 0 && total_defausse < 77);

        //Proposer au joueur de piocher si il est toujours vivant et que le total est inférieur à 77
        if(joueurs[index_joueur].nb_jetons >= 0 && total_defausse < 77)
        {
            while(cartes_a_piocher > 0)
            {
                for(int i = 0; i < DIM_main_joueur; i++) //Trouve un emplacement de carte vide
                    if(joueurs[index_joueur].cartes[i] == CARTE_VIDE)
                        index_carte = i;

                color(JAUNE, NOIR); printf("\nVous avez 5 secondes pour piocher une carte en appuyant sur une touche.\n"); color(BLANC, NOIR);
                if(attend_touche(DELAI_PIOCHE) == 1)
                {
                    joueurs[index_joueur].cartes[index_carte] = pile[*index_pile];
                    pile[*index_pile] = CARTE_VIDE;
                    (*index_pile)--;

                    afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                    afficher_petit_encadre("Vous avez pioch\x82 la carte:");
                    afficher_carte(joueurs[index_joueur].cartes[index_carte]);
                }else
                {
                    afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
                    color(ROUGE, NOIR); printf("Vous n'avez pas pioch\x82 de carte.\n\n");
                    if(nb_cartes_joueur(joueurs[index_joueur]) == 0)
                    {
                        printf("Vous n'avez plus de cartes,");
                        retirer_jeton(&joueurs[index_joueur]);
                        color(ROUGE, NOIR);
                        afficher_encadre("La manche va maintenant se terminer.");
                    }
                    color(BLANC, NOIR);
                }
                system("pause");

                cartes_a_piocher--;
            }
        }

        if(total_defausse >= 77)
        {
            afficher_joueurs_et_total(joueurs, nb_joueurs, total_defausse);
            color(ROUGE, NOIR); printf("Vous avez fait d""\x82""passer la d""\x82""fausse au dessus de 76");
            retirer_jeton(&joueurs[index_joueur]); color(BLANC, NOIR);
            system("pause");
        }else
            index_joueur = joueur_suivant(joueurs, nb_joueurs); //On passe au joueur suivant si la défausse n'a pas atteint 77
    }
    //-------------------------Fin de manche-------------------------
    joueurs[get_joueur_actuel(joueurs, nb_joueurs)].sens_jeu = 0; //Remise à zéro du sens du joueur
    vider_main_joueurs(joueurs, nb_joueurs, pile, index_pile); //Vidage de la main des joueur_suivant
    vider_defausse(pile, defausse, index_pile, &index_defausse); //Vide la défausse avant la fin de la manche
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
        usleep(400000);
        for(int j = 0; j < nb_joueurs; j++)
        {
            if(joueurs[j].cartes[i] != CARTE_VIDE)
            {
                (*index_pile)++;
                pile[*index_pile] = joueurs[j].cartes[i];
                joueurs[j].cartes[i] = CARTE_VIDE;
            }
        }
    }

    system("cls");
    afficher_joueurs(joueurs, nb_joueurs);
}
