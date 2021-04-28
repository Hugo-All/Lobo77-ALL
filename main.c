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
    //SetConsoleOutputCP(1252);
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);

    index_pile = DIM_pile-1;
    initialiser_pile(pile);
    melanger_pile(pile, index_pile);

    joueurs[0].donneur = 1;
    initialiser_joueurs(joueurs, &nb_joueurs);
    distribuer_jetons(joueurs, nb_joueurs);
    distribuer_cartes(pile, &index_pile, joueurs, nb_joueurs);
    
    manche(joueurs, nb_joueurs, pile, &index_pile);
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs);
    printf("Fin de la manche demo.\n");
    system("pause");

    return 0;
}
