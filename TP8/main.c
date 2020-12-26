/* Challenge Syracuse */
#include <stdio.h>

#define N 200000000

/* Tableau contenant la longueur des vols de chaque nombre */
unsigned long int tab[N];
/* Variable content la longueur de vols maximum */
int max = 0;

/* Fonction syracuse */
unsigned long int syracuse(unsigned long int n) {
	unsigned long int compteur = 1;
	if (n == 1) {
		return 0;
	}

	/* Si la longueur du vol de ce nombre existe déjà, on retourne sa valeur */
	if ((n-1) < N && tab[n-1] != 0) {
		return tab[n-1];
	}
	
	/* Application de la suite de syracuse */
	if ( n%2 == 0) {
		compteur =  1 + syracuse(n/2);
	}
	else {
		compteur =  1 + syracuse(3*n+1);
	}

	/* Si l'index (n-1) est présent dans le tableau, on met la longueur du vol dans ce dernier sinon on ne la met pas */
	if ( (n-1) < N) {
		tab[n-1] = compteur;
	}
	return compteur;

}

/* On cherche la longueur du vol maximale pour les nombres e, allant de 1 à N */
void execution() {
	int i;
	int valeur;
	for (i = 1; i <= N; i++) {
		valeur = syracuse(i);
		if (valeur > max)
			max = valeur;
	}
}

/* Programme */
int main() {
	execution();
	printf("Max : %d\n", max);
	return 0;
}
