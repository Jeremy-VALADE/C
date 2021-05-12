
/*
scandir();
dlsym(handle, symbole);
*/
 /*#define _DEFAULT_SOURCE*/
 #include <dirent.h>
 #include <stdio.h>
 #include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "operation.h"

int filter(const struct dirent * d) {
	char* toto;
	strncpy(toto, &d->d_name[strlen(d->d_name)-3], strlen(d->d_name));
	return 0 == strcmp(toto, ".so");
}


char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}



int main(void)
{
	struct dirent **namelist;
	int n;

	n = scandir(".", &namelist, filter, alphasort);
	if (n == -1) {
		perror("scandir");
		exit(EXIT_FAILURE);
	}
	printf("n %d\n", n);

	operation* tabOperation[n]; /*= (operation**)malloc(sizeof(operation*)* n);*/
	void* tata;
	int i = 0;
	while (n--) {
		printf("%s\n", namelist[n]->d_name);
		char* result = concat("./", namelist[n]->d_name);
		printf("result : %s\n", result);
		 tata = dlopen(result, RTLD_LAZY);
		if (!tata) {
			printf("tata is null\n");
			return 0;
		}
		tabOperation[i] = dlsym(tata, "api_table");

		printf("op->symbole : %c\n", tabOperation[i]->symbole);
		printf("op->arite : %d\n", tabOperation[i]->arite);
		int tab[2] = {5, 2};
		printf("op->add : %d\n",tabOperation[i]->eval(tab));
		
		/*free(tata);*/
/*
		printf("op->symbole : %c\n", tabOperation[i]->symbole);
		printf("op->arite : %d\n", tabOperation[i]->arite);
		int tab[2] = {5, 2};
		printf("op->add : %d\n",tabOperation[i]->eval(tab));*/
		i++;

		free(namelist[n]);
	}
	free(namelist);

	printf("fin %d \n ", i);
	/*
	*/
	/*return 0;*/
	if (tabOperation[0]== NULL) printf("C'est null");

	printf("op->symbole : %c\n", tabOperation[1]->symbole);
	printf("op->arite : %d\n", tabOperation[0]->arite);
	int tab[2] = {5, 2};
	printf("op->add : %d\n",tabOperation[0]->eval(tab));
	dlclose(tata);
exit(EXIT_SUCCESS);
	return 0;
}