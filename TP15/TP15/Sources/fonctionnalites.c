#include <stdio.h> 
#include <math.h>
#include <limits.h>
#include "../Headers/stack.h"
#include "../Headers/fonctionnalites.h"

/* Variable statique de la pile */
Stack* pile;

/* Fonction qui initialise la pile */
void init() {
	pile = create_stack();
}

/* Fonction qui libère la pile*/
void clear_stack() {
	free_stack(pile);
}

/* Fonction qui affiche la tête de la pile*/ 
void top_in_stack() {
	int value = top(pile);
	if (value != INT_MIN)
		printf("%d\n", top(pile));
}

/* Fonction qui ajoute un entier à la pile */
void push_in_stack(int entier) {
	push(pile, entier);
}

/* Fonction qui retourne la tête de la pile*/
int stack_pop() {
	return pop(pile);
}

/* Fonction qui inverse le premier et le deuxième élément de la pile */
void reverse() {	
	int entier1 = pop(pile);
	int entier2 = pop(pile);
	push(pile, entier1);
	push(pile, entier2);
}

/* Fonction qui retourne la taille de la pile*/
int stack_size() {
	return pile->current;
}

/* Fonction qui affiche la pile */
void print_stack() {
	if (pile->current == 0)
		printf("Stack is empty\n");
	else {
		int i;
		for (i = pile->current-1; i >= 0; i--)
			printf("%d ", pile->values[i]);
		printf("\n");
	}
}