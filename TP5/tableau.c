/* Programme implémentant différentes fonctions en rapport avec les tableaux de l'exercie 1 du TP5 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
   Allocate memory for an array which can contain `size`
   integers. The returned C array has memory for an extra last
   integer labelling the end of the array.
   */
int* allocate_integer_array(int size){
	int* new_tab;

	new_tab = (int*)malloc((size+1)*sizeof(int));
	if (new_tab == NULL){
		fprintf(stderr, "Memory allocation error\n");
		return NULL;
	}
	return new_tab;
}

/* Free an integer array */
void free_integer_array(int* tab){
	free(tab);
}

/*
 * Fonction qui calcule la taille d'un tableau 
 * Tant que la case du tableau n'est pas égal à -1, on continue à parcourir le tableau
 */
int array_size(int* array) {
	int taille = 0;	
	while (array[taille] != -1) {
		taille++;
	}

	return taille;
}

/* Fonction qui affiche les éléments d'un tableau */
void print_array(int* array) {
	int taille = array_size(array);
	int i;
	for (i = 0 ; i < taille ; i++) {
		if ( (i+1) == taille)
			printf("%d ", array[i]);
		else
			printf("%d - ", array[i]);
	}
	printf("\n");
}

/* 
 * Fonction qui compare deux tableaux
 * Renvoie 1 si les deux tableaux sont égaux sinon 0
 */
int are_arrays_equal(int* first, int* second) {
	/* Compare élément par élément */ 
	int taille = array_size(first);
	int i;
	/* Compare la taille des deux tableaux */
	if (array_size(first) != array_size(second))
		return 0;

	for (i = 0 ; i < taille ; i++) {
		if (first[i] != second[i])
			return 0;
	}

	return 1;
}

/* Copie un tableau dans un autre tableau */
int* copy_array(int* array) {
	int* tab;
	int taille = array_size(array) + 1; /*Car le -1 on ne le compte pas*/
	int i;

	tab = allocate_integer_array(16);
	for (i = 0 ; i < taille ; i++) 
		tab[i] = array[i];

	return tab;
}


/* Cette fonction permet à l'utilisateur de remplir un tableau */
int* fill_array(void) {

	int taille;
	int* tab;

	int i;
	printf("Saisir la taille du tab : ");
	scanf("%d", &taille);
	printf("%d\n", taille);

	tab = allocate_integer_array(taille);
	for (i = 0 ; i < taille ; i++) {
		printf("Tab[%d] : ", i);
		scanf("%d", &tab[i]);
		printf("%d\n", tab[i]);
	}

	tab[taille] = -1;
	return tab;
}

/* Cette fonction produit des tableaux aléatoires */
int* random_array(int size, int max_entry) {
	int i;
	int *tab;
	tab =  allocate_integer_array(size);

	for (i = 0 ; i < size ; i++)
		tab[i] = (rand() % max_entry); /* Valeur du tableau entre 0 et max_entry */
	tab[size] = -1;
	return tab;
}

/*
 * Cette fonction concanne deux tableaux en un
 * Exemple tab = elementTab1 + elementTab2
 */
int* concat_array(int* first, int* second) {
	int* tab;
	/* Récupération de la taille */
	int taille1 = array_size(first);
	int taille2 = array_size(second);
	int taille = taille1 + taille2;

	int i;
	/* Allocation mémoire pour un tableau */
	tab =  allocate_integer_array(taille);

	for ( i = 0 ; i < taille ; i++) {
		if (i < taille1)
			tab[i] = first[i];
		else
			tab[i] = second[i - taille1];
	}
	tab[taille] = -1;
	return tab;
}

/*
 *
 * Retourne un tableau trié en fusionnant les deux tableaux
 */
int* merge_sorted_arrays(int* first, int* second) {
	int* tab;
	int taille1 = array_size(first);
	int taille2 = array_size(second);
	int taille = taille1 + taille2; /*Compter le moins 1*/
	int i, j, k;
	tab =  allocate_integer_array(taille);

	if (taille1 == 0)
		return second;
	if (taille2 == 0)
		return first;	

	i = 0;	
	j = 0;
	k = 0;

	/* On parcoure la tableau */
	while (i < taille1 && j < taille2) {

		if (first[i] < second[j]) {
			tab[k] = first[i];
			i++;
		}
		else {
			tab[k] = second[j];
			j++;
		}
		k++;
	}

	if (i < taille1) {
		int l;
		for (l = i ; l < taille1 ; l++) {
			tab[k] = first[l];
			k++;
		}
	}
	else {
		int l;
		for (l = j ; l < taille2 ; l++) {
			tab[k] = second[l];
			k++;
		}
	}

	tab[taille] = -1;
	return tab;
}

/* Fonction qui fabrique deux tableaux à partir d'un */
void split_arrays(int* array, int** first, int** second) {
	int taille = array_size(array);
	int taille1 = taille/2;
	int taille2 = taille - taille1;

	int i;
	
	*first =  allocate_integer_array(taille1);
	*second = allocate_integer_array(taille2);

	for ( i = 0 ; i < taille ; i++) {
		if (i < taille1)
			(*first)[i] = array[i];
		else {
			(*second)[i - taille1] = array[i];
		}
	}

	(*first)[taille1] = -1;
	(*second)[taille2] = -1;
}

/* Cette fonction trie un tableau en utilisant le tri par fusion */
int* merge_sort(int* array) {
	if (array_size(array) <= 1)
		return array;
	else {
		int* tab4 = NULL;
		int* tab5 = NULL;
		split_arrays(array, &tab4, &tab5);

		return merge_sorted_arrays(merge_sort(tab4), merge_sort(tab5));

	}
}

