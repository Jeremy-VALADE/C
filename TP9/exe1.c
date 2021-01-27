#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int* tab;
	int size = 0;
	int i;

	/* Vérifie si le paramètre est null */
	if (argv[1] != NULL)
		size = atoi(argv[1]);

	tab = (int*)malloc(size*sizeof(int));
	if (tab == NULL) {
		fprintf(stderr, "Not enough memory\n");
		exit(1);
	}

	/* Remplit le tableau */
	for ( i = 0; i < size; i++) {
		tab[i] = i+1;
	}

	/* Affiche le tableau */
	for (i = 0; i < size;i ++) {
		printf("%d ", tab[i]);
	}
	
	printf("\n");
	free(tab);

	return 0;
}
