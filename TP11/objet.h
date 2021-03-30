#include <MLV/MLV_all.h>

#define NB_LIGNE 16
#define NB_COLONNE 16


#ifndef __Taquin__
#define __Taquin__

typedef struct carre {
	int ligne;
	int colonne;
	MLV_Image* image;

} Carre;

typedef struct plateau {
	int ligneCaseNoire;
	int colonneCaseNoire;
	Carre bloc[NB_LIGNE][NB_COLONNE];
} Plateau;

typedef struct Taquin {
	int width;
	int height;
	int nbCase;
	int epaisseurDuTrait;
	Plateau* p;
} Taquin;

#endif

Taquin* createTaquin(int width, int height, int nbCase, int epaisseurDuTrait);
void createPlateau(Taquin* taquin, MLV_Image* image);
int verification(Taquin* taquin);
void getCase(Taquin* taquin, int x, int y);
void free_taquin(Taquin* taquin);
