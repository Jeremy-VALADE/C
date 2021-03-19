#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** allocationTabChaine(int size) {
	char** tab = (char**)malloc(size * sizeof(char*));
	return tab;
}

char* allocation2(int size) {
	char* chaine = (char*) malloc(size * sizeof(char));
	return chaine;
}

void affichage(char** tab, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("arg[%d] : %s\n", i, tab[i]);
	}
}

void free_array(char** chaine, int size) {
	int i;
	if (chaine == NULL) return;
	for (i = 0; i < size; i++) {	
		if (chaine[i] != NULL)
			free(chaine[i]);
	}
	free(chaine);
}

int main(int argc, char* argv[]) {
	char** tab = allocationTabChaine(argc);
	int i;
	for (i = 0; i < argc; i++) {
		tab[i] = allocation2(strlen(argv[i]) + 1);
		strcpy(tab[i], argv[i]);
	}

	affichage(tab, argc);
	free_array(tab, argc);
	return 0;	
}
