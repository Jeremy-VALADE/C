#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../Headers/operation.h"

/* Cette variable contient 64 bits, chaque bits est une case de l'échiquier. */
unsigned long int n = 0;

/* Fonction qui affiche les bits d'un nombre de 64 bits */ 
void print_ULI(unsigned long int n) {
   int i = sizeof(unsigned long int)*8;
   while(i--) {
	   printf("i : %d -> %ld\n", i, n>>i & 1);
   }
}

/* Fonction qui renvoie la valeur d'un bit à la position en argument d'un nombre */
int  bit_n_ULI(unsigned long int n, int position) {
	return  n>>position & 1;
}

/* Fonction qui met le bit de position à 1*/
void set_positive_bit_ULI(unsigned long int* n, int position) {
	*n = (*n) | ((unsigned long int) 1<<position);
}

/* Fonction qui met le bit de position à 0*/
void set_negative_bit_ULI(unsigned long int* n, int position) {	
	*n =(* n) & ((unsigned long int) 0<<position);
}

/* Fonction qui retourne la valeur du bit à la position en argument*/
int getCase(int position) {
	return bit_n_ULI(n, position);
}

/* Fonction qui remet à zéro, l'échiquier */
void reset() {
	n = 0;
}

/* Fonction qui met à jour le plateau lorsque le joueur pose une dame */
void updatePlateau(int numCase, int a, int b) {
	int i;
	int ligne, colonne;

	/* Ligne */
	int tmp = b*8;
	for ( i = 0; i < 8; i++) {
		set_positive_bit_ULI(&n, tmp);
		tmp +=1;
	}

	/* Colonne */
	tmp = a;
	for (i = 0; i < 8; i++) {
		set_positive_bit_ULI(&n, tmp);
		tmp += 8;
	}

	/* Diagonale de droite supérieur */
	tmp = numCase+7;
	ligne = b;
	colonne = a;
	while (ligne < 7 && colonne > 0) {
		set_positive_bit_ULI(&n, tmp);
		ligne++; 
		colonne--;
		tmp += 7;
	}

	/* Diagonale de droite inférieur */
	ligne = b;
	colonne = a;
	tmp = numCase-7;
	while (ligne > 0 && colonne < 7) {
		set_positive_bit_ULI(&n, tmp);
		ligne--; 
		colonne++;
		tmp -= 7;
	}

	/* Diagonale de gauche supérieur */
	ligne = b;
	colonne = a;
	tmp = numCase + 9;
	while (ligne < 7 && colonne < 7) {
		set_positive_bit_ULI(&n, tmp);
		ligne++; 
		colonne++;
		tmp += 9;
	}

	/* Diagonale de gauche infèrieur */
	ligne = b;
	colonne = a;
	tmp = numCase - 9;
	while (ligne > 0 && colonne > 0 ) {
		set_positive_bit_ULI(&n, tmp);
		ligne--; 
		colonne--;
		tmp -= 9;
	}
}

/* Fonction qui retourne 1 si tous les bits sont égaux à 1 sinon 0*/ 
int fullCase() {
	int i = 64;
	while (i--) {
		if (bit_n_ULI(n, i) == 0) 
			return 0;
	}
	return 1;
}