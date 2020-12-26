/* Programme du Nombre Mystère */

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main() {
	/* Variable récupérant la saisie de l'utilisateur */
	char saisi[50];
	/* Booléen qui vérifie la saisi de l'utilisateur */
	int checkSaisi;
	/* Cette variable récupère la saisie de l'utilisateur si c'est un nombre */
	int nombre;
	int compteur = 0;

	/* Bornes */
	int min = 1;
	int max = 100;
	/* Cette variable récupère un nomnbre aléatoire entre le minimum et le maximum */
	int solution; 

	/* Initialisation de la graine pour obtenir un nombre aléatoires */
	srand(time(NULL));
	solution = (rand() % max) + min;

	/* Exécution du jeu */
	printf("Nombre Mystère !!!\n");
	do {
		/* Vérification de la saisie de l'utilisateur */
		do {
			checkSaisi = 1;
			printf("Saisir un nombre entre 1 et 100\n"); 
			scanf("%s", saisi);

			if (!(nombre = atoi(saisi))) {
				printf("Erreur : Chaine de caractère saisi\n");
				checkSaisi = 0;	
			}
			if ( nombre < min || nombre > max) {
				checkSaisi = 0;
				if (nombre < min) 
					printf("Erreur : le nombre %d est inférieur à la borne minimale : %d\n", nombre, min);
				if (nombre > max) 
					printf("Erreur : le nombre %d est supérieur à la borne maximale : %d\n", nombre, max);
			}
		} while (!checkSaisi);

		if (nombre < solution)
			printf("Le nombre mystère est plus grand\n");
		if (nombre > solution)
			printf("Le nombre mystère est plus petit\n");
		compteur++;
		printf("\n");
	} while (nombre != solution);

	/* Fin du jeu */
	printf("Vous avez gagné!!! Félicitation\n");
	printf("Nombre de coups = %d\n", compteur);

	return 0;
}


