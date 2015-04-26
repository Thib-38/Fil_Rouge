#include "suspect.h"
#include <stdlib.h>
#include <string.h>

struct suspect *creer_suspect(const char *name, ensemble_t attributs) {
        if (name == NULL)
	{
		return NULL;
	}
	else
	{
		const char *name2 = name;
		struct suspect *le_suspect = malloc(sizeof(struct suspect));
		le_suspect->nom = name2;
		le_suspect->attributs = attributs;
		le_suspect->suiv = NULL;
		le_suspect->prec = NULL;
		return le_suspect;
	}
}

struct liste_suspects *creer_liste_suspects(void) {
        struct liste_suspects *liste_vide = malloc(sizeof(struct liste_suspects));
	liste_vide->nb_suspects = 0;
	liste_vide->tete = NULL;
	liste_vide->queue = NULL;
}

void detruire_liste_suspects(struct liste_suspects **l) {
	while((*l)->nb_suspects != 0)
		retirer_suspect(*l,(*l)->tete);
	free(l);
	free(*l);
}

void ajouter_suspect(struct liste_suspects *liste, struct suspect *suspect) {
	if (liste->nb_suspects == 0)
	{
		liste->nb_suspects = 1;
		liste->tete = suspect;
		liste->queue = suspect;
		(liste->tete)->prec = NULL;
		(liste->tete)->suiv = NULL;
		(liste->queue)->prec = NULL;
		(liste->queue)->suiv = NULL;
	}
	else
	{
		liste-> nb_suspects += 1;
		struct suspect *temp = liste->queue;
		(liste->queue)->suiv = suspect;
		liste->queue = suspect;
		(liste->queue)->suiv = NULL;
		(liste->queue)->prec = temp;
	}
}

void retirer_suspect(struct liste_suspects *liste, struct suspect *suspect) {
}

void affiche_liste_suspects(struct liste_suspects *l) {
}
