#include "affichage.h"

// Affiche une bannière avec le nom du jeu et le numéro de la manche si il est non nul
void banniere()
{
    if(num_manche > 0)
    {
        printf("%c", 186);
        for(int i = 0; i < LARGEUR_AFFICHAGE - 2; i++) printf(" ");
        printf("%c\n", 186);

        printf("%c", 186);
        for(int i = 0; i < 14; i++) printf(" ");
        printf("Manche num\x82""ro %-2d", num_manche);
        for(int i = 0; i < 13; i++) printf(" ");
        printf("%c\n", 186);
        
        printf("%c", 186);
        for(int i = 0; i < LARGEUR_AFFICHAGE - 2; i++) printf(" ");
        printf("%c\n", 186);
    }
    
    printf("%c", 200);
    for(int i = 0; i < 16; i++)
        printf("%c", 205);
    printf("  LOBO 77  ");
    for(int i = 0; i < 16; i++)
        printf("%c", 205);
    printf("%c\n\n", 188);
}

// Affiche une barre horizontale de largeur LARGEUR_AFFICHAGE
void barre_horizontale()
{
    for(int i = 0; i < LARGEUR_AFFICHAGE; i++)
        printf("%c", 205);
    printf("\n\n");
}

// Affiche le sens du jeu, le nom des joueurs, leurs jetons, leurs cartes et qui est le donneur
void afficher_joueurs(S_joueur joueurs[NB_max_joueurs], int nb_joueurs)
{
    banniere();

    printf("Sens  Nom        Jetons  Cartes        Donneur\n\n");
    for(int i = 0; i < nb_joueurs; i++) // Parcours chaque joueur
    {
        if(joueurs[i].sens_jeu != 0) // Si le joueur en cours d'affichage est en train de jouer
        {
            if(joueurs[i].sens_jeu == SENS_HORAIRE)
                printf("  v   ");
            else
                printf("  ^   ");
        }else
        {
            printf("      ");
        }

        printf("%-10s ", joueurs[i].nom); // Affiche le nom du joueur

        // Il faut qu'un joueur soit toujours vivant pour être affiché
        if(joueurs[i].nb_jetons >= 0)
        {
            // Affiche les jetons du joueur
            color(BLEU, NOIR); // Affichage des jetons en bleu comme dans le jeu physique
            for(int j = 1; j <= NB_max_jetons; j++)
            {
                if(joueurs[i].nb_jetons >= j)
                    printf("%c ", 254);
                else
                    printf("  ");

            }
            printf("  ");
            color(BLANC, NOIR); // Remise à zéro de la couleur

            // Affiche des carrés à la place des cartes du joueur
            for(int j = 0; j < DIM_main_joueur; j++)
            {
                if(joueurs[i].cartes[j] == CARTE_VIDE)
                {
                    printf("%c ", 176);
                }else{
                    printf("%c ", 219);
                }
            }
            printf("   ");

            // Affiche un (D) si le joueur est le donneur
            if(joueurs[i].donneur == 1)
            {
                printf(" (D)    ");
            }else
            {
                printf(" ( )    ");
            }

        }else
        {
            printf("Elimin\x82");
        }
        printf("\n\n");
    }
    barre_horizontale();
}

// Affiche les cartes du joueur à l'horizontal
void afficher_cartes(S_joueur joueur, int curseur)
{
    char buffer_ligne[9];

    afficher_encadre_str("Cartes de %s", joueur.nom);

    // Affiche le haut de chaque cartes
    sprintf(buffer_ligne, "%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 187);
    afficher_ligne_cartes(joueur, buffer_ligne, curseur);

    // Affiche 2 lignes intermédiaires
    sprintf(buffer_ligne, "%c      %c", 186, 186);
    for(int i = 0; i < 2; i++)
        afficher_ligne_cartes(joueur, buffer_ligne, curseur);

    // Affiche la ligne contenant le type de carte
    for(int i_carte = 0; i_carte < DIM_main_joueur; i_carte++)
    {
        color(BLANC, NOIR);
        printf(" "); // Espacement entre les cartes
        if(joueur.cartes[i_carte] != CARTE_VIDE)
        {
            if(i_carte == curseur) color(NOIR, TURQUOISE_2); // Couleurs du curseur
            switch (joueur.cartes[i_carte])
            {
                case CARTE_SENS :
                    printf("%c SENS %c", 186, 186);
                    break;
                case CARTE_X2 :
                    printf("%c  X2  %c", 186, 186);
                    break;
                default :
                    printf("%c % 3d  %c", 186, joueur.cartes[i_carte], 186);
            }
        }
        else
            printf("        ");
    }
    printf("\n");

    // Affiche 2 lignes intermédiaires
    sprintf(buffer_ligne, "%c      %c", 186, 186);
    for(int i = 0; i < 2; i++)
        afficher_ligne_cartes(joueur, buffer_ligne, curseur);

    // Affiche le bas de chaque cartes
    sprintf(buffer_ligne, "%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 188);
    afficher_ligne_cartes(joueur, buffer_ligne, curseur);

    color(BLANC, NOIR); // Remet à 0 les couleurs
    printf("\n");
}

// Affiche une portion de chaque cartes
void afficher_ligne_cartes(S_joueur joueur, char ligne[9], int curseur)
{
    for(int i_carte = 0; i_carte < DIM_main_joueur; i_carte++) // Parcours chaque cartes du joueur
    {
        color(BLANC, NOIR); // Remet à 0 les couleurs
        printf(" "); // Espacement entre les cartes
        if(joueur.cartes[i_carte] != CARTE_VIDE)
        {
            if(i_carte == curseur) color(NOIR, TURQUOISE_2); // Couleurs du curseur
            printf("%s", ligne);
        }
        else
            printf("        "); // Si la carte est vide, imprimer des espaces
        color(BLANC, NOIR); // Remet à 0 les couleurs
    }
    printf("\n");
}

// Affiche une carte
void afficher_carte(int carte)
{
    int marge = (LARGEUR_AFFICHAGE - 8)/2; // Calcul de la marge nécéssaire pour le centrage

    for(int i = 0; i < marge; i++) printf(" "); // Affichage de la marge
    printf("%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 187); // Ligne supérieure de la carte

    for(int i = 0; i < 2; i++) // Lignes intermédiaires
    {
        for(int j = 0; j < marge; j++) printf(" ");
        printf("%c      %c\n", 186, 186);
    }

    for(int i = 0; i < marge; i++) printf(" ");
    switch (carte) // Ligne de texte de la carte
    {
        case CARTE_SENS :
            printf("%c SENS %c\n", 186, 186);
            break;
        case CARTE_X2 :
            printf("%c  X2  %c\n", 186, 186);
            break;
        default :
            printf("%c % 3d  %c\n", 186, carte, 186);
    }

    for(int i = 0; i < 2; i++) // Lignes intermédiaires
    {
        for(int j = 0; j < marge; j++) printf(" ");
        printf("%c      %c\n", 186, 186);
    }

    for(int i = 0; i < marge; i++) printf(" ");
    printf("%c%c%c%c%c%c%c%c\n\n", 200, 205, 205, 205, 205, 205, 205, 188); // Ligne inférieure de la carte
}

// Affiche "format" dans un encadré centré à double bordure et remplace un %d par "donnee"
void afficher_encadre_int(char format[], int donnee)
{
    char ligne[30];
    sprintf(ligne, format, donnee);

    afficher_encadre(ligne);
}

// Affiche "format" dans un encadré centré à double bordure et remplace un %s par "donnee"
void afficher_encadre_str(char format[], char donnee[])
{
    char ligne[30];
    sprintf(ligne, format, donnee);

    afficher_encadre(ligne);
}

// Affiche "ligne" dans un encadré centré avec une double bordure
void afficher_encadre(char ligne[]) 
{
    char buffer[strlen(ligne) + 1];
    if(strlen(ligne) % 2 == 0) // Si la ligne à afficher est de longueur pair, on rajoute un espace
    {
        strcpy(buffer, ligne);
        strcat(buffer, " ");
    }else{
        strcpy(buffer, ligne);
    }

    int marge = (LARGEUR_AFFICHAGE - (strlen(buffer) + 4))/2; // Calcul de la marge nécéssaire pour le centrage

    for(int i = 0; i < marge; i++) printf(" "); // Affichage de la marge
    printf("%c", 201); // Affiche le coin supérieur gauche
    for(int i = 0; i < strlen(buffer) + 2; i++) // Affiche la bordure supérieur
        printf("%c", 205);
    printf("%c\n", 187); // Affiche le coin supérieur droit

    for(int i = 0; i < marge; i++) printf(" ");
    printf("%c %s %c\n", 186, buffer, 186); // Affiche "ligne"

    for(int i = 0; i < marge; i++) printf(" ");
    printf("%c", 200); // Affiche le coin inférieur gauche
    for(int i = 0; i < strlen(buffer) + 2; i++) // Affiche la bordure inférieure
        printf("%c", 205);
    printf("%c\n\n", 188); // Affiche le coin inférieur droit
}

// Affiche "ligne" dans un encadré centré avec une simple bordure
void afficher_petit_encadre(char ligne[])
{
    char buffer[strlen(ligne) + 1];
    if(strlen(ligne) % 2 == 0) // Si la ligne à afficher est de longueur paire, on rajoute un espace
    {
        strcpy(buffer, ligne);
        strcat(buffer, " ");
    }else{
        strcpy(buffer, ligne);
    }

    int marge = (LARGEUR_AFFICHAGE - (strlen(buffer) + 4))/2; // Calcul de la marge nécéssaire pour le centrage

    for(int i = 0; i < marge; i++) printf(" "); // Affichage de la marge
    printf("%c", 218); // Affiche le coin supérieur gauche
    for(int i = 0; i < strlen(buffer) + 2; i++) // Affiche la bordure supérieur
        printf("%c", 196);
    printf("%c\n", 191); // Affiche le coin supérieur droit

    for(int i = 0; i < marge; i++) printf(" ");
    printf("%c %s %c\n", 179, buffer, 179); // Affiche "ligne"

    for(int i = 0; i < marge; i++) printf(" ");
    printf("%c", 192); // Affiche le coin inférieur gauche
    for(int i = 0; i < strlen(buffer) + 2; i++) // Affiche la bordure inférieure
        printf("%c", 196);
    printf("%c\n\n", 217); // Affiche le coin inférieur droit
}

// Affiche la bannière, les joueurs, le total de la défausse, puis une barre horizontale
void afficher_joueurs_et_total(S_joueur joueurs[NB_max_joueurs], int nb_joueurs, int total_defausse)
{
    system("cls");
    afficher_joueurs(joueurs, nb_joueurs);
    afficher_encadre_int("  Total: % 3d ", total_defausse);
    barre_horizontale();
}

// Affiche la console en plein écran et applique un zoom de valeur "zoom"
void apparence_console(int zoom)
{
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof cfi;
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = zoom;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;

    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

// Joue une animation qui simule le mélange d'une pile
void animation_melanger_pile(S_joueur joueurs[NB_max_joueurs], int nb_joueurs)
{
    char *animation[5] = {"    ", "\xDB   ", " \xDB  ", "  \xDB ", "   \xDB"};
    for(int i = 0; i < 16; i++)
    {
        system("cls");
        afficher_joueurs(joueurs, nb_joueurs);
        afficher_encadre_str("M\x82""lange des cartes ""\xDB""%s\xDB", animation[i % 5]);
        Sleep(300);
    }

    system("cls");
    afficher_joueurs(joueurs, nb_joueurs);
    color(VERT, NOIR); afficher_encadre("M\x82""lange des cartes termin\x82"); color(BLANC, NOIR);
    system("pause");
}