#include <stdio.h>
#include "tableau.h"

/* Fonction de test */ 
void test(int tableau[], int taille) {
	printf("Affichage tableau\n");
	print_tableau(tableau, taille);
	printf("Moyenne du tableau : %d\n", moyenne(tableau, taille));
	printf("Minimum du tableau : %d\n", min(tableau, taille));
	printf("Maximum du tableau : %d\n", max(tableau, taille));
}

/* Tests des différentes fonctions du fichier tableau.c sur un tableau */ 
int main() {
	int tab[6] = {15, 16, 17, 18, 19, 20};
	int tab2[6] = {0, 6, 7, 8, 19, 14};
	int tab3[6] = {15, 13, 6, 1, 19, 20};

	test(tab, 6);
	test(tab2, 6);
	test(tab3, 6);

	return 0;
}
