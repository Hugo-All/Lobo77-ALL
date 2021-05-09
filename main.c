#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "util.h"
#include "init.h"
#include "gestion_manche.h"
#include "affichage.h"
#include "declarations.h"
#include "debug.h"
#include "menu.h"

void partie(S_joueur joueurs[NB_max_joueurs], int pile[DIM_pile], int *index_pile);

int main()
{
    int pile[DIM_pile];
    S_joueur joueurs[NB_max_joueurs];
    int quitter;
    int index_pile = DIM_pile-1;
    num_manche = 0;
    jetons_depart = 3; // Max des jetons par défaut
    delai_pioche = 5; // Temps pour piocher par défaut

    srand(time(NULL));
    color(BLANC, NOIR);
    apparence_console(24); // Zoom sur la fenêtre

    initialiser_pioche(pile);

    do{
        quitter = menu();
        
        if(quitter == 0)
        {
            partie(joueurs, pile, &index_pile);
        }
    }while(quitter == 0); // Tant que le joueur ne veut pas quitter

    return 0;
}

void partie(S_joueur joueurs[NB_max_joueurs], int pile[DIM_pile], int *index_pile)
{
    int nb_joueurs;
    system("cls");
    banniere();
    color(VERT, NOIR); afficher_encadre("D\x82""but de la partie"); color(BLANC, NOIR);

    initialiser_joueurs(joueurs, &nb_joueurs);

    if(nb_joueurs > 5) apparence_console(18); // Dézoom si il y a beaucoup de joueurs

    donneur_aleatoire(joueurs, nb_joueurs);
    distribuer_jetons(joueurs, nb_joueurs);

    do
    {
        num_manche++;
        system("cls");
        afficher_joueurs(joueurs, nb_joueurs);
        color(VERT, NOIR); afficher_encadre_int("D\x82""but de la manche %d", num_manche); color(BLANC, NOIR);
        system("pause");

        manche(joueurs, nb_joueurs, pile, index_pile);

        if(nb_joueur_valide(joueurs, nb_joueurs) > 1) // Pas besoin de trouver un nouveau donneur si il y a déjà un gagnant
        {
            donneur_suivant(joueurs, nb_joueurs); // Rotation du donneur

            system("cls");
            afficher_joueurs(joueurs, nb_joueurs);
            afficher_encadre_int("Fin de la manche % 2d", num_manche);
            color(JAUNE, NOIR); printf("Le nouveau donneur est %s\n\n", joueurs[get_donneur(joueurs, nb_joueurs)].nom); color(BLANC, NOIR);
            system("pause");
        }
    } while (nb_joueur_valide(joueurs, nb_joueurs) > 1);

    annoncer_gagnant(joueurs, nb_joueurs);

    system("pause");
    num_manche = 0; // Réinitialisation du nombre de manches
}