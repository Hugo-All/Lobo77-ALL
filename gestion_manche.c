#include "gestion_manche.h"void vider_defausse(int pile[DIM_pile], int defausse[DIM_pile], int *index_pile, int *index_defausse)
{
    for(int i = *index_defausse; i >= 0; i--)
    {
        (*index_pile)++; //Incrémente le nombre de carte dans la pile
        (*index_defausse)--; //Décrémente le nombre de carte dans la défausse

        pile[*index_pile] = defausse[i]; //Transfère la carte de la défausse vers la pile
        defausse[i] = CARTE_VIDE; //Remplace la carte transférée par la carte vide
    }
}
