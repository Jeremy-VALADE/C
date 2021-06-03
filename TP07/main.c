#include <stdio.h>

#include "objet.h"
#include "interface.h"
#include "operation.h"

int main() {
	/* Grille sudoku */
	Board solution;
	Board probleme;

	/* Coordonnées de la souris */ 
	int x, y;

	/* Case du tableau */ 
	int a, b; 
	/* Variable contenant le chiffre saisi par l'utilisateur */
	int valeur;

	/*Grille joueur */
	fread_board("Grille/grid1.txt", probleme);
	/*Grille solution */
	fread_board("Grille/grid1.txt", solution);
	solveSudoku(solution, 0, 0);

	/* Création de la fenêtre */
	create_window();

	do {
		creation_sudoku(probleme);
		coordonneeSouris(&x, &y);
		if (verification_souris_1(probleme, x, y, &a, &b)) {
			affiche_proposition();
			coordonneeSouris(&x, &y);

			if ((valeur = verification_souris_2(x, y)) != 0) {
				probleme[b][a] = valeur;
			}
			/* On enlève le tableau des propositions */ 
			clear_window();
		}
	} while (!are_array_equals(probleme, solution));

	free_window();

	return 0;
}
