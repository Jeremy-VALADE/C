#include <MLV/MLV_all.h>
#include "objet.h"

static const struct graphiqueSudoku sudoku =  {"Sudoku", 700, 800, 50, 125, 200, 550,  45};

/* Création de la fenêtre */
void create_window() 
{
	MLV_create_window(sudoku.titre, NULL, sudoku.largeur, sudoku.hauteur);
}

/* Remplissage de la grille par la feuille du sudoku */
void remplissage_grille(Board grid) {
	int i, j;

	for ( i = 0 ; i < 9 ; i++) {
		for ( j = 0 ; j < 9 ; j++) {
			char c[50];
			if (grid[i][j] == 0)
				sprintf(c, "%s", "");
			else
				sprintf(c, "%d", grid[i][j]);
			MLV_draw_text(sudoku.abscisseGrille + j*sudoku.longueurCote+20,  sudoku.ordonneeGrille + i*sudoku.longueurCote+20 , c,MLV_rgba(255, 0, 0, 0));
		}
	}
}


/* Remplissage du tableau des propositions par les propositions possibles (1 à 9) */
void affiche_proposition_chiffre() {
	int  i, j;	
	int compteur = 1;

	for ( i = 0 ; i < 3 ; i++) {
		for ( j = 0 ; j < 3 ; j++) {
			char c[50];
			sprintf(c, "%d", compteur);
			MLV_draw_text(sudoku.abscisseProposiion + j*sudoku.longueurCote + 20, sudoku.ordonneeProposition + i*sudoku.longueurCote+20 , c,MLV_rgba(0, 255, 0, 0));
			compteur++;
		}
	}
}

/* Affiche les grilles d'un tableau */
void grille(int x, int y, int nombreCase) {
	int i;
	for (i = 0 ; i <= nombreCase ; i++) {
		/* Colonne */
		MLV_draw_line(x + i*sudoku.longueurCote, y, x + i*sudoku.longueurCote, y + sudoku.longueurCote*nombreCase, MLV_rgba(255, 255, 255, 255));
		/* Ligne */
		MLV_draw_line(x, y + i*sudoku.longueurCote, x + sudoku.longueurCote*nombreCase,  y + i*sudoku.longueurCote, MLV_rgba(255, 255, 255, 255));
	}
}

/* Affiche le sudoku sur la fenêtre */
void creation_sudoku(Board b) {
	grille(sudoku.abscisseGrille, sudoku.ordonneeGrille, 9);
	remplissage_grille(b);
	MLV_actualise_window();
}

/* Affiche le tableau des propositions sur la fenêtre */
void affiche_proposition() {
	/*	affiche_proposition_grille();
	*/
	grille(sudoku.abscisseProposiion, sudoku.ordonneeProposition, 3);
	affiche_proposition_chiffre();
	MLV_actualise_window();
}

void coordonneeSouris(int* x, int* y) {
	MLV_wait_mouse(x, y);
}
/* Détermination de la case sélectionnée */
int verification_souris_1(Board tab, int x, int y, int* a, int* b) {
	int i;
	if ( x < sudoku.abscisseGrille || x > (sudoku.abscisseGrille + 9*sudoku.longueurCote))
		return 0;
	if ( y < sudoku.ordonneeGrille || y > (sudoku.ordonneeGrille + 9*sudoku.longueurCote))
		return 0;

	/* Vérication abscisse */
	i = 0;
	*a = -1;
	while (*a == -1) {
		if ( (sudoku.abscisseGrille + i*sudoku.longueurCote) <= x && x <= (sudoku.abscisseGrille + (i+1)*sudoku.longueurCote)) {
			*a = i;			
		}
		i++;
	}
	/* Vérication ordonnée */
	i = 0;
	*b = -1;
	while (*b == -1) {
		if ( (sudoku.ordonneeGrille + i*sudoku.longueurCote) <= y && y <= (sudoku.ordonneeGrille + (i+1)*sudoku.longueurCote)) {
			*b = i;			
		}
		i++;
	}

	if (tab[*b][*a] != 0)
		return 0;

	return 1;
}

/* Détermination du numéro sélectionné 
 * Par exemple : on met 1 dans la case (0,5)
 * */
int verification_souris_2(int x, int y) {
	int i, j, valeur;
	valeur = 0;

	for ( i = 0 ; i < 3 ; i++) {
		for ( j = 0 ; j < 3 ; j++) {
			if ( ( (sudoku.abscisseProposiion + (j*sudoku.longueurCote)) <= x && x <= (sudoku.abscisseProposiion + (j+1)*50)) && ((sudoku.ordonneeProposition + i*50) <= y && y <= (sudoku.ordonneeProposition + (i+1)*50)) ) {
				return valeur+1;
			}
			valeur++;
		}
	}
	return 0;
}

void clear_window() {
	MLV_clear_window(MLV_rgba(0, 0, 0, 255));
}

void free_window() {
	MLV_free_window();
}

