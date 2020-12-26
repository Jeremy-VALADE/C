/* Fonctions sur des tableaux */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Fonction qui fourni un espace mémoire pour le tableau */
int* allocate_integer_array(int size){
  int* new_tab;

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}

/* Fonction qui créait des tableaux aléatoire */
int* creationTableauAleatoire(int taille) {
	int* tableau;
	int i;
	tableau = allocate_integer_array(taille);
	for (i = 0 ; i < taille ; i++) 
		tableau[i] = (rand() % 100) + 1; /* Valeur du tableau entre 1 et 100 */ 
	return tableau;
}


/* Fonction qui effectue le tri à bulle */
void tri_a_bulle(int tableau[], int taille) {
	int i;
	for (i = taille ; i > 1 ; i--) {
		int var;
	  	int k;	
		for ( k = 0 ; k < (i-1) ; k++) {
			if (tableau[k] > tableau[k+1]) {
				var = tableau[k+1];
				tableau[k+1] = tableau[k];
				tableau[k] = var;			
			}
		}
	}
}

/* Fonction qui affiche un tableau */ 
void afficherTableau(int tableau[], int taille) {
	int i;
	printf("[");
	for (i = 0; i < taille ; i++) { 
		printf("%d", tableau[i]);
		if ( (i+1) != taille)
			printf(", ");
			
	}

	printf("]\n");
}


