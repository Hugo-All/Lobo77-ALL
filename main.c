/*
    Projet d'algorithmique et programmation de première année à l'ESTACA
    Portage numérique du jeu de cartes LOBO77
    Réalisé par Hugo ALLAIRE et Tom ALLARD
*/

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

void partie(S_joueur joueurs[NB_max_joueurs], int pioche[DIM_pile], int *index_pioche);

int main()
{
    int pioche[DIM_pile];
    S_joueur joueurs[NB_max_joueurs];
    int quitter; // Stocke si le joueur veut quitter le programme ou non
    num_manche = 0; // Stocke numéro de la manche en cours
    jetons_depart = 3; // Max des jetons par défaut
    delai_pioche = 5; // Temps pour piocher par défaut

    srand(time(NULL));
    color(BLANC, NOIR);
    apparence_console(24); // Zoom sur la fenêtre

    initialiser_pioche(pioche);
    int index_pioche = DIM_pile-1; // Index de la dernière carte non-vide dans la pioche

    do
    {
        quitter = menu_principal(); // menu() renvoie 1 si le joueur veut quitter, 0 sinon

        if(quitter == 0) // Si le joueur n'a pas choisi de quitter
            partie(joueurs, pioche, &index_pioche);
    }while(quitter == 0); // Tant que le joueur ne veut pas quitter

    return 0;
}

// Joue une partie. A la fin d'une partie propose de recommencer avec les mêmes joueurs
void partie(S_joueur joueurs[NB_max_joueurs], int pioche[DIM_pile], int *index_pioche)
{
    int nb_joueurs;
    system("cls");
    banniere();
    color(VERT, NOIR); afficher_encadre("D\x82""but de la partie"); color(BLANC, NOIR);

    initialiser_joueurs(joueurs, &nb_joueurs);

    if(nb_joueurs > 5) apparence_console(18); // Dézoom si il y a beaucoup de joueurs

    do // Tant que le joueur veut recommencer avec les mêmes joueurs
    {
        donneur_aleatoire(joueurs, nb_joueurs);
        distribuer_jetons(joueurs, nb_joueurs);

        do // Boucle de manches
        {
            num_manche++;
            system("cls");
            afficher_joueurs(joueurs, nb_joueurs);
            color(VERT, NOIR); afficher_encadre_int("D\x82""but de la manche %d", num_manche); color(BLANC, NOIR);
            system("pause");

            manche(joueurs, nb_joueurs, pioche, index_pioche);

            if(nb_joueur_valide(joueurs, nb_joueurs) > 1) // Trouve un nouveau donneur si il n'y a pas encore de gagnant
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
        for(int i = 0; i < nb_joueurs; i++) joueurs[i].nb_jetons = 0; // Réinitialisation des jetons des joueurs
        num_manche = 0; // Réinitialisation du nombre de manches
    }while(choix_recommencer() == 1); // Demande au joueur si il veut recommencer une partie avec les mêmes joueurs
}
