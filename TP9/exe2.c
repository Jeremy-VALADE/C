#include <stdio.h>
#include <stdlib.h>

int main() {
	int num_ligne = 0;
	int num_colonne = 0;
	/* Case du tableau */
	int i, j;
	char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	int index = 0;
	int** tab;
	printf("Donner deux dimensions entières : ");
	scanf("%d %d", &num_ligne, &num_colonne);
	printf("Num ligne : %d\n", num_ligne);
	printf("Num colonne : %d\n", num_colonne);


	tab = (int**)malloc(num_ligne * sizeof(int*));
	if (tab == NULL) {
		fprintf(stderr, "Tableau générale -> Pas assez de mémoire\n");
		exit(1);
	}

	for (i = 0; i < num_ligne; i++) {
		tab[i] = (int*)malloc(num_colonne * sizeof(int));
		if (tab[i] == NULL) {
			fprintf(stderr, "Sous-tableau : %d -> Pas assez de mémoire\n", i);
			exit(1);
		}
	}


	for (i = 0; i < num_ligne; i++) {
		index = i;
		for (j = 0; j < num_colonne; j++) {
			if ( index > 25)
				index = 0;

			/*printf("[%d][%d] = %c\n", i, j, alphabet[index]);*/
			tab[i][j] = alphabet[index];
			index++;
		}
	}

	for (i = 0; i < num_ligne; i++) {
		for (j = 0; j < num_colonne; j++) {
			printf("%c ", tab[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < num_ligne; i++) {
		free(tab[i]);
	}
	free(tab);

	return 0;
}
