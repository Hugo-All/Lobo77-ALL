#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "init.h"
#include "gestion_manche.h"
#include "affichage.h"
#include "declarations.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    index_donneur=0;
    initialiser_joueurs(joueurs, &nb_joueurs);
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs, index_donneur);
    return 0;
}
