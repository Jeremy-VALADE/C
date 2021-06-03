#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct movies {
	char titre[8192];
	int annee;
	char realisateur[8192];
	int duree;
	char** acteurs;
} Movie;


typedef struct listMovies {
	Movie** movies;
	int size;
	int current;
}listMovies;


void display_movie(Movie* l) {
	printf("Titre : %s\n", l->titre);
	printf("Annee de sortie: %d\n", l->annee);
	printf("Réalisateur : %s\n", l->realisateur);
	printf("Duree : %d\n", l->duree);
	printf("acteurs : \n");
	int i;
	for (i = 0; i < 3; i++) {
		if (l->acteurs[i] != NULL)
			printf("%s\n", l->acteurs[i]);
	} 
}

void ajout(listMovies* list, char titre[], int annee, char realisateur[], int duree, char acteurs[]) {
	Movie* m = (Movie*) malloc(sizeof(Movie));
	strcpy(m->titre, titre);
	m->annee = annee;
	strcpy(m->realisateur, realisateur);
	m->duree = duree;
	if (list->size == list->current) {
		list->size = list->size *2;
		list->movies = (Movie**) realloc(list->movies, sizeof(Movie*)*list->size);
		if (list->movies == NULL)
			fprintf(stderr, "Erreur mémoire\n");
	}
	list->movies[list->current] = m;
	list->current++;
}

/*Pointeur de fonction : int define(Movie* m1, Movie* m2);*/

int compareReal(void* m1, void* m2) {
	Movie* n1 = (Movie*)m1;
	Movie* n2 = (Movie*)m2;

	return strcmp(n1->realisateur, n2->realisateur);
}

void sort_by(listMovies* list, int compare(const void* m1, const void* m2)) {
	qsort(list, list->size, sizeof(Movie), compare);
}

/*Pointeur : int isCritere(Movie* m1)*/ 

int filtre(Movie* m1) {
	if (m1->annee <= 1970)
		return 1;
	return 0;
}

void display_filter(listMovies* l, int filter(Movie* m1)) {
	int i;
	for (i = 0; i < l->size; i++) {
		if (filter(l->movies[i]))
			display_movie(l->movies[i]);
	}
}

int main() {
	return 0;
}