#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"
#include "init.h"
#include "gestion_manche.h"
#include "affichage.h"
#include "declarations.h"
#include "debug.h"

int main()
{
    srand(time(NULL));
    color(BLANC,NOIR);
    //SetConsoleOutputCP(1252);

    index_donneur = 0;
    index_pile = DIM_pile-1;
    index_defausse = 0;
    initialiser_joueurs(joueurs, &nb_joueurs);
    //system("cls");
    initialiser_pile(pile);
    initialiser_defausse(defausse);
    melanger_pile(pile, index_pile);

    distribuer_cartes(pile, &index_pile, joueurs, nb_joueurs, index_donneur);

    joueurs[0].cartes[0] = CARTE_VIDE;
    afficher_joueurs(joueurs, nb_joueurs, index_donneur);
    int carte = selectionner_carte(joueurs, joueurs[0], nb_joueurs, index_donneur);

    printf("%d\n", carte);
    return 0;
}
