#include "objet.h"
#include <stdio.h>

int main() {
	FILE* fichier = fopen("big.txt", "r");
	List l = NULL;
	char word[50];
	unsigned long int i = 0;
	while (fscanf(fichier, "%s", word) == 1) {
		Node* node = allocation(word);
		insertion(&l, node);
		i++;
	}

	printf("diff : %d\n", size(&l));	
	printf("total word : %ld\n", i);	
	free_list(l);
	return 0;
}
