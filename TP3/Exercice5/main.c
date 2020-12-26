/* Programme qui effectue un tri à bulle */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tableau.h"

/* Exécution du programme */ 
int main() {
	int taille; /* Taille du tableau */
	int i;
	/* Initialisation des nombres aléatoires */
	srand(time(NULL));
	for (i = 0 ; i < 5 ; i++) {
		int* tableau;
		taille = (rand() % 20 ) + 2; /*Taille du tableau entre 2 et 20*/
		printf("Tableau %d\n", i+1);
		tableau = creationTableauAleatoire(taille);
		afficherTableau(tableau, taille);
		printf("Tri du tableau\n");
		tri_a_bulle(tableau, taille);	
		afficherTableau(tableau, taille);
		printf("\n");
	}
	return 0;
}
