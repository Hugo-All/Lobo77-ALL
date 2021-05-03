#include "menu.h"

void menu()
{
    char touche = 0;
    char curseur = 0;
    char nb_boutons = 4;
    do{
        do{
            system("cls");
            banniere();

            afficher_bouton("Nouvelle partie", curseur==0);
            afficher_bouton("Options", curseur==1);
            afficher_bouton("R""\x8A""gles", curseur==2);
            afficher_bouton("Quitter", curseur==3);

            touche = get_fleche_verticale();
            if(touche == TOUCHE_HAUT && curseur + 1 <= nb_boutons - 1)
                curseur++;
            else if(touche == TOUCHE_BAS && curseur - 1 >= 0)
                curseur--;

        }while(touche != TOUCHE_ENTER);

        if(curseur == 1)
        {
            options();
        }else if(curseur == 2)
        {
            printf("REGLES"); system("pause");
        }else if(curseur == 3)
        {
            system("cls");
            banniere();
            color(VERT, NOIR); afficher_encadre("Au revoir !"); color(BLANC, NOIR);
            exit(0);
        }
    }while(curseur != 0);
}

void options()
{
    char touche = 0;
    do{
        system("cls");
        banniere();

        afficher_petit_encadre("Nombre de jetons au d\x82""part:");
        afficher_encadre_int("< %d >", jetons_depart);
        afficher_petit_encadre("Appuyez sur Entr\x82 pour valider");

        touche = get_fleche_horizontale();
        if(touche == TOUCHE_DROITE && jetons_depart + 1 <= NB_max_jetons)
            jetons_depart++;
        else if(touche == TOUCHE_GAUCHE && jetons_depart - 1 >= 0)
            jetons_depart--;

    }while(touche != TOUCHE_ENTER);

    system("cls");
    banniere();
    color(TURQUOISE_2, NOIR); afficher_encadre_int("%d jeton(s) au d\x82""part", jetons_depart); color(BLANC, NOIR);
    system("pause");
}

void afficher_bouton(char *texte, int curseur)
{
    char buffer[strlen(texte) + 1];
    if(strlen(texte) % 2 == 0) //Si la ligne à afficher est de longueur paire, on rajoute un espace
    {
        strcpy(buffer, texte);
        strcat(buffer, " ");
    }else{
        strcpy(buffer, texte);
    }

    int marge = (LARGEUR_AFFICHAGE - (strlen(buffer) + 4))/2; //Calcul de la marge nécéssaire pour le centrage

    for(int i = 0; i < marge; i++) printf(" "); //Affichage de la marge

    if(curseur == 1) color(NOIR, TURQUOISE_2); //Si le bouton est sélectionné, on change les couleurs
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
