#include "menu.h"

void afficher_bouton(char *texte, int curseur)
{
    char buffer[strlen(texte) + 1];
    if(strlen(texte) % 2 == 0) //Si la ligne à afficher est de longueur pair, on rajoute un espace
    {
        strcpy(buffer, texte);
        strcat(buffer, " ");
    }else{
        strcpy(buffer, texte);
    }

    int marge = (LARGEUR_AFFICHAGE - (strlen(buffer) + 4))/2; //Calcul de la marge nécéssaire pour le centrage

    for(int i = 0; i < marge; i++) printf(" "); //Affichage de la marge

    if(curseur == 1) color(NOIR, TURQUOISE_2); //Si le bouton est sélectionnée, on change les couleurs
    printf("%c", 201);
    for(int i = 0; i < strlen(buffer) + 2; i++)
        printf("%c", 205);
    printf("%c", 187);
    color(BLANC, NOIR);

    printf("\n");
    for(int i = 0; i < marge; i++) printf(" ");

    if(curseur == 1) color(NOIR, TURQUOISE_2);
    printf("%c %s %c", 186, buffer, 186);

    color(BLANC, NOIR);
    printf("\n");
    for(int i = 0; i < marge; i++) printf(" ");

    if(curseur == 1) color(NOIR, TURQUOISE_2);
    printf("%c", 200);
    for(int i = 0; i < strlen(buffer) + 2; i++)
        printf("%c", 205);
    printf("%c", 188);

    color(BLANC, NOIR); printf("\n\n");
}
