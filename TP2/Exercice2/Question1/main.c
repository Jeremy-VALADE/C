#include <stdio.h>

/* Programme permettant d'afficher la somme de deux entiers entrées par l'utilisateur via scanf */

int main() {
	/* Déclaration */
	int entier1, entier2, somme;

	/* Valeur entré par l'utilisateur */ 
	printf("Entrez une valeur : ");
	scanf("%d",&entier1);
	printf("Entrez une deuxième valeur : ");
	scanf("%d", &entier2);
	somme = entier1 + entier2;
	
	/* Affichage de la somme */ 
	printf("Somme de %d + %d = %d:\n", entier1, entier2, somme);
	
	/* Fin du programme */
	return 0;
}
