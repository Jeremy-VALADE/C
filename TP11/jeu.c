#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>

#define NB_LIGNE 4
#define NB_COLONNE 4

int ligneCaseNoire = 3;
int colonneCaseNoire = 3;

typedef struct carree {
	int ligne;
	int colonne;
	MLV_Image* image;

} Carre;

typedef struct plateau {
	Carre bloc[NB_LIGNE][NB_COLONNE];
} Plateau;

void initialisation(Plateau* p, MLV_Image* image) {
	int i, j;
	for (i = 0; i < NB_LIGNE; i++) {
		for (j = 0; j < NB_COLONNE; j++) {
			(p->bloc)[i][j].ligne = i;
			(p->bloc)[i][j].colonne = j;
			if ( i == 3 && j == 3)
				(p->bloc[i][j]).image = MLV_create_image(512/4, 512/4);
			else
				(p->bloc)[i][j].image = MLV_copy_partial_image(image, i*512/4 , j*512/4 , 512/4, 512/4);
		}
	}
}

void affichage(Plateau* p) {
	int i, j;
	int ecartLigne = 0;
	int ecartColonne;
	for ( i = 0; i < NB_LIGNE; i++) {
		ecartLigne = 10;
		ecartColonne = 0;
		for (j = 0; j < NB_COLONNE; j++) {
			/*			printf("Plateau[%d][%d] : ligne = %d, colonne = %d\n", i, j, (p->bloc)[i][j].ligne, (p->bloc)[i][j].colonne);*/
			MLV_draw_image((p->bloc)[i][j].image, i*512/4 + i*5, j*512/4+5*j);
		}
	}
	MLV_actualise_window();
}

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

void modificationImage(Plateau* p, int ligne, int colonne) {
	printf("modification Image\n");

	/* Modification horizontale */
	if ( (ligne+1) == ligneCaseNoire || (ligne-1) == ligneCaseNoire) {
		if (colonne == colonneCaseNoire) {
			swap_mem(&(p->bloc)[ligneCaseNoire][colonneCaseNoire], &(p->bloc)[ligne][colonne], sizeof(Carre));
			affichage(p);
			MLV_actualise_window();
			ligneCaseNoire = ligne;
		}
	}

	/* Modification Verticale */
	else if ((colonne+1) == colonneCaseNoire || (colonne-1) == colonneCaseNoire) {
		if (ligne == ligneCaseNoire) {
			swap_mem(&(p->bloc)[ligneCaseNoire][colonneCaseNoire], &(p->bloc)[ligne][colonne], sizeof(Carre));
			affichage(p);
			MLV_actualise_window();
			colonneCaseNoire = colonne;
		}
	}
}



void action_souris(Plateau *p, int x, int y) {
	int i = 0;
	int a = -1;
	while (a == -1 && (i*512/4 <= 512)) {
		printf("%d < a < %d\n", (i * 512/4 + i*5), ((i+1)*512/4 + i*5)); 
		if ((i * 512/4 + i*10) <= x && x <= ((i+1)*512/4 +i*5))
			a = i;
		i++;
	}
	int b = -1;
	i = 0;
	while (b == -1 && (i*512/4 <= 512)) {
		printf("%d < b < %d\n", (i * 512/4 + i*10), (i+1)*512/4 + (i+1)*512/4); 
		if ((i * 512/4 + i*5) <= y && y <= ((i+1)*512/4 + i*5))
			b = i;
		i++;
	}

	if ((a != -1) || (b != -1)) {
		printf("a : %d, b: %d\n", a, b);
		modificationImage(p, a, b);
	}
}
void melange(Plateau *p) {
	int a = 3;
	int b = 3;
	int i = 0;
	int n;
	Carre* tmp = NULL;
	while (i != 120) {
		n = rand() % 4;
		switch (n) {
			/* Déplace la case en Haut */
			case 0: 
				if ((b-1) >= 0) {
					swap_mem(&(p->bloc)[a][b], &(p->bloc)[a][b-1], sizeof(Carre));
					b = (b-1);
					i++;
				}
				break;
				/* Déplace la case en Bas */
			case 1:
				if ( (b+1) < 4) {
					swap_mem(&(p->bloc)[a][b], &(p->bloc)[a][b+1], sizeof(Carre));
					b = b + 1;
					i++;
				}
				break;
				/* Déplace la case en gauche */
			case 2:
				if ( (a-1) >= 0)  {
					swap_mem(&(p->bloc)[a][b], &(p->bloc)[a-1][b], sizeof(Carre));
					a = a - 1;
					i++;
				}
				break;
				/* Déplace la case à droite */
			case 3: 
				if ( (a+1) < 4) {
					swap_mem(&(p->bloc)[a][b], &(p->bloc)[a+1][b], sizeof(Carre));
					a = a + 1;
					i++;
				}
				break;
		}
	}
	ligneCaseNoire = a;
	colonneCaseNoire = b;
}
int verification(Plateau* p) {
	int i, j;
	for (i = 0; i < NB_LIGNE; i++) {
		for (j = 0; j < NB_COLONNE; j++) {
			if (i != (p->bloc)[i][j].ligne) 
				return 0;

			if (j != (p->bloc)[i][j].colonne) 
				return 0;
		}
	}

	return 1;
}




int main() {
	srand( time( NULL ) );
	MLV_create_window("Jeu du Taquin", NULL, 512, 512);
	MLV_Image* image = MLV_load_image("Images/image2.png");
	Plateau* p = (Plateau*)malloc(sizeof(Plateau));
	initialisation(p, image);
	printf("affichage avant le mélange\n");
	melange(p);
	printf("affichage après le mélange\n");
	/*	affichage(p);
	*/	printf("Verification : %d\n", verification(p));
	/*printf("Position :%d, :%d\n", (p->bloc)[0][1].ligne,  (p->bloc)[3][2].colonne);*/    
	/*MLV_Image* m = MLV_copy_partial_image(image, 271/4*2, 186/4*2, 271/4, 186/4);
	*/
	/*	MLV_draw_image((p->bloc)[0][0].image, 50, 50);
	*/affichage(p);
	int x, y;
	while (!verification(p)) {
		MLV_wait_mouse(&x, &y);
		action_souris(p, x, y);
	}
	return 0;
}
