#include <stdio.h>
#include <stdlib.h>

int* allocation(int size) {
	int* tab = (int*)malloc(size*sizeof(int));
	if (tab == NULL) {
		fprintf(stderr, "Not enough memory\n");
		exit(1);
	}
	return tab;
}

void freeTab(int* tab) {
	free(tab);
}

void fillTab(int* tab, int size) {
	int i;
	for ( i = 0; i < size; i++) {
		tab[i] = i+1;
	}
}

void printTab(int* tab, int size) {
	int i;
	for (i = 0; i < size;i ++) {
		printf("%d ", tab[i]);
	}

}

int main(int argc, char* argv[]) {
	/* Debut */
	int* tab;
	int size = 0;
	/* Vérifie si le paramètre est null */
	if (argv[1] != NULL)
		size = atoi(argv[1]);

	/* Traitement */
	tab = allocation(size);
	fillTab(tab, size);
	printTab(tab, size);
	freeTab(tab);

	/* Fin */
	printf("\n");
	return 0;
}
