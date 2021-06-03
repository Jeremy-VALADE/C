#include <stdlib.h>
#include <stdio.h>
#include <string.h>     
#include <dirent.h>
#include "../Headers/fonctions.h"

/* Fonction qui renvoie la position d'un char dans un tableau de char.
   Si le char n'est pas trouvé, elle renvoie -1
*/
int isCharInTab(char c, char tab[]) {
	int i;
	for (i = 0; i < strlen(tab); i++) {
		if (tab[i] == c)
			return i;
	}
	return -1;
} 

/* Fonction qui filtre tous les fichiers .so*/
int filter(const struct dirent * d) {
	char str[20];
	strncpy(str, &d->d_name[strlen(d->d_name)-3], strlen(d->d_name));
	return 0 == strcmp(str, ".so");
}

/* Fonction qui renvoie la chaine s1 concaténer à la chaine s2*/ 
char* concat(const char *s1, const char *s2) {
	char *result = malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

/* Fonction qui affiche le menu du programme */
void menu() {
	printf("? help\n");
	printf("p Afficher la tête de la pile\n");
	printf("a Afficher la pile\n");
	printf("r Changer le premier et le deuxième élément de la pile\n");
	printf("c Vider la pile\n");
	printf("q Quitter le programme\n");
}