/* Programme appliquant le principe de la dichotomie */

#include <stdio.h>

/* 
 * Fonction permettant de trouver la position d'un élément dans le tableau
 * Sinon la fonction retourne -1
 */
int dichotomie(int tab[], int n, int start, int end) {
	int milieu = (start + end) /2;
	/* Si on a parcouru tous le tableau, alors l'élément n'existe pas */
	if (end < start)
		return -1;

	if (n == tab[milieu])
		return milieu;
	else {
		if ( n > tab[milieu]) 
			start = milieu + 1;
		else
			end = milieu - 1;
	}
	return dichotomie(tab, n, start, end);
}

/* Fonction qui affiche un tableau */
void print_array(int tab[], int taille) {
	int i;
	printf("[");
	for (i = 0; i < taille ; i++) {
		printf("%d", tab[i]);
	        if (!((i+1) == taille))
			printf(", ");	       
	}
	printf("]\n");
}


/* Exécution du programme */
int main() {
	int tab[5] = {10, 22, 30,50,75};
	int tab2[20];
	
	/* Initialisation du tableau 2 */
	int i;
	for (i = 0; i < 20; i++)
		tab2[i] = i;

	/* Tests sur tableau 1 */
	printf("Tableau 1\n");
	print_array(tab, 5);
	printf("Tests \n");
	printf("Le chiffre 22 dans le tableau se trouve à l'index :  %d\n", dichotomie(tab, 22,0, 5));
	printf("Le chiffre 75 dans le tableau se trouve à l'index :  %d\n", dichotomie(tab, 75, 0, 5));

	printf("\n");

	/* Tests sur tableau 2 */
	printf("Tableau 2\n");
	print_array(tab2, 20);
	printf("Tests \n");
	printf("Le chiffre 17 dans le tableau se trouve à l'index :  %d\n", dichotomie(tab2, 17, 0, 19));
	printf("Le chiffre 3 dans le tableau se trouve à l'index :  %d\n", dichotomie(tab2, 3, 0, 19));
	printf("Le chiffre 11 dans le tableau se trouve à l'index :  %d\n", dichotomie(tab2, 11, 0, 19));
	
	return 0;
}
