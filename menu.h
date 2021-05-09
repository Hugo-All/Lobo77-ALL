#ifndef INCLUDE_MENU_H
#define INCLUDE_MENU_H

#include <stdio.h>
#include <stdlib.h>

#include "declarations.h"
#include "affichage.h"
#include "util.h"
#include "init.h"

// Affiche le menu principal. Retourne 1 si le joueur souhaite quitter, 0 sinon
int menu();
void options(); // Affiche et gère les options
void regles(); // Affiche les règles

// Affiche "texte" dans un encadré centré à double bordure. Avec un fond turquoise si curseur==0
void afficher_bouton(char *texte, int curseur);

#endif