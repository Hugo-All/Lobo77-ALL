#include "menu.h"

int menu() //Retourne 1 si le joueur veut quitter le jeu
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
            if(touche == TOUCHE_HAUT && curseur + 1 < nb_boutons)
                curseur++;
            else if(touche == TOUCHE_BAS && curseur - 1 >= 0)
                curseur--;

        }while(touche != TOUCHE_ENTER);
        
        if(curseur == 1)
        {
            options();
        }else if(curseur == 2)
        {
            regles();
        }else if(curseur == 3)
        {
            system("cls");
            banniere();
            color(VERT, NOIR); afficher_encadre("Au revoir !"); color(BLANC, NOIR);
            return 1; //Sort du menu et quitte le jeu
        }
    }while(curseur != 0);
    return 0; //Sort du menu sans quitter le jeu
}

void options()
{
    char touche = 0;
    char curseur = 0;
    char nb_boutons = 2;
    char buffer[DIM_STR];
    do{
        system("cls");
        banniere();

        afficher_petit_encadre("Nombre de jetons au d\x82""part: (0 \x85 3)");
        sprintf(buffer, "< %d >", jetons_depart);
        afficher_bouton(buffer, curseur == 0);

        barre_horizontale();

        afficher_petit_encadre("Nombre de secondes pour piocher:");
        sprintf(buffer, "< %d >", delai_pioche);
        afficher_bouton(buffer, curseur == 1);

        barre_horizontale();
        afficher_petit_encadre("Appuyez sur Entr\x82 pour valider");

        touche = get_fleches();

        switch (touche)
        {
            case TOUCHE_HAUT:
                if(curseur + 1 < nb_boutons)
                    curseur++;
                break;
            case TOUCHE_BAS:
                if(curseur - 1 >= 0)
                    curseur--;
                break;
            case TOUCHE_DROITE:
                if(curseur == 0 && jetons_depart + 1 <= NB_max_jetons)
                    jetons_depart++;
                else if(curseur == 1)
                    delai_pioche++;
                break;
            case TOUCHE_GAUCHE:
                if(curseur == 0 && jetons_depart - 1 >= 0)
                    jetons_depart--;
                else if(curseur == 1 && delai_pioche - 1 >= DELAI_PIOCHE_MIN)
                    delai_pioche--;
                break;
        }
    }while(touche != TOUCHE_ENTER);

    //Affichage du récapitulatif des options
    system("cls");
    banniere();
    color(VERT, NOIR);
    afficher_encadre_int("%d jeton(s) au d\x82""part", jetons_depart);
    afficher_encadre_int("%d secondes pour piocher", delai_pioche);
    color(BLANC, NOIR);
    system("pause");
}

void regles()
{
    char nb_diapos = 5;
    char curseur = 0;
    char touche;
    char buffer[20];
    int exemple_cartes[DIM_pile];
    initialiser_pile(exemple_cartes);
    int carte_aleatoire;

    do{
        system("cls");
        banniere();
        sprintf(buffer, "Panneau %d/%d", curseur + 1, nb_diapos);
        afficher_encadre(buffer);
        switch (curseur)
        {
            case 0:
                color(VERT, NOIR); afficher_petit_encadre("R\x8A""gles du jeu LOBO77:"); color(BLANC, NOIR);
                printf("Pour remporter une partie de LOBO 77 il faut \x88""tre le dernier joueur avec des jetons ou en train de \"nager\".\n");
                printf("Pour y parvenir, il faut respecter deux principes fondamentaux :\n\n");
                printf("\t- La d\x82""fausse ne doit jamais afficher un multiple de 11\n");
                printf("\t- La d\x82""fausse ne doit jamais atteindre ou d\x82""passer 77\n\n");

                color(ROUGE, NOIR);
                printf("Si un de ces principes n'est pas respect\x82"", alors vous perdez un des 3 jetons qui vous est distribu\x82 au d\x82""part.\n");
                printf("Lorsque vous perdez vos 3 jetons vous \"nagez\" et la prochaine erreur est synonyme d'\x82""limination.\n");
                color(BLANC, NOIR);
                break;
            case 1:
                color(VERT, NOIR); afficher_petit_encadre("D\x82""roulement du jeu"); color(BLANC, NOIR);
                printf("En d\x82""but de manche les joueurs (compris entre 2 et 8) re\x87""oivent tous 5 cartes parmi\n");
                printf("celles expos\x82""es ci-dessus ainsi que 3 jetons");
                color(VERT, NOIR); printf("(configurable pour une partie plus rapide).\n\n"); color(BLANC, NOIR);
                printf("De plus, un \"donneur\" est s\x82""lectionn\x82"", le joueur \x85 sa gauche est d\x82""finie comme premier joueur \x85 poser une carte.\n");

                printf("La manche est donc lanc\x82""e, il faut maintenant respecter les 2 principes fondamentaux pour ne pas perdre de jetons.\n");
                
                color(ROUGE, NOIR);
                printf("Mais \x82""galement ne pas oublier de piocher une carte apr\x8A""s avoir jou\x82""\n");
                printf("sous peine d'avoir un choix plus restreint et m\x88""me de perdre un jeton lorsque votre main est vide.\n\n");
                printf("La manche est termin\x82 seulement lorsqu'on atteint ou d\x82""passe 77:\n");
                color(BLANC, NOIR);
                printf("atteindre un multiple de 11 autre que 77 fera seulement perdre un jeton au joueur en question mais la manche continue.\n\n");

                printf("Lorsque la pioche est vide, on r\x82""cup\x8A""re la d\x82""fausse, on la m\x82""lange et on l'utilise \x85 nouveau comme pioche.\n");
                break;
            case 2:
                do{ //On prend une carte aléatoire qui n'est pas une carte spéciale
                    carte_aleatoire = exemple_cartes[rand() % DIM_pile];
                }while(carte_aleatoire == CARTE_SENS || carte_aleatoire == CARTE_X2);
                color(VERT, NOIR); afficher_petit_encadre("Cartes normales"); color(BLANC, NOIR);
                printf("Voici les diff\x82""rentes cartes normales:\n");
                printf("\t- 4 cartes 0\n");
                printf("\t- 4 cartes -10\n");
                printf("\t- 6 cartes multiple de 11 (entre 11 et 66)\n");
                printf("\t- 8 cartes 10\n");
                printf("\t- 3 cartes par chiffre de 2 \x85 9\n\n");
                printf("Par exemple, cette carte ajoutera %d \x85 la d\x82""fausse.\n\n", carte_aleatoire);
                afficher_carte(carte_aleatoire);
                break;
            case 3:
                color(VERT, NOIR); afficher_petit_encadre("Cartes changement de sens (5 dans le jeu)"); color(BLANC, NOIR);
                printf("Inverse le sens de jeu.\n\n");
                afficher_carte(CARTE_SENS);
                break;
            case 4:
                color(VERT, NOIR); afficher_petit_encadre("Cartes x2 (4 dans le jeu)"); color(BLANC, NOIR);
                printf("Demande au joueur suivant de jouer 2 cartes.\n\n");
                color(ROUGE, NOIR); printf("Le joueur suivant ne pourra pas jouer de cartes x2 en premier.\n\n"); color(BLANC, NOIR);
                afficher_carte(CARTE_X2);
                break;
        }

        printf("\n");
        barre_horizontale();
        afficher_petit_encadre("Navigez avec < > puis Enter pour sortir");

        touche = get_fleche_horizontale();
        if(touche == TOUCHE_DROITE && curseur + 1 < nb_diapos)
            curseur++;
        else if(touche == TOUCHE_GAUCHE && curseur - 1 >= 0)
            curseur--;
    }while(touche != TOUCHE_ENTER);
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
