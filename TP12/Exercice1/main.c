#include <stdio.h>
#include <stdlib.h>  
#include "objet.h"

int main(int argc, char **argv) {
	FILE* fichier = fopen(argv[1], "r");
	if (fichier == 0) {
		perror("Canot open input file\n");
		exit(-1);		
	}
	else {		
		List l = NULL;
		char word[50];
		int i = 0;
		while (fscanf(fichier, "%s", word) == 1) {
			Node* node = allocation(word);
			insertion(&l, node);
			i++;
		}
		fclose(fichier);
		printf("diff : %d\n", size(&l));	
		printf("total word : %d\n", i);	
		free_list(l);

		return 0;
	}
}
