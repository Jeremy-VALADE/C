/* Programme qui calcule la puissance d'un nombre de deux manières différents */

#include <stdio.h>

/* Manière itérative */
int iterative_puissance(int a, int n){
	int nombre = a;
	int i;

	if ( n == 0) 
		return 1;	

	for (i = 1; i < n; i++) 
		nombre*=a;

	return nombre;
}

/* Manière récursive */ 
int recursive_puissance(int a, int n) {
	if (n == 0) 
		return 1;
	return a*recursive_puissance(a,n-1);
}

/* Exécution du programme */
int main() {
	printf("Fonction iterative_puissance(2, 3) : %d\n", iterative_puissance(2, 3));
	printf("Fonction recursive_puissance(2, 3) : %d\n", recursive_puissance(2, 3));
	return 0;
}
