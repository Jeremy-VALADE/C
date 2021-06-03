#include <stdio.h>
#include <stdlib.h>

char* alphabet = "abcdefghijklmnopqrstuvwxyz";
int index = 0;

char** allocationTab(int num_ligne, int num_colonne) {	
	char** tab = (char**)malloc(num_ligne * sizeof(char*));
	int i;	
	if (tab == NULL) {
		fprintf(stderr, "Tableau générale -> Pas assez de mémoire\n");
		exit(1);
	}
	for (i = 0; i < num_ligne; i++) {
		tab[i] = (char*)malloc(num_colonne * sizeof(char));
		if (tab[i] == NULL) {
			fprintf(stderr, "Sous-tableau : %d -> Pas assez de mémoire\n", i);
			exit(1);
		}
	}
	return tab;
}

void fillTab(char** tab, int num_ligne, int num_colonne) {
	int i, j;
	for (i = 0; i < num_ligne; i++) {
		index = i;
		for (j = 0; j < num_colonne; j++) {
			if ( index > 25)
				index = 0;
			tab[i][j] = alphabet[index];
			index++;
		}
	}
}

void printTab(char** tab, int num_ligne, int num_colonne) {
	int i, j;
	for (i = 0; i < num_ligne; i++) {
		for (j = 0; j < num_colonne; j++) {
			printf("%c ", tab[i][j]);
		}
		printf("\n");
	}
}

void freeTab(char** tab, int num_ligne) {
	int i;
	for (i = 0; i < num_ligne; i++) {
		free(tab[i]);
	}
	free(tab);
}

int main() {
	int num_ligne = 0;
	int num_colonne = 0;
	/* Case du tableau */
	char** tab;
	printf("Donner deux dimensions entières ($1 $2) : ");
	scanf("%d %d", &num_ligne, &num_colonne);
	printf("Num ligne : %d\n", num_ligne);
	printf("Num colonne : %d\n", num_colonne);

	tab = allocationTab(num_ligne, num_colonne); 
	fillTab(tab, num_ligne, num_colonne);
	printTab(tab, num_ligne, num_colonne);
	freeTab(tab, num_ligne);

	return 0;
}
