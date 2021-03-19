#include <stdio.h>
#include <stdlib.h>
#include "personne.h"
	

int main() {
	FILE* fichier = fopen("liste_nom.txt", "r");
	char nom[256];
	char prenom[256];
	int age;
	List l = NULL;
	
	while (fscanf(fichier, "%s %s %d", nom, prenom, &age) == 3) { 
		Cell* c = allocate_cell(nom, prenom, age);
		ordered_insertion(&l,  c, name_order);
	}
	fclose(fichier);

	display(l);
	free_list(l);
	return 0;
}
