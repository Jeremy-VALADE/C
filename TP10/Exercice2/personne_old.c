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
	return 0;
}
/*
void ordered_insertion(List* liste, Cell* new, int order_func(Cell* c1, Cell* c2)) {
	printf("Passe\n");
	if (*liste == NULL) {
		new->next = *liste;
		*liste = new;
	}
	
	if (order_func(*liste, new) > 0) {
		new->next = *liste;
		*liste = new;
	}
	else {
		ordered_insertion((*liste)->next, new, order_func);
	}
}
*/
void ordered_insertion(List* liste, Cell* new, int order_func(Cell* c1, Cell* c2)) {
	printf("New : %s %s %d\n", new->first_name, new->last_name, new->age);
	if (*liste == NULL) {
		new->next = *liste;
		*liste = new;
	}
	else {
/*		Cell* tmp = *liste;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = new;

		
*/		Cell* c =  *liste;
		while (*liste != NULL) {
			printf("Passage dans la boucle\n");
/*			printf("New : %s %s %d\n", new->first_name, new->last_name, new->age);*/
			int valeur = order_func(c, new);
			if (valeur > 0) {
				printf("Valeur : %d\n", valeur);
				new->next = *liste;
				*liste = new;
				printf("Egalité : %d\n", c == *liste);
				printf("First-Personne : %s %s %d\n", c->first_name, c->last_name, c->age);
		/*		printf("Next-Personne : %s %s %d\n", c->next->first_name, c->next->last_name, c->next->age);
				printf("Next-Personne : %s %s %d\n", c->next->next->first_name, c->next->next->last_name, c->next->next->age);
		*/	
				return;
			}
			if ((*liste)->next == NULL)
				break;
			*liste = (*liste)->next;		
		
		}
	/*	printf("Fin de boucle : %s %s %d\n", c->first_name, c->last_name, c->age);
	*/	(*liste)->next = new;

	
	}
}

void display(List liste) {
	Cell* c = liste;
	printf("Liste : \n");
	while (c != NULL) {
		printf("%s %s %d\n", c->first_name, c->last_name, c->age);
		c = c->next;
	}
}







