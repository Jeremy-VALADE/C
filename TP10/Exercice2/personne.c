#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "personne.h"

Cell* allocate_cell(char* first, char* last, int age) {
	Cell* c = (Cell*)malloc(sizeof(Cell));

	strcpy(c->first_name,first);
	strcpy(c->last_name, last);
	c->age = age;
	return c;
}

/*
   Méthode qui compare l'âge de deux personnes
   Retour possible de la méthode :
   0 < -> âge de la personne 1 est infèrieur à l'âge de la personne 2
   >0 -> âge de la personne 1 est supérieur à l'âge de la personne 2
   == 0 -> l'âge des deux personnes sont égaux
   */
int age_order(Cell* p1, Cell* p2) {
	int diff = p1->age - p2->age;
	if (diff != 0)
		return diff;
	else {
		diff = strcmp(p1->first_name, p2->first_name);
		if (diff != 0)
			return diff;
		diff = strcmp(p1->last_name, p2->last_name);
		return diff;
	}	
}

/* Méthode qui compare de manière alphabétique deux personnes */
int name_order(Cell* p1, Cell* p2) {
	int diff = strcmp(p1->first_name, p2->first_name);
	if (diff != 0)
		return diff;
	diff = strcmp(p1->last_name, p2->last_name);
	if (diff != 0)
		return diff;
	diff = p1->age - p2->age;
	return diff;
}


void ordered_recursive(List* liste, Cell* new, int order_func(Cell* c1, Cell* c2)) {
	if (!(*liste) || (order_func(*liste, new) > 0)) {
		new->next = *liste;
		*liste = new;
	}
	else {
		ordered_recursive(&((*liste)->next), new, order_func);
	}
}

void ordered_insertion(List* liste, Cell* new, int order_func(Cell* c1, Cell* c2)) {
	Cell* tmp = NULL;
	Cell* c = *liste;

	while (c && order_func(c, new) < 0) {
		tmp = c;
		c =  c->next;
	}
	new->next = c;
	if (tmp) 
		tmp->next  = new;
	else
		*liste = new;
}

void display(List liste) {
	Cell* c = liste;
	printf("Liste : \n");
	while (c != NULL) {
		printf("%s %s %d\n", c->first_name, c->last_name, c->age);
		c = c->next;
	}
}

void free_list(List l) {
	Cell* c = l;
	Cell* tmp = NULL;
	while (c != NULL) {
		tmp = c;
		c = c->next;
		free(tmp);
	}
}





