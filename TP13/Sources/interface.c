#include <MLV/MLV_all.h>
#include "../Headers/dame.h"

/* Propriétées de la fenêtre */
#define WIDTH 800
#define HEIGHT 500
#define TITLE "Game 8 Queen"
#define LENGTH_CHESS_BOARD 400
#define LENGTH_CASE 50
#define FILE_MUSIC_PATH "Son/error.ogg"
#define FILE_QUEEN_PATH "Images/queen.png"
#define VICTORY_MESSAGE "Congratulations, you win"
#define DEFEAT_MESSAGE "Dommage, toutes les cases sont attaquées.\n Vous n'avez pas réussi à placer les 8 dames."

/* Propriétés du bouton annuler */
#define X_CANCEL_BUTTON 500
#define Y_CANCEL_BUTTON 50
#define WIDTH_CANCEL_BUTTON 150
#define HEIGHT_CANCEL_BUTTON 50

/* Propriétés de l'emplcament du message de victoire ou défaite */
#define X_END_MESSAGE 450
#define Y_END_MESSAGE 250
#define WIDTH_END_MESSAGE 300
#define HEIGHT_END_MESSAGE 100

/* Image d'une dame */
MLV_Image* image = NULL;
/* Fichier son d'une erreur */
MLV_Music* error = NULL;

/* Fonction qui initialise la fenêtre, l'image le son du jeu */
void create_window() {
	MLV_create_window(TITLE, NULL, WIDTH, HEIGHT);
	MLV_init_audio();
	image = MLV_load_image(FILE_QUEEN_PATH);
	error =	MLV_load_music(FILE_MUSIC_PATH);
}

/* Fonction qui dessine le plateau de jeu */
void drawPlateau() {
	int tab = 63;
	int i, j, k;
	char c[50];

	/* Dessine le jeu d'échecs avec les dames dessus */
	MLV_draw_filled_rectangle(0, 0, WIDTH, HEIGHT, MLV_COLOR_BEIGE);
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (j%2 == i%2) {
				MLV_draw_filled_rectangle(j*LENGTH_CASE, i*LENGTH_CASE, LENGTH_CASE, LENGTH_CASE, MLV_COLOR_GREY);
			} else
			MLV_draw_filled_rectangle(j*LENGTH_CASE, i*LENGTH_CASE, LENGTH_CASE, LENGTH_CASE, MLV_COLOR_WHITE);
			if (caseIsDame(tab)) {
				MLV_draw_image(image, j*LENGTH_CASE, i*LENGTH_CASE);
			}
			tab--;	
		}
	}

	/* Dessine les lignes à l'extèrieur de l'échiquier */
	MLV_draw_line(0, LENGTH_CHESS_BOARD, LENGTH_CHESS_BOARD, LENGTH_CHESS_BOARD, MLV_COLOR_RED);
	MLV_draw_line(LENGTH_CHESS_BOARD, 0, LENGTH_CHESS_BOARD, LENGTH_CHESS_BOARD, MLV_COLOR_RED);

	/* Dessine les autres lignes à l'extèrieur de l'échiquier*/
	MLV_draw_line(0, LENGTH_CHESS_BOARD + 35, LENGTH_CHESS_BOARD + 35, LENGTH_CHESS_BOARD + 35, MLV_COLOR_RED);
	MLV_draw_line(LENGTH_CHESS_BOARD + 35, 0, LENGTH_CHESS_BOARD + 35 , LENGTH_CHESS_BOARD + 35, MLV_COLOR_RED);


	/* Écrit les chiffres des cases entre les lignes dessiner précédemment */
	for (k = 0; k < 8; k++) {
		sprintf(c, "%d", 7-k);
		MLV_draw_text(k*LENGTH_CASE + LENGTH_CASE/2 - 5, i*LENGTH_CASE + 10, c, MLV_COLOR_GREY);
		MLV_draw_text(i*LENGTH_CASE + 10, k*LENGTH_CASE + LENGTH_CASE/2 - 5, c, MLV_COLOR_GREY);
	}

	MLV_actualise_window();
}

/* Fonction qui récupère les coordonnées de la souris */
void getSouris(int* x, int* y) {
	MLV_wait_mouse(x, y);
}

/* Fonction qui affice l'écran de fin */
void screenEnd(char* message) {
	MLV_draw_text_box(X_END_MESSAGE, Y_END_MESSAGE , WIDTH_END_MESSAGE, HEIGHT_END_MESSAGE, message, 1, MLV_COLOR_BLACK, MLV_COLOR_GREEN, MLV_rgba(0, 0, 0, 0), MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER); 
	MLV_actualise_window();
}

/* Fonction qui affiche le jeu. Il détermine aussi si vous avez gagné ou perdu */ 
int game_finish() {
	drawPlateau();
	if (sizeDames() == 8) {
		screenEnd(VICTORY_MESSAGE);
		return 1;
	}

	if (allCaseFill()) {
		screenEnd(DEFEAT_MESSAGE);
		return 1;
	}
	
	if (sizeDames() != 0) 
		MLV_draw_text_box(X_CANCEL_BUTTON, Y_CANCEL_BUTTON , WIDTH_CANCEL_BUTTON, HEIGHT_CANCEL_BUTTON, "Annuler un coup", 1, MLV_COLOR_BLACK, MLV_COLOR_GREEN, MLV_rgba(0, 0, 0, 0), MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER); 
	
	MLV_actualise_window();
	return 0;
}

/* Fonction qui permet de trouver le numéro de la case dans le tableau
 *  * */
void find(int a, int b) {
	int numCase = 63;
	int tmp = numCase;
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (i == b && j == a) 
				tmp = numCase;
			numCase--;
		}

	}

	if (!caseIsDame(tmp) && !caseIsTake(tmp)) {
		insert_dame(tmp, 7-a, 7-b);
	}
	else { 
		MLV_play_music(error, 0.5, 1);
	}
}


/* Fonction qui détermine les coordonées de la case sélectionnée.
 * Transmet à la fonction find(x, y) la ligne et la colonne correspondant à cette case.
 * */
void findCase(int x, int y) {
	/* Si la personne appuie sur le boutn de cancel, alors on supprime la dame précédente */
	if (X_CANCEL_BUTTON < x && x < (X_CANCEL_BUTTON + WIDTH_CANCEL_BUTTON) && Y_CANCEL_BUTTON < y && y < (Y_CANCEL_BUTTON + HEIGHT_CANCEL_BUTTON)) {
		deleteDame();
	}
	else {
		int a = -1;
		int b = -1;
		int i = 0;

		while (a == -1 && (i+1)*LENGTH_CASE <= LENGTH_CHESS_BOARD ) {
			if( (x >= i*LENGTH_CASE) && ( x <= (i+1)*LENGTH_CASE))
				a = i;
			i++;
		}

		i = 0;
		while (b == -1 && (i+1)*LENGTH_CASE <= LENGTH_CHESS_BOARD ) {
			if( (y >= i*LENGTH_CASE) && ( y <= (i+1)*LENGTH_CASE))
				b = i;
			i++;
		}

		if (a != -1 && b != -1) 
			find(a, b);
	}
}

/* Fonction qui libère les ressources de la libMLV */ 
void free_window() {
	MLV_free_image(image);
	MLV_free_music(error);
	MLV_free_audio();
	MLV_free_window();
}
