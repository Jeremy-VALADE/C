#include <stdio.h>
#include "objet.h"

#define N 9

int fread_board (const char *file, Board board)
{
	FILE *f;
	int i, j;
	int entry;

	f = fopen (file, "r");
	if (f == NULL)
	{
		fprintf (stderr, "Erreur d'ouverture du fichier %s\n", file);
		return 0;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			fscanf (f, "%d", &entry);
			board[i][j] = entry;
		}
	}
	return 1;
}

/* Vérification que deux tableaux sont égaux */
int are_array_equals (Board first, Board second)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (first[i][j] != second[i][j])
				return 0;
		}
	}
	return 1;
}

/* Affiche une grille de sudoku */
void print_board (Board b)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		printf ("\n");
		for (j = 0; j < N; j++)
		{
			printf ("%d  ", b[i][j]);
		}
	}
	printf ("\n");
}

/* Cette fonction permet de dire s'il est possible de mettre 
 * ce chiffre dans la case sélectionnée */
int possible (Board b, int current, int num_ligne, int num_colonne)
{
	int k, l;

	int ligne_initial = num_ligne - num_ligne % 3;
	int colonne_initial = num_colonne - num_colonne % 3;
	int i, j;

	/*Vérification des lignes */
	for (k = 0; k < N; k++)
	{
		if (current == b[num_ligne][k])
		{
			return 0;
		}
	}

	/*Vérification des colonnes */
	for (l = 0; l < N; l++)
	{
		if (current == b[l][num_colonne])
		{
			return 0;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (b[i + ligne_initial][j + colonne_initial] == current)
				return 0;
		}
	}
	return 1;
}

/* Fonction qui résout un sudoku à une solution */
int solveSudoku (Board b, int row, int col)
{
	int num;
	if (row == (N - 1) && col == N)
	{
		return 1;
	}

	if (col == N)
	{
		row++;
		col = 0;
	}

	if (b[row][col] > 0)
	{
		return solveSudoku (b, row, col + 1);
	}

	for (num = 1; num <= N; num++)
	{
		if (possible (b, num, row, col))
		{
			b[row][col] = num;

			if (solveSudoku (b, row, col + 1))
				return 1;

		}
		b[row][col] = 0;
	}
	return 0;
}
