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

    joueurs[5].donneur = 1;
    joueurs[5].sens_jeu = SENS_HORAIRE;

    
    //system("cls");

    index_pile = DIM_pile-1;
    initialiser_pile(pile);
    melanger_pile(pile, index_pile);

    initialiser_joueurs_DEBUG(joueurs, &nb_joueurs);
    distribuer_cartes_DEBUG(pile, &index_pile, joueurs, nb_joueurs);
    
    manche(joueurs, nb_joueurs, pile, &index_pile);

    return 0;
}
