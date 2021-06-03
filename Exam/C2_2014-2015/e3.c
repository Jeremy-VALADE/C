#include <stdlib.h>  
#include <stdio.h>   

typedef struct game {
	int nbColumns;
	int nbLignes;
	int** tab;
} Game;

void print(Game* game) {
	printf("%d\n",game->nbLignes );
		printf("%d\n",game->nbColumns );

	int i, j;
	for (i = 0; i < game->nbLignes; i++) {

		for (j = 0; j < game->nbColumns; j++) {
			printf("%d ", game->tab[i][j]);
		}
		printf("\n");
	}
}
Game* create_game(int nbColumns, int nbLignes) {
	Game* game = (Game*)malloc(sizeof(Game));
	game->nbColumns = nbColumns;
	game->nbLignes = nbLignes;

	game->tab = (int**)malloc(sizeof(int*)*nbLignes);
	int i, j;
	for (i = 0; i < nbLignes; i++) {
		game->tab[i] = (int*) malloc(sizeof(int)*nbColumns);
		for (j = 0; j < nbColumns; j++)
			game->tab[i][j] = 0;
	}
	game->tab[0][0] = -1;
	return game;
}

void coup(Game* game, int x, int y) {
	if (x < 0 || x > game->nbColumns)
		return;
	if (y < 0 || y > game->nbLignes)
		return;

	int i, j;
	for (i = x; i < game->nbLignes; i++) {
		for (j = y; j < game->nbColumns; j++) {
			game->tab[i][j] = 1;
		}
	}
}


int main() {
	Game* toto = create_game(7, 4);
	coup(toto, 2, 4);
	print(toto);
	return 0;
}