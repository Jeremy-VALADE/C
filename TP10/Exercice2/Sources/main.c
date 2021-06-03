#include <stdio.h>
#include <stdlib.h>
#include "../Headers/personne.h"
	

int main() {
	FILE* fichier = fopen("liste_nom.txt", "r");
	char nom[256];
	char prenom[256];
	int age;
	List l = NULL;
	int choix = 0;
	printf("1 - Trier la liste des pesonnes par âge\n");
	printf("2 - Trier la liste des pesonnes par ordre alphabétique\n");
	printf("Votre choix\n");
	scanf("%d", &choix);
	while (fscanf(fichier, "%s %s %d", nom, prenom, &age) == 3) { 
		Cell* c = allocate_cell(nom, prenom, age);
		if (choix == 1)
			ordered_recursive(&l,  c, age_order);
		else 
			ordered_recursive(&l,  c, name_order);
	}
	fclose(fichier);

	display(l);
	free_list(l);
	return 0;
}
