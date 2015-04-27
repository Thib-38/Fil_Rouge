#include <stdlib.h>
#include <string.h>

#include "ensemble.h"
#include "suspect.h"

#include "tests.h"

int
main(int argc, char **argv) {
    struct liste_suspects *l = creer_liste_suspects();
    CHECK("Création de la liste de suspects",
          (l != NULL)
          && (l->nb_suspects == 0)
          && (l->queue == NULL)
          && (l->tete == NULL));

    struct suspect *s1 = creer_suspect("A", 0);
    CHECK("Création de suspect (A, 0)",
          (s1 != NULL)
          && (strcmp(s1->nom, "A") == 0)
          && (s1->attributs == 0)
          && (s1->suiv == NULL)
          && (s1->prec == NULL));

    struct suspect *snull = creer_suspect(NULL, 0);
    CHECK("Création de suspect (NULL, 0)", (snull == NULL));
    
    ajouter_suspect(l, s1);
    CHECK("Ajout d'un suspect à la liste",
          (l != NULL)
          && (l->tete == s1)
          && (l->queue == s1)
          && (l->nb_suspects == 1));

    struct suspect *s2 = creer_suspect("B", 1);
    ajouter_suspect(l, s2);
    CHECK("Ajout d'un 2e suspect à la liste",
          (l != NULL)
          && (l->tete == s1)
          && (l->queue == s2)
          && (l->nb_suspects == 2)
          && (s1->suiv == s2)
          && (s2->prec == s1));


/* TEST POUR DEBUG PERSO */
struct suspect *s3 = creer_suspect("C", 2);
ajouter_suspect(l, s3);
struct suspect *s4 = creer_suspect("D", 3);
printf("\n On a ajouté A,0 ; B,1 ; C,2 \n");
affiche_liste_suspects(l);
printf("\n On essaye de supprimer D,3 ! \n ");
retirer_suspect(l, s4);
affiche_liste_suspects(l);
printf("\n On ajoute D,3 ! \n");
ajouter_suspect(l, s4);
affiche_liste_suspects(l);
printf("\n On essaye de supprimer C,2 ! \n ");
retirer_suspect(l, s3);
affiche_liste_suspects(l);
printf("\n On detruit la liste \n ");
detruire_liste_suspects(l);
/*--------------------- */

/* ----- Test prof ----------

    retirer_suspect(l, s2);
    CHECK("Retrait d'un suspect de la liste (1)",
          (l != NULL)
          && (l->tete == s1)
          && (l->queue == s1)
          && (l->nb_suspects == 1));

    retirer_suspect(l, s1);
    CHECK("Retrait d'un suspect de la liste (2)",
          (l != NULL)
          && (l->nb_suspects == 0)
          && (l->queue == NULL)
          && (l->tete == NULL));

------------------------------ */
    
    return 0;
}
