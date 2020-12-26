#include <stdio.h>

/* Fonction qui affiche un tableau */
void print_tableau(int tab[], int taille) {
	int i;
	printf("[");
	for (i = 0; i < taille ; i++) {
		printf("%d", tab[i]);
	        if (!((i+1) == taille))
			printf(", ");	       
	}
	printf("]\n");
}

/* Calcule puis retourne la moyenne d'un tableau */
int moyenne(int tab[], int taille) {
	int i;
	int somme = 0;
	for (i = 0; i < taille; i++) {
		somme += tab[i];
	}

	return somme/taille;
}

/* Trouve et retourne le minimum d'un tableau */
int min(int tab[], int taille) {
	int i;
	int min = tab[0];
	for (i = 1; i < taille; i++) {
		if (tab[i] < min)
			min = tab[i];
	}

	return min;
}


/* Trouve et retourne le maximum d'un tableau */
int max(int tab[], int taille) {
	int i;
	int max = tab[0];
	for (i = 1; i < taille; i++) {
		if (tab[i] > max)
			max = tab[i];
	}

	return max;
}
