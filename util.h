#include <windows.h>

enum E_couleurs{noir,
            bleu_fonce,
            vert_fonce,
            turquoise,
            rouge_fonce,
            violet,
            vert_oie,
            gris_clair,
            gris_fonce,
            bleu,
            vert,
            turquoise_2,
            rouge,
            violet_2,
            jaune,
            blanc
            };
typedef enum E_couleurs couleurs;

void color (int couleurDuTexte, int couleurDuFond);