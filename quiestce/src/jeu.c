#include "jeu.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct liste_suspects *initialisation(void) {
/* OK */
        struct liste_suspects *liste = creer_liste_suspects();
	ensemble_t attributs;
        attributs = HOMME | COIFFURE_CHAUVE | CHEVEUX_BLANCS | LUNETTES;
	ajouter_suspect(liste, 	creer_suspect("André", attributs));
        attributs = FEMME | COIFFURE_LONG | CHEVEUX_BLANCS;
	ajouter_suspect(liste, 	creer_suspect("Patricia", attributs));
	attributs = HOMME | COIFFURE_CHAUVE | CHEVEUX_NOIRS | LUNETTES;
	ajouter_suspect(liste, 	creer_suspect("Cédric", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_BLONDS | LUNETTES;
	ajouter_suspect(liste, 	creer_suspect("Philippe", attributs));
	attributs = HOMME | COIFFURE_CHAUVE | CHEVEUX_CHATAINS | MOUSTACHE | BARBE;
	ajouter_suspect(liste, 	creer_suspect("Baptiste", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_CHATAINS;
	ajouter_suspect(liste, 	creer_suspect("Pierre", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_BLANCS | LUNETTES;
	ajouter_suspect(liste, 	creer_suspect("Jean-Louis", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_ROUX;
	ajouter_suspect(liste, 	creer_suspect("Sébastien", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_BLANCS;
	ajouter_suspect(liste, 	creer_suspect("Martin", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_BLANCS | CHAPEAU;
	ajouter_suspect(liste, 	creer_suspect("François", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_CHATAINS | MOUSTACHE;
	ajouter_suspect(liste, 	creer_suspect("Olivier", attributs));
	attributs = FEMME | COIFFURE_LONG | CHEVEUX_CHATAINS | CHAPEAU;
	ajouter_suspect(liste, 	creer_suspect("Elodie", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_NOIRS | BARBE;
	ajouter_suspect(liste, 	creer_suspect("Robert", attributs));
	attributs = HOMME | COIFFURE_CHAUVE | CHEVEUX_ROUX;
	ajouter_suspect(liste, 	creer_suspect("Nicolas", attributs));
	attributs = HOMME | COIFFURE_CHAUVE | CHEVEUX_ROUX | BARBE;
	ajouter_suspect(liste, 	creer_suspect("Victor", attributs));
	attributs = FEMME | COIFFURE_COURT | CHEVEUX_ROUX | CHAPEAU | LUNETTES;
	ajouter_suspect(liste, 	creer_suspect("Carole", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_BLONDS | BARBE;
	ajouter_suspect(liste, 	creer_suspect("Luc", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_BLONDS | CHAPEAU;
	ajouter_suspect(liste, 	creer_suspect("Georges", attributs));
	attributs = FEMME | COIFFURE_LONG | CHEVEUX_BLONDS;
	ajouter_suspect(liste, 	creer_suspect("Mélanie", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_CHATAINS | CHAPEAU;
	ajouter_suspect(liste, 	creer_suspect("Simon", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_BLONDS | MOUSTACHE;
	ajouter_suspect(liste, 	creer_suspect("Thierry", attributs));
	attributs = HOMME | COIFFURE_LONG | CHEVEUX_ROUX | MOUSTACHE;
	ajouter_suspect(liste, 	creer_suspect("Fabien", attributs));
	attributs = HOMME | COIFFURE_COURT | CHEVEUX_NOIRS | MOUSTACHE;
	ajouter_suspect(liste, 	creer_suspect("Maxime", attributs));
	attributs = FEMME | COIFFURE_COURT | CHEVEUX_NOIRS;
	ajouter_suspect(liste, 	creer_suspect("Céline", attributs));
	return liste;
}

ensemble_t demander_qui_il_faut_trouver(void) {
/* OK */
	ensemble_t a_trouver;
	long m;
	char *c;
	char ligne_lue[256];
	printf("\nListe des personnes en jeu :\n\n");
	printf("1 -> André\n");
	printf("2 -> Patricia\n");
	printf("3 -> Cédric\n");
	printf("4 -> Philippe\n");
	printf("5 -> Baptiste\n");
	printf("6 -> Pierre\n");
	printf("7 -> Jean-Louis\n");
	printf("8 -> Sébastien\n");
	printf("9 -> Martin\n");
	printf("10 -> François\n");
	printf("11 -> Olivier\n");
	printf("12 -> Elodie\n");
	printf("13 -> Robert\n");
	printf("14 -> Nicolas\n");
	printf("15 -> Victor\n");
	printf("16 -> Carole\n");
	printf("17 -> Luc\n");
	printf("18 -> Georges\n");
	printf("19 -> Mélanie\n");
	printf("20 -> Simon\n");
	printf("21 -> Thierry\n");
	printf("22 -> Fabien\n");
	printf("23 -> Maxime\n");
	printf("24 -> Céline\n");
saisie: printf("\nChoisissez le numéro de la personne que l'IA doit retrouver.\n");
	if(fgets(ligne_lue, sizeof ligne_lue, stdin) != NULL)
	{
		m = strtol(ligne_lue, &c, 10);
		if (m > 24 || m < 1)
			goto saisie;
	}
	if (m == 1)
		a_trouver = HOMME | COIFFURE_CHAUVE | CHEVEUX_BLANCS | LUNETTES;
	else if (m == 2)
		a_trouver = FEMME | COIFFURE_LONG | CHEVEUX_BLANCS;
	else if (m == 3)
		a_trouver = HOMME | COIFFURE_CHAUVE | CHEVEUX_NOIRS | LUNETTES;
	else if (m == 4)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_BLONDS | LUNETTES;
	else if (m == 5)
		a_trouver = HOMME | COIFFURE_CHAUVE | CHEVEUX_CHATAINS | MOUSTACHE | BARBE;
	else if (m == 6)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_CHATAINS;
	else if (m == 7)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_BLANCS | LUNETTES;
	else if (m == 8)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_ROUX;
	else if (m == 9)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_BLANCS;
	else if (m == 10)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_BLANCS | CHAPEAU;
	else if (m == 11)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_CHATAINS | MOUSTACHE;
	else if (m == 12)
		a_trouver = FEMME | COIFFURE_LONG | CHEVEUX_CHATAINS | CHAPEAU;
	else if (m == 13)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_NOIRS;
	else if (m == 14)
		a_trouver = HOMME | COIFFURE_CHAUVE | CHEVEUX_ROUX;
	else if (m == 15)
		a_trouver = HOMME | COIFFURE_CHAUVE | CHEVEUX_ROUX | BARBE;
	else if (m == 16)
		a_trouver = FEMME | COIFFURE_COURT | CHEVEUX_ROUX | CHAPEAU | LUNETTES;
	else if (m == 17)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_BLONDS | BARBE;
	else if (m == 18)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_BLONDS | CHAPEAU;
	else if (m == 19)
		a_trouver = FEMME | COIFFURE_LONG | CHEVEUX_BLONDS;
	else if (m == 20)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_CHATAINS | CHAPEAU;
	else if (m == 21)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_BLONDS | MOUSTACHE;
	else if (m == 22)
		a_trouver = HOMME | COIFFURE_LONG | CHEVEUX_ROUX | MOUSTACHE;
	else if (m == 23)
		a_trouver = HOMME | COIFFURE_COURT | CHEVEUX_NOIRS | MOUSTACHE;
	else
		a_trouver = FEMME | COIFFURE_COURT | CHEVEUX_NOIRS;
	return a_trouver; 
}


bool la_question(uint16_t n)
{
	char ligne_lue[256];
	printf("\n\nVeuillez répondre à la question suivante par [o]ui / [n]on : \n\n");
	if (n == 0)
		printf("Est-ce un homme ?\n");
	if (n == 1)
		printf("Est-ce une femme ?\n");
	if (n == 2)
		printf("Est-ce que cette personne a de la moustache ?");
	if (n == 3)
		printf("Est-ce que cette personne a une barbe ?\n");
	if (n == 4)
		printf("Cette personne est-elle chauve ?\n");
	if (n == 5)
		printf("Cette personne a-t-elle les cheveux longs ?\n");
	if (n == 6)
		printf("Cette personne a-t-elle les cheveux courts ?\n");
	if (n == 7)
		printf("Cette personne a-t-elle les cheveux noirs ?\n");
	if (n == 8)
		printf("Cette personne a-t-elle les cheveux chatains ?\n");
	if (n == 9)
		printf("Cette personne a-t-elle les cheveux blancs ?\n");
	if (n == 10)
		printf("Cette personne a-t-elle les cheveux roux ?\n");
	if (n == 11)
		printf("Cette personne a-t-elle les cheveux blonds ?\n");
	if (n == 12)
		printf("Cette personne porte-t-elle des lunettes ?\n");
	if (n == 13)
		printf("Cette personne porte-t-elle un chapeau ?\n");
lire_reponse:
	if(fgets(ligne_lue, sizeof ligne_lue, stdin) != NULL)
	{
	        if (ligne_lue[0] == 'o')
		        return true;
		else if (ligne_lue[0] == 'n')
			return false;
		else
			goto lire_reponse;
	}
}

void questionner_joueur_et_maj(struct liste_suspects *l, ensemble_t q)
{
	uint16_t n = 0;
	uint16_t b = 0;
	struct suspect *temp = (l->tete);
	struct suspect *(temp_2) = temp;
poser_autre_question:
        n = rand() % 14;
	if (!(ensemble_appartient(q,n)))
	{
		ensemble_ajouter_elt((&q),13-n+2);
		b = la_question(n);
		/*printf("%d",b);*/
		if (b == 1)
		{
			while (temp != NULL)
			{
				if ((ensemble_appartient(ensemble_complementaire((temp->attributs)),13-n+2)))
				{
					temp_2 = temp->suiv;
					retirer_suspect(l,temp);
					temp=temp_2;
				}
				else
					temp = (temp->suiv);
			}
		}
		else
		{
			while (temp != NULL)
			{	
				if ((ensemble_appartient((temp->attributs),13-n+2)))
				{
					temp_2 = temp->suiv;
					retirer_suspect(l,temp);
					temp = temp_2;
				}
				else
					temp = (temp->suiv);
			}
		}
		/*printf("\n n=%d \n",n);*/
		ensemble_afficher("Etat actuel de la liste de l'AI", q);
		/* FAIRE DES TEST INTELLIGENTS ie si n=1 alors ajouter n=2, etc ... */ 
		return;
	}
	else
		goto poser_autre_question;
}


int main(void) {
	srand(time(NULL));
	struct liste_suspects *liste = initialisation();
	ensemble_t questions_posees = ensemble_vide();
	ensemble_t cible = demander_qui_il_faut_trouver();
	while ((liste->nb_suspects) > 1)
	{
		affiche_liste_suspects(liste);
		questionner_joueur_et_maj(liste,questions_posees);
	}
	if ((liste->nb_suspects) != 1)
		printf("\n\nVous avez menti\n\n");
	else if ((liste->tete->attributs) != cible)
		printf("\n\nVous avez menti\n\n");
	else
		printf("\n\nLa personne que l'IA a trouvée est : %s\n\n",(liste->tete)->nom);
	detruire_liste_suspects(&liste);
        return 0;
}
