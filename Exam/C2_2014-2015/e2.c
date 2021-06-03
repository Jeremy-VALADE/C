#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct cell {
	char* name;
	struct cell* next;
} Cell, *List;

char* alphabetMaj = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char* alphabet = "abcdefghijklmnopqrstuvwxyz";

int positionAlphabet(char c) {

	int i;
	for (i = 0; i < 26; i++) {
		if (alphabet[i] == c)
			return i;
	}
	return -1;
}


void beginUpperCase(char* name) {	
	int position = positionAlphabet(name[0]);
	if (position != -1) {		
		*name = alphabetMaj[position];
	}
	
}
void applyFuncList(List l, void(*func)(char* )) {
	Cell* tmp = l;
	while (tmp != NULL) {
		func(tmp->name);
		tmp = tmp->next;
	}
}

int main() {
	char toto[] = "bonjour";
	beginUpperCase(toto);
	List l = NULL;
	applyFuncList(l, beginUpperCase);
	printf("%s\n", toto);
	return 0;
}