/* Programme qui convertit une chaine de caractère en base 26 ou traduit un mot numérique en chaine de caractère */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const char* alphabet = "abcdefghijklmnopqrstuvwxyz";
/* Fonction qui convertit une chaine de caractère en base 10 */
int minusculeToNumerique(char chaine[]) {
	int taille = strlen(chaine);
	int i, j;
	int nombre = 0;
	char valeur;
	for (i = taille; i > 0; i--) {
		j = 0;
		while ((valeur = alphabet[j]) != chaine[i])
			j++;
		nombre += j*pow(26, taille-i);
	}
	return nombre;
}

/* Fonction qui convertit un nombre en une chaine de caractère */
char* numeriqueToMinuscule(int nombre) {	
	/* On récupère la chaine de caractère */
	char chaine[500];
	/* Variable qui renvoie la chaine convertit */
	char trueChaine[500];	
	/* Convertit le tableau chaine en chaine de caractère */
	char* c = malloc(500);
	int i = 0;
	int j = 0;
	/* Conversion de la chaine de caractère */
	while (nombre != 0) {
		chaine[i] = alphabet[nombre%26];
		nombre /= 26;
		i++;
	}
	chaine[i] = '\0';


	/* On inverse l'ordre du tableau */	
	while (chaine[j] != '\0') {
		trueChaine[i -j-1] = chaine[j];
		j++;
	
	}
	trueChaine[j] = '\0';
	sprintf(c,"%s", trueChaine);
	return c;
}

/* Exécution du programme */
int main(int argc, char *argv[]) {
	char* mot = argv[1];
	int nombre;
	if (mot != NULL) {
		if (!atoi(mot))
			printf("%d\n", minusculeToNumerique(mot));
 		if ((nombre = atoi(mot)))
			printf("%s\n", numeriqueToMinuscule(nombre));
	} else 
		printf("Erreur : pas d'argument\n");
	return 0;
}
