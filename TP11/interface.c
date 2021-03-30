#include <stdio.h>
#include "objet.h"
void create_window(Taquin* taquin) {
	MLV_create_window("Jeu du Taquin", NULL, taquin->width, taquin->height);
}

MLV_Image* getImage(char* string) {
	return MLV_load_image(string);
}

void coordonneesSouris(int* x, int* y) {
	MLV_wait_mouse(x, y);
}

void free_window(MLV_Image* image) {
	MLV_free_image(image);
	MLV_free_window();
}

void affichage(Taquin* taquin) {
	Plateau* p = taquin->p;
	int i, j;
	int longueurImage = taquin->width/taquin->nbCase;
	int hauteurImage = taquin->height/taquin->nbCase;
	int epaisseurDuTrait = taquin->epaisseurDuTrait;
	for ( i = 0; i < taquin->nbCase; i++) {
		for (j = 0; j < taquin->nbCase; j++) {
			MLV_draw_image((p->bloc)[i][j].image, i*longueurImage + i*epaisseurDuTrait, j*hauteurImage + epaisseurDuTrait*j);
		}
	}
	MLV_actualise_window();
}

void victoire_window(Taquin* taquin, int time) {
	char str[500] = "Congratulations, you win in ";
	char t[500] = "";
	sprintf(t, "%d seconde(s)", time);
	strcat(str, t);
	MLV_draw_text_box(100, taquin->height/2 - 20, 300, 50, str, 1, MLV_COLOR_BLACK, MLV_COLOR_GREEN, MLV_rgba(0, 0, 0, 0), MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER); 

	MLV_actualise_window();
}


