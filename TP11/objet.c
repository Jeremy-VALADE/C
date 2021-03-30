#include "objet.h"

void swap_mem(void* z1, void* z2, size_t size) {
	char* a = (char*) z1;
	char* b = (char*) z2;
	char c;

	int i;
	for (i = 0; i < size; i++) {
		c = a[i];
		a[i] = b[i];
		b[i] = c;
	}
}

void melangePlateau(Taquin* taquin) {
	Plateau* p = taquin->p;
	int a = p->ligneCaseNoire;
	int b = p->colonneCaseNoire;
	int i = 0;
	int n, tmp;

	while (i != 120) {
		n = rand() % 4;
		tmp = i;
		switch (n) {
			/* Déplace la case en Haut */
			case 0:
				if ((b-1) >= 0) {
					b -= 1;
					i++;
				}
				break;
				/* Déplace la case en Bas */
			case 1:
				if ( (b+1) < taquin->nbCase) {
					b += 1;
					i++;
				}
				break;
				/* Déplace la case en gauche */
			case 2:
				if ( (a-1) >= 0)  {
					a -= 1;
					i++;
				}
				break;
				/* Déplace la case à droite */
			case 3:
				if ( (a+1) < taquin->nbCase) {
					a += 1;
					i++;
				}
				break;
		}

		if (tmp != i) {
			swap_mem(&(p->bloc)[p->ligneCaseNoire][p->colonneCaseNoire], &(p->bloc)[a][b], sizeof(Carre));
			p->ligneCaseNoire = a;
			p->colonneCaseNoire = b;
		}
	}
}

Plateau* initialisation(Taquin* taquin, MLV_Image* image) {
	int i, j;
	int longueurImage = taquin->width/taquin->nbCase;
	int hauteurImage = taquin->height/taquin->nbCase;
	Plateau* p = (Plateau*)malloc(sizeof(Plateau));
	p->ligneCaseNoire = taquin->nbCase - 1;
	p->colonneCaseNoire = taquin->nbCase - 1;
	for (i = 0; i < taquin->nbCase; i++) {
		for (j = 0; j < taquin->nbCase; j++) {
			(p->bloc)[i][j].ligne = i;
			(p->bloc)[i][j].colonne = j;
			if ( i == (taquin->nbCase-1) && j == (taquin->nbCase-1))
				(p->bloc[i][j]).image = MLV_create_image(longueurImage, hauteurImage);
			else
				(p->bloc)[i][j].image = MLV_copy_partial_image(image, i*longueurImage, j*hauteurImage, longueurImage, hauteurImage);
		}
	}
	return p;
}


Taquin* createTaquin(int width, int height, int nbCase, int epaisseurDuTrait) {
	Taquin* taquin = (Taquin*)malloc(sizeof(Taquin));
	taquin->width = width;
	taquin->height = height;
	taquin->nbCase = nbCase;
	taquin->epaisseurDuTrait = epaisseurDuTrait;
	taquin->p = NULL;
	return taquin;
}

void free_taquin(Taquin* taquin) {
	free(taquin);
}

void createPlateau(Taquin* taquin, MLV_Image* image) {
	taquin->p = initialisation(taquin, image);
	melangePlateau(taquin);
}

/* Méthode qui permet de vérifier si le jeu du taquin a été résolu */
int verification(Taquin* taquin) {
	Plateau* p = taquin->p;
	int i, j;
	for (i = 0; i < taquin->nbCase; i++) {
		for (j = 0; j < taquin->nbCase; j++) {
			if (i != (p->bloc)[i][j].ligne) 
				return 0;

			if (j != (p->bloc)[i][j].colonne) 
				return 0;
		}
	}
	return 1;
}



void modificationPlateau(Plateau* p, int ligne, int colonne) {
	/* Modification horizontale */
	if ( (ligne+1) == p->ligneCaseNoire || (ligne-1) == p->ligneCaseNoire) {
		if (colonne == p->colonneCaseNoire) {
			swap_mem(&(p->bloc)[p->ligneCaseNoire][p->colonneCaseNoire], &(p->bloc)[ligne][colonne], sizeof(Carre));
			p->ligneCaseNoire = ligne;
		}
	}

	/* Modification Verticale */
	else if ((colonne+1) == p->colonneCaseNoire || (colonne-1) == p->colonneCaseNoire) {
		if (ligne == p->ligneCaseNoire) {
			swap_mem(&(p->bloc)[p->ligneCaseNoire][p->colonneCaseNoire], &(p->bloc)[ligne][colonne], sizeof(Carre));
			p->colonneCaseNoire = colonne;
		}
	}
}

void getCase(Taquin* taquin, int x, int y) {
	int i, a, b;
	int longueurImage = taquin->width/taquin->nbCase;
	int hauteurImage = taquin->height/taquin->nbCase;
	a = -1;
	i = 0;
	while (a == -1 && (i*longueurImage <= taquin->width)) {
		if ((i * longueurImage + i*taquin->epaisseurDuTrait) <= x && x <= ((i+1)*longueurImage +i*taquin->epaisseurDuTrait))
			a = i;
		i++;
	}

	b = -1;
	i = 0;
	while (b == -1 && (i*hauteurImage <= taquin->height)) {
		if ((i * hauteurImage + i*taquin->epaisseurDuTrait) <= y && y <= ((i+1)*hauteurImage +i*taquin->epaisseurDuTrait))
			b = i;
		i++;
	}

	if ((a != -1) || (b != -1)) {
		modificationPlateau(taquin->p, a, b);
	}
}

