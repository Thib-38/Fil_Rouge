#include "suspect.h"
#include <stdlib.h>
#include <string.h>

struct suspect *creer_suspect(const char *name, ensemble_t attributs) {
/*OK*/
        if (name == NULL)
	{
		return NULL;
	}
	else
	{
		char *copie_pointeur_de_nom = strdup(name);
		struct suspect *le_suspect = malloc(sizeof(struct suspect));
		le_suspect->nom = copie_pointeur_de_nom;
		le_suspect->attributs = attributs;
		le_suspect->suiv = NULL;
		le_suspect->prec = NULL;
		return le_suspect;
	}
}

struct liste_suspects *creer_liste_suspects(void) {
/*OK*/
        struct liste_suspects *liste_vide = malloc(sizeof(struct liste_suspects));
	liste_vide->nb_suspects = 0;
	liste_vide->tete = NULL;
	liste_vide->queue = NULL;
	return liste_vide;
}

void detruire_liste_suspects(struct liste_suspects **l) {
/* KOOOOOO */
	while((*l)->nb_suspects != 0)
		retirer_suspect(*l,(*l)->tete);
	free(*l);
	free(l);
}

void ajouter_suspect(struct liste_suspects *liste, struct suspect *suspect) {
/* Correcte => vérifiée avec DDD */
/* RQ : on ne vérifie pas que suspect est déjà présent avant de l'insérer */
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
	else if (liste->nb_suspects == 1)
	{
		liste-> nb_suspects += 1;
		(liste->tete)->suiv = suspect;
		liste->queue = suspect;
		(liste->queue)->prec = liste->tete;
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
	/* Verifiée avec DDD */
	/* ----------------- */
	/* si suspect == NULL alors on n'a pas de suspect à retirer */
	if (suspect == NULL)
		return;
	/* si la liste est vide, l'élément est déjà retiré */
	if (liste->nb_suspects == 0)
		return;
	/* s'il y a 1 unique élement, soit c'est le bon et on le retire, soit c'est pas le bon et on ne change pas la liste */
	else if (liste->nb_suspects == 1)
	{
		if (liste->tete != suspect)
			return;
		else
		{
			liste->tete = NULL;
			liste->queue = NULL;
			free(suspect);
			liste->nb_suspects = 0;
		}
	}
	/* Lorsque le suspect est en-tete : */
	/* s'il y a exactement 2 elements il faut supprimer la tete, la remplacer par la queue, */
        /* mettre la queue à vide, mettre à jour les pointeurs et libérer la mémoire */
	/* s'il y a plus de deux élements, c'est plus simple car il suffit de remplacer la tete par ce qui suit */
	/* (ie la queue ne sera pas modifiée !) et de rediriger les pointeurs. */
	else if ((liste->nb_suspects > 1) && ((liste->tete) == suspect))
	{
		if ((liste->nb_suspects) == 2)
		{
			liste->tete = (liste->queue);
			liste->tete->suiv = NULL;
			liste->tete->prec = NULL;
			liste->queue->suiv = NULL;
			liste->queue->prec = NULL;
			free(suspect);
			liste->nb_suspects -= 1;
		}
		else
		{
			struct suspect *temp = liste->tete->suiv;
			suspect->suiv = NULL;
			suspect->prec = NULL;
			liste->tete = temp;
			liste->tete->prec = NULL;
			free(suspect);
			liste->nb_suspects -= 1;
	
		}

	}
	/* Ailleurs : */
        /* le suspect est (peut-etre) dans la liste qui contient au moins 2 elements */
	/* on le supprime s'il est présent, sinon on ne fait rien */
	else
	{
		/* soit il est en queue */
		if ((liste->queue) == suspect)
		{
			liste->queue = liste->queue->prec;
			(liste->queue)->suiv = NULL;
			suspect->prec = NULL;
			suspect->suiv = NULL;
			liste->nb_suspects -= 1;
			free(suspect);
			
		}
		/* soit il est (eventuellement) entre la tete et la queue */
		/* on le cherche : si on le trouve on le supprime, sinon rien */
		else
		{
			struct suspect *temp = (liste->tete)->suiv;
			while (temp != NULL)
			{
				if (temp == suspect)
				{
					(suspect->prec)->suiv = suspect->suiv;
					(suspect->suiv)->prec = suspect->prec;
					liste->nb_suspects -= 1;
					free(suspect);
				        return;
				}
				else
				{
					temp = temp->suiv;
				}
			}
		}
     	}
}

void affiche_liste_suspects(struct liste_suspects *l) {
	struct suspect *temp = l->tete;
	printf("Affichage de la liste: \n ");
	while (temp != NULL) {
		printf("NOM = %s", temp->nom);
		printf(" ; ATTRIBUT = %d | ", (temp->attributs));
		temp = temp->suiv;
	}
	printf("\n");
}
