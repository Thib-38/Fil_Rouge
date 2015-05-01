#ifndef JEU_H
#define JEU_H

#include "suspect.h"
#include "ensemble.h"

/* Genre */
#define HOMME                0b1000000000000000
#define FEMME                0b0100000000000000

/* Pilosité */
#define MOUSTACHE            0b0010000000000000
#define BARBE                0b0001000000000000

/* Coiffure */
#define COIFFURE_CHAUVE      0b0000100000000000
#define COIFFURE_LONG        0b0000010000000000
#define COIFFURE_COURT       0b0000001000000000

/* Couleur cheveux */
#define CHEVEUX_NOIRS        0b0000000100000000
#define CHEVEUX_CHATAINS     0b0000000010000000
#define CHEVEUX_BLANCS       0b0000000001000000
#define CHEVEUX_ROUX         0b0000000000100000
#define CHEVEUX_BLONDS       0b0000000000010000

/* Accessoires */
#define LUNETTES             0b0000000000001000
#define CHAPEAU              0b0000000000000100

#endif /* JEU_H */
