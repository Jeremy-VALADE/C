#include <stdio.h>

/* Programme qui affiche son code source */
int main(){
	/* Variable qui stocke un caractère du fichier */
	char caractere;
	/* Récupération du fichier */
	FILE* source;
	source = fopen("main.c", "r");

	/* Affichage des lignes du fichier */
	while ((caractere = fgetc(source)) != EOF) 
		printf("%c", caractere);	

	/* Fermeture du fichier */ 
	fclose(source);

	return 0;
}
