#define DIM_STR 10
#define DIM_pile 56
#define DIM_main_joeur 5
#define NB_max_joueurs 8

typedef struct joueur{
    char nom[DIM_STR];
    int cartes[5];
    int nb_jetons;
} joueur;

int pile[DIM_pile];
int defausse[DIM_pile];
joueur joueurs[NB_max_joueurs];