#include <stdio.h>
#include "ensemble.h"
#define un 0b0000000000000001

ensemble_t ensemble_vide(void) {
        return 0b0000000000000000;
}

ensemble_t ensemble_plein(void) {
        return 0b1111111111111111;
}

uint16_t ensemble_cardinal(ensemble_t e) {
	ensemble_t e_temp = e;
	uint16_t res = 0;
	uint16_t i=0;
	for (i=0; i<16; i++)
	{
		res = res + ( e_temp & un);
		e_temp = e_temp >> 1;
	}
	return res;
}

bool ensemble_appartient(ensemble_t e, uint16_t numero_elt) {
        if (((e >> numero_elt) & un) == un)
		return true;
	return false;
}

ensemble_t ensemble_union(ensemble_t e1, ensemble_t e2) {
        return (e1 | e2);
}

ensemble_t ensemble_intersection(ensemble_t e1, ensemble_t e2) {
        return (e1 & e2);
}

ensemble_t ensemble_complementaire(ensemble_t e) {
        return ~e;
}

void ensemble_ajouter_elt(ensemble_t *e, uint16_t numero_elt) {
	*e = *e | (un<<numero_elt);
}

void ensemble_retirer_elt(ensemble_t *e, uint16_t numero_elt) {
	*e = *e & ~(un<<numero_elt);
}

void ensemble_afficher(const char *msg, ensemble_t e) {
	char chaine[17];
	uint16_t i = 0;
	uint16_t puissance_de_deux = 32768; /* 32768 = 2puissance15 */
	uint16_t res_dec = 0;
	for (i=0;i<16;i++)
	{
		if (ensemble_appartient(e,15-i) == true)
		{
			res_dec = res_dec + puissance_de_deux;
			chaine[i]='1';
		}
		else
		{
			chaine[i]='0';	
		}
		puissance_de_deux = puissance_de_deux/2;
		
	}
	chaine[16]='\0';
	printf("%s             Binaire : %s | Decimal : %d        ",msg,chaine,res_dec);
}
