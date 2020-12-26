#include <stdio.h>

/* 
 * Ce programme affiche la suite n, n-1, n-2, n-k 1 1  n+1, n+2, n
 */

void iterative(int n) {
	int nombre;
	nombre = n;
	while (nombre > 0) {
		printf("%d ", nombre);
		nombre -= 1;
	}

	while (nombre < n) {
		nombre += 1;
		printf("%d ", nombre);
	}

	printf("\n");	
}

int main() {
	int n;
	printf("Entrer un nombre : ");
	scanf("%d", &n);
	iterative(n);
	return 0;
}
