#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>
#include <dlfcn.h>
#include "../Headers/fonctionnalites.h"
#include "../Headers/fonctions.h"
#include "../Headers/operation.h"

#define PATH_LIBRARY "Plugin/"

int main() {
	struct dirent **namelist; /*Récupère les noms des fichiers */
	int n; /* Récupère le nombre de fichier */
	void* objet; /* Variable qui stocke l'objet opértion des bibliothèques (api_table) */

	n = scandir(PATH_LIBRARY, &namelist, filter, alphasort);
	if (n == -1) {
		fprintf(stderr, "scandir");
		exit(EXIT_FAILURE);
	}

	operation* tabOperation[n];
	char idOperation[n];	
	int i = 0;
	while (n--) {
		char* path = concat(PATH_LIBRARY, namelist[n]->d_name);
		objet = dlopen(path, RTLD_LAZY);	


		if (objet != NULL) {
			tabOperation[i] = dlsym(objet, "api_table");
			idOperation[i] = tabOperation[i]->symbole;
			i++;
		}
		else {
			fprintf(stderr, "Problem with library : %s\n", path); 
		}
		free(namelist[n]);
	}
	free(namelist);


	char fonctionnalites[] = {'q', 'p', 'c', 'a', 'r'};
	char* value;
	char* end; 
	int entier, position, result;
	int* args;

	init();	
	while (1) {
		value = readline(">>> ");
		add_history(value);
		
		while (*value != '\0') {
			entier = strtol(value, &end, 10);
			if (value != end)
				push_in_stack(entier);

			value = end;
			if ((position = isCharInTab(*end, idOperation)) != -1) {
				if (stack_size() >= tabOperation[position]->arite) {
					int arite = tabOperation[position]->arite;
					args = (int*) malloc(arite*sizeof(int));
					i = 0;
					while (arite--) {
						args[i] = stack_pop();
						i++;
					}
					result = tabOperation[position]->eval(args);
					if (result != INT_MIN)
						push_in_stack(result);
					else {
						for (arite = 0; arite < i; arite++)
							push_in_stack(args[arite]);
					}

					free(args);
				}
				else {
					fprintf(stderr, "Stack needs %d params \n", tabOperation[position]->arite); 
				}
				value++;
			}

			else if (isCharInTab(*end, fonctionnalites) != -1) {
				switch (*end) {
					case 'q':
						dlclose(objet);
						clear_history();
						exit(EXIT_SUCCESS);
					break;

					case 'a':
						print_stack();
					break;

					case 'c':
						clear_stack();
						init();
					break;

					case 'r':
						reverse();
					break;

					case 'p':
						top_in_stack();
					break;
				}
				value++;
			}
			else if (*value == ' ') {
				value++;
			}
			else if (*value != '\0') {
				fprintf(stderr, "'%c' COMMAND INVALID !!!\n", *value);
				value++;
			}
		}

	}

	if (objet != NULL)
		dlclose(objet);
	clear_history();

	exit(EXIT_SUCCESS);
}