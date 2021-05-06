#ifndef INCLUDE_MENU_H
#define INCLUDE_MENU_H

#include <stdio.h>
#include <stdlib.h>

#include "declarations.h"
#include "affichage.h"
#include "util.h"
#include "init.h"

int menu();
void options();
void regles();

int choix_recommencer();

void afficher_bouton(char *texte, int curseur);

#endif