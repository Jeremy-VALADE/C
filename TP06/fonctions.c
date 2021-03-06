#include <stdio.h>
#include "sudoku.h"

#define N 9

int fread_board(const char* file, Board board){
	FILE* f;
	int i,j;
	int entry;

	f = fopen(file, "r");
	if (f == NULL){
		fprintf(stderr, "Erreur d'ouverture du fichier %s\n", file);
		return 0;
	}

	for (i=0 ; i<N; i++){
		for (j=0 ; j<N ; j++){
			fscanf(f, "%d", &entry);
			board[i][j] = entry;
		}
	}
	return 1;
}

/* Affiche une grille de sudoku */
void print_board(Board b) {
	int i, j;
	for (i = 0; i < N; i++) {
		printf("\n");
		for (j=0 ; j<N ; j++) {
			printf("%d  ", b[i][j]);
		}
	}
	printf("\n");
}

/* Cette fonction permet de dire s'il est possible de mettre 
 * ce chiffre dans la case sélectionnée */
int possible(Board b, int current, int num_ligne, int num_colonne) {
	int k, l, i, j;
	int ligne_depart = num_ligne - num_ligne % 3; 
	int colonne_depart = num_colonne - num_colonne % 3;
	
	/*Vérification des lignes */ 
	for (k = 0; k < N; k++) {
		if (current == b[num_ligne][k]) {
			return 0;
		}
	}	

	/*Vérification des colonnes*/
	for (l = 0 ; l < N ; l++) {
		if (current == b[l][num_colonne]) {
			return 0;
		}
	}

	/* Vérification du nombre dans un des 9 tableaux de la grille du sudoku */
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (b[i + ligne_depart][j +  colonne_depart] == current)
				return 0;
		}
	}
	return 1;
}

/* Fonction qui résout un sudoku à une solution */
int solveSudoku(Board b, int row, int col) {
	int num;
	if (row == (N-1) && col == N) {
		printf("Solution de la grille\n");
		print_board(b);
		return 1;
	}

	if (col == N) {
		row++;
		col = 0;
	}

	if (b[row][col] > 0) { 
		return solveSudoku(b, row, col + 1);
	}

	int compteur = 0;
	int nombre = 0;
	for (num = 1; num <= N; num++) {
		if (possible(b, num, row, col)) {
			b[row][col] = num;
			nombre = solveSudoku(b, row, col+1);
			compteur += nombre;
			if (compteur > 0)
				return compteur;

		}
		b[row][col]  = 0;
		compteur -= nombre;
	}
	return 0;
}


