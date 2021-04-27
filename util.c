#include "util.h"

void color (int couleurDuTexte, int couleurDuFond)
{
     HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}

void gets_limite(char *sortie, int limite)
{
     fflush(stdin);
     fgets(sortie, limite, stdin);
     strtok(sortie, "\n");  // Enlève le retour à la ligne à la fin du nom
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

int attend_touche(int timeout)
{
     int start = time(NULL);
     fflush(stdin); // S'assure que le buffer est vide avant d'attendre la pression d'une touche
     while (time(NULL) - start < timeout)
          if(kbhit()!=0)
               return 1; // Une touche a été pressée dans le temps imparti

     return 0; // Pas de touche pressée
}

int selectionner_carte(S_joueur joueurs[NB_max_joueurs], S_joueur joueur, int nb_joueurs)
{
     char touche;
     int curseur;
     for(int i = 0; i < DIM_main_joueur; i++) // Place le curseur sur une carte non-vide
     {
          if(joueur.cartes[i] != CARTE_VIDE)
          {
               curseur = i;
               break;
          }
     }

     do // Tant que le joueur n'as pas appuyé sur entré
     {
          system("cls");
          afficher_joueurs(joueurs, nb_joueurs);
          
          printf("\nVeuillez selectionner une carte:\n");

          afficher_cartes(joueur, curseur);
          touche=get_touche();

          switch (touche)
          {
               case TOUCHE_GAUCHE:
                    for(int i = curseur - 1; i >= 0; i--)
                    {
                         if(joueur.cartes[i] != CARTE_VIDE) // Trouve une carte non-vide à gauche du curseur
                         {
                              curseur = i;
                              break;
                         }
                    }
                    break;
               case TOUCHE_DROITE:
                    for(int i = curseur + 1; i < DIM_main_joueur; i++)
                    {
                         if(joueur.cartes[i] != CARTE_VIDE) // Trouve une carte non-vide à droite du curseur
                         {
                              curseur = i;
                              break;
                         }
                    }
                    break;

               default:
                    break;
          }

     }while(touche != TOUCHE_ENTER);

     return curseur;
}

char get_touche()
{
     char touche;
     fflush(stdin);
     do{
          touche = getch();
     }while(touche != TOUCHE_GAUCHE && touche != TOUCHE_DROITE && touche != TOUCHE_ENTER);

    return touche;
}