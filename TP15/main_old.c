#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include "operation.h"


int isCharInTab(char c, char tab[]) {
	int i;
	for (i = 0; i < strlen(tab); i++) {
		if (tab[i] == c)
			return 1;
	}
	return 0;
} 

int main() {
	char operation[] = {'+', '-', '*', '/', '%', '!', '^'};
	char fonctionnalite[] = {'q', 'p', 'c', 'a', 'r'};
	 
	char* elt = NULL;
	
	char * ptr;
	char* delim = " ";
	char* end;
	long value;
	int exe = 1;
	init();

	while (exe) {
		elt = readline(">>> ");	
		add_history(elt);	
		ptr = strtok(elt, delim);
		printf("elt : %s\n", elt);

		while(ptr != NULL) {	
			printf("ptr : %s\n", ptr);

			if (strlen(ptr) == 1 && (isCharInTab(ptr[0], operation) || isCharInTab(ptr[0], fonctionnalite))) {
				char c = ptr[0];
				switch(c) {
					case 'q':
  						exe = 0;
					break;
					
					case 'p':
						top_in_stack();
					break;

					case 'c':
						/*clear_pile();*/
						init();
					break;

					case 'a':
						print_stack();
					break;

					case 'r':
						reverse();
					break;

					case '+':
						add();
					break;
					
					case '-':
						subtraction();
					break;

					case '*':
						multiplication();
					break;

					case '/':
						division();
					break;

					case '%':
						modulo();
					break;

					case '!':
						factorielle();
					break;

					case '^':
						exponentiation();
					break;
				}
			}
			else {
				value = strtol(ptr, &end, 10);
				if (value == 0 && strcmp(ptr, "0") != 0)
					printf("Erreur : commande : %s don't find\n", ptr);
				else {
					printf("Value : %ld\n", value);
					push_in_stack(value);
				}
			}
			ptr = strtok(NULL, delim);
		}
	}
	clear_history();
	return 0;
}



/*fichier .so*/