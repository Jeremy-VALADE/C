#include <stdio.h>
#include "sudoku.h"
#include "fonctions.h"

/* Programme */
int main(int argc, char* argv[]) {
	Board b;
	if (!fread_board(argv[1], b)) {
		printf("Erreur : l'argument doit être sudoku/data/grid*.txt\n");
		return 0;
	}
	printf("%d\n", solveSudoku(b, 0, 0));

	return 0;
}
