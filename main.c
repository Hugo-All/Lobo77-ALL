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
    //SetConsoleOutputCP(1252);

    index_donneur = 0;
    index_pile = DIM_pile;
    index_defausse = 0;
    initialiser_joueurs_DEBUG(joueurs, &nb_joueurs);
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs, index_donneur);
    initialiser_pile(pile);
    initialiser_defausse(defausse);
    afficher_pile(pile);
    melanger_pile(pile,index_pile);
    afficher_pile(pile);
    //distribuer_cartes(pile, index_pile, joueurs, nb_joueurs, index_donneur);
    printf("%d\n",attend_touche(5));
    system("pause");
    /*
    for(int i = 0; i<10000;i++){
        melanger_pile(pile, 40);
        afficher_pile(pile);
    }*/
    return 0;
}
