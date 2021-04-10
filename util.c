#include "util.h"

void color (int couleurDuTexte, int couleurDuFond)
{
     HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}

void gets_limite(int limite, char *sortie)
{
     fflush(stdin);
     fgets(sortie,limite, stdin);
     strtok(sortie, "\n");//Enlève le retour à la ligne à la fin du nom
     fflush(stdin);
}

void melanger_pile(int cartes[DIM_pile],char nb_cartes) // Mélange les nb_cartes premières cartes d'une pile
{
     int i, index_aleatoire, carte_temp;

     for (i = nb_cartes - 1; i > 0; i--) { // Parcours toute les cartes de la pile de la nb_cartes vers le début
         index_aleatoire = rand() % (i + 1); // Trouve une case aléatoire
         carte_temp = cartes[index_aleatoire]; // Echange la case choisie aléatoirement avec la case en cours
         cartes[index_aleatoire] = cartes[i];
         cartes[i] = carte_temp;
     }
}
