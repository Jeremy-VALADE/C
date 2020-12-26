#include <stdio.h>

/*Fonction permettant d'affichier la suite n, n-1, ..., 1, 1 ,n+1,..., n*/
void iteration(int x) {	
	if (x == 1) {
		printf("1 ");
		printf("1 ");
	}
	else {
		printf("%d ",x);
		iteration(x-1);
		printf("%d ", x);
	} 	
}

/* Fonction appelant la fonction iteration avec l'argument saisi par l'utilisateur */
int main() {
	/* Récupération du paramètre de l'utilisateur */ 
	int nombre;
	printf("Entrez une valeur : ");
	scanf("%d",&nombre);

	/* Appel de la fonction */
	iteration(nombre);	
	printf("\n");

	/* Fin */
	return 0;
}
