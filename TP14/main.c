#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <string.h>
#include <ftw.h>

#define MAX_SIZE 10

typedef struct position {
	char path[8192];
	unsigned long int size;
} Position;

typedef struct tableau {
	Position* index[MAX_SIZE];
	int size;
} Tableau;

/* Variable globale contenant des informations sur les dix fichiers les plus gros */
Tableau* t;

Tableau* create_tableau() {
	Tableau* tab = (Tableau*) malloc(sizeof(Tableau));
	int i;
	for (i = 0; i < MAX_SIZE; i++) {
		tab->index[i] = NULL;
	}
	tab->size = 0;
	return tab;

}

Position* create_link(const char* path, unsigned long int size) {
	Position* p = (Position*) malloc(sizeof(Position));
	strcpy(p->path, path);
	p->size = size;
	return p;
}

void display() {
	int i;
	for (i = 0; i < t->size; i++) {
		printf("%ld %s\n", t->index[i]->size, t->index[i]->path);
	}

}

void free_tab() {
	int i;
	for (i = 0; i < t->size; i++) {
		free(t->index[i]);
	}
	free(t);
}

void insert_sorted(const char* path, int size) {
	int i = t->size-1;
	while (i >= 0 && t->index[i]->size < size) {
		if (i < MAX_SIZE-1)
			t->index[i+1] = t->index[i];
		else 
			free(t->index[i]);
		i--;
	}
	if (i < MAX_SIZE-1)
		t->index[i+1] = create_link(path, size);
	
	if (t->size < MAX_SIZE)
		t->size++;
}	

static int insert_tab(const char *fpath, const struct stat *sb, int tflag) {
	if (tflag != 1) { /* tflag == 1 -> correspond au fichier*/
		insert_sorted(fpath, sb->st_size);
	}

	return 0;
}

int main(int argc, char* argv[]) {
	t = create_tableau();

	if (argc == 2) {
		ftw(argv[1], insert_tab, 10);
		display();
		free_tab();
		
		exit(EXIT_SUCCESS);
	}
	return 0;
}
