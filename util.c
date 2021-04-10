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

void melanger_pile(int cartes[DIM_pile],char nb_cartes)//Mélange les nb_cartes premières cartes d'une pile
{
     int temp_pile[DIM_pile];
     for(int i = 0; i < DIM_pile; i++)
          temp_pile[i]=CARTE_NULLE;

     int index_aleatoire;
     for(int i = 0; i < nb_cartes; i++)//Sélectionne chaque carte de la pile à mélanger
     {
          do{
               index_aleatoire = rand() % nb_cartes;//Sélectionne un index au hasard
          }while(temp_pile[index_aleatoire] != CARTE_NULLE);//Vérifie que la case sélectionnée au hasard est vide

          temp_pile[index_aleatoire] = cartes[i];//Place la carte sélectionner dans la case aléatoire
     }

     for(int i = 0; i < nb_cartes; i++)
          cartes[i]=temp_pile[i];
}
