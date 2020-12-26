#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];

void initialize_empty_board(Board grid);
void print_board(Board grid);



struct graphiqueSudoku {
	char titre[40];
	int hauteur;
	int largeur;
	int longueurCote;

	int abscisseGrille;
	int ordonneeGrille;
	int abscisseProposiion;
	int ordonneeProposition;
};


#endif
