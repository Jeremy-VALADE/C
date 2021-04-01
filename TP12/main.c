#include "objet.h"
#include <stdio.h>

int main() {
	FILE* fichier = fopen("Germinal.txt", "r");
	List l = NULL;
	char word[50];
	int i = 0;
	while (fscanf(fichier, "%s", word) == 1) {
		Node* node = allocation(word);
		insertion(&l, node);
		i++;
	}

	printf("diff : %d\n", size(&l));	
	printf("total word : %d\n", i);	
	free_list(l);
	return 0;
}
