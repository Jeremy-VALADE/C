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
	char* end;
	char* value;

	char* test;
	int tmp;
	
	int exe = 1;
	init();
	while (exe) {
		value = readline(">>> ");
		
		add_history(value);	
		/*char* s = value;*/
		while (*value != '\0') {
			tmp = strtol(value, &end, 10);

			if (value != end) {
				printf("passe rien\n");
				printf("tmp : %d\n", tmp);
				push_in_stack(tmp);
			}
			value = end;

			if (isCharInTab(end[0], operation)) {				
				printf("passe operation\n");
				if (*end == '+')
					add();
			}
			else if (isCharInTab(end[0], fonctionnalite)) {			
				if (*end == 'a')
					print_stack();
				if (*end == 'q')
					exe = 0;
				printf("passe fonctionnailite\n");
			}
			value++;
		}
	}

	clear_history();
	return 0;
}



