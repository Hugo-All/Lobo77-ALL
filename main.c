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
    initialiser_pile(pile);
    initialiser_defausse(defausse);
    index_donneur=0;
    /*initialiser_joueurs(joueurs, &nb_joueurs);
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs, index_donneur);*/
    return 0;
}
