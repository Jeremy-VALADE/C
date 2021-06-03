#include<stdio.h>

#define N 3

/* Fonction qui affiche les éléments d'un tableau */
void affiche_tableau(int* array) {
	int i;
	for (i = 0 ; i < N ; i++) {
		if ( (i+1) == N)
			printf("%d ", array[i]);
		else
			printf("%d - ", array[i]);
	}
	printf("\n");
}

/*Algo de permutation */
void permutations(int buffer[], int current, int max) {
	if (current > max) {
		affiche_tableau(buffer);
	}
	else {
		int i;
		for (i = 0 ; i < max ; i++) {
			if (buffer[i] == 0) {
				buffer[i] = current;
				permutations(buffer, current+1, max);
				buffer[i] = 0;
			}	
		}
	}
}

/* Exécution du programme */
int main() {
	int tab[3] = {0,0,0};
	permutations(tab, 1, N);

	return 0;
}
