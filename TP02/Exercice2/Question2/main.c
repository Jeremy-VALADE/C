#include <stdio.h>
#include <stdlib.h>

/* Programme permettant d'afficher la somme de deux entiers entrées en arguments par l'utilisateur
 * Exemple : ./exe 5 5 => 5 + 5 = 10
 */

int main(int argc, char* argv[]) {
	/* Déclarations */
 	int entier1, entier2, somme;

	/* Si il n'y a pas trois arguments, on n'exécute pas le programme */ 
	if (argc != 3) {
		printf("Erreur : pas d'arguments\n");
		return 1;
	}
	
	/* Récupération des entiers */
	entier1 = atoi(argv[1]);
	entier2 = atoi(argv[2]);
	somme = entier1 + entier2;

	/* Affichage de la somme */
	printf("Somme de %d + %d = %d:\n", entier1, entier2, somme);
	
	/* Fin */
	return 0;
}
