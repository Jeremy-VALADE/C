#include <stdio.h>
#include "operation.h"
/* 
 * Le joueur peut poser 8 dames sur l'échiquier.
 * Chaque case du tableau représente une dame posé par le joueur.
 * Si la case vaut -1 alors le joueur n'a pas encore posé sa n ème dame.
 * */
int dames[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

/* Insère une dame dans le tableau */
void insert_dame(int numCase, int ligne, int colonne) {
	int i;
	for (i = 0; i < 8; i++) {
		if (dames[i] == -1)
			break;
	}
	dames[i] = numCase;
	updatePlateau(numCase, ligne, colonne);
}

/* Retourne 1 si cette case est une dame sinon 0*/
int caseIsDame(int numCase) {
	int i;
	for (i = 0; i < 8; i++) {
		if (numCase == dames[i])
			return 1;
	}
	return 0;
}

/* Fonction qui retourne 1 si la case est prise sinon 0 */
int caseIsTake(int numCase) {
	return getCase(numCase);
}

/* Si la fonction renvoie 1, cela indique que toutes les cases de l'échiquier sont remplit sinon elle renvoie 0. */
int allCaseFill() {
	return fullCase();
}

/* Renvoie le nombre de dame dans le tableau */
int sizeDames() {
	int i = 0;
	while (dames[i] != -1 && i < 8) {
		i++;
	}
	return i;
}

/* Fonction qui affiche la position des dames du tableau*/ 
void printDames() {
	int i = 0;
	for (i = 0; i < sizeDames(); i++)
		printf("%d ", dames[i]);
}

/* Fonction qui donne la ligne et la colonne d'une case de l'échiquier
	Les variables ligne et colonne sont des pointeurs ainsi les paramères passés en argument seront modifiés.
*/
void getCoordooneeeCase(int numCase, int* ligne, int* colonne) {
	int numberCase = 63;
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (numCase == numberCase) {
				*ligne = 7-i;
				*colonne = 7-j;
				return;
			}

			numberCase--;
		}
	}				
}

/*
	Fonction qui remplit l'échiquier avec les dames du tableau 
*/
void fillChess() {
	int i = 0;
	int a; 
	int b;
	while (dames[i] != -1) {
		getCoordooneeeCase(dames[i], &a, &b);
		updatePlateau(dames[i], a, b);
		i++;
	}
}   

/* Fonction qui supprime la dernière dame du tableau*/
void deleteDame() {
	int size = sizeDames();
	if (size != 0)
		dames[size-1] = -1;
	reset();
	fillChess();
}