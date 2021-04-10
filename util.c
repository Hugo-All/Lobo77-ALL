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