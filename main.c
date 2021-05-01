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

int main()
{
    srand(time(NULL));
    color(BLANC, NOIR);
    apparence_console();

    index_pile = DIM_pile-1;
    initialiser_pile(pile);
    melanger_pile(pile, index_pile);

    banniere();
    printf("Bienvenue sur LOBO77. Par Hugo ALLAIRE et Tom ALLARD\n\n");

    initialiser_joueurs(joueurs, &nb_joueurs);
    donneur_aleatoire(joueurs, nb_joueurs);
    distribuer_jetons(joueurs, nb_joueurs);

    int num_manche = 1;
    do
    {
        system("cls");
        afficher_joueurs(joueurs, nb_joueurs);
        afficher_encadre_int("Manche numero: % 2d", num_manche);
        system("pause");

        manche(joueurs, nb_joueurs, pile, &index_pile);

        if(nb_joueur_valide(joueurs, nb_joueurs) > 1) //Pas besoin de trouver un nouveau donneur si il y a déjà un gagnant
        {
            donneur_suivant(joueurs, nb_joueurs); //Rotation du donneur

            system("cls");
            afficher_joueurs(joueurs, nb_joueurs);
            afficher_encadre_int("Fin de la manche % 2d", num_manche);
            color(JAUNE, NOIR); printf("\nLe nouveau donneur est %s\n\n", joueurs[get_donneur(joueurs, nb_joueurs)].nom); color(BLANC, NOIR);
            system("pause");
            num_manche++;
        }
    } while (nb_joueur_valide(joueurs, nb_joueurs) > 1);

    annoncer_gagnant(joueurs, nb_joueurs);

    system("pause");

    return 0;
}
