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
    index_donneur=0;
    /*initialiser_joueurs(joueurs, &nb_joueurs);
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs, index_donneur);*/
    initialiser_pile(pile);
    afficher_pile(pile);
    return 0;
}
