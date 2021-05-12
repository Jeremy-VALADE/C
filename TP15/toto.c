#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>



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
	while (exe) {
		value = readline(">>> ");
		/*tmp = strtol(value, &end, 10);*/
		add_history(value);	

		char* s = value;

		while (*s != '\0') {
			tmp = strtol(s, &end, 10);

			if (s != end) {
				printf("passe rien\n");
				printf("tmp : %d\n", tmp);
			}
			s = end;
			if (isCharInTab(end[0], operation)) {
				s++;
				printf("passe operation\n");
			}
			else if (isCharInTab(end[0], fonctionnalite) || end[0] ==' ') {
				s++;
				printf("passe fonctionnailite\n");
			}
		}


/*
		do {
			printf("value %s\n", end);

			tmp = strtol(value, &end, 10);
			if (*end == ' ') {
				*end += 1;
				printf("espace");
			}

			printf("tmp : %d\n", tmp);
			printf("test[0] : %c\n", end[0]);
		}	while (*end != '\0');*/
		/*while (test[0] != '\0') {	
			
			printf("test %s\n", test);
			printf("tmp : %d\n", tmp);
			printf("test[0] : %c\n", end[0]);
			tmp = strtol(test, &end, 10);*/
			/*if (test[0] == ' ')
				test += 1;*/
		/*} */
}
}