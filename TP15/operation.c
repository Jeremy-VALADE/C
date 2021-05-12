#include <stdio.h> 
#include <math.h>
#include <limits.h>
#include "stack.h"
#include "operation.h"

Stack* pile;

void init() {
	pile = create_stack();
}

void top_in_stack() {
	int value = top(pile);
	if (value != INT_MIN)
		printf("%d\n", top(pile));
}

void push_in_stack(int entier) {
	push(pile, entier);
}

void clear_pile() {
	free_stack(pile);
}

int verification() {
	if (pile->current < 2) {
		fprintf(stderr, "Not enough arguments\n");
		return 0;
	}
	return 1;
}

void add() {
	if (!verification()) 
		return;
	int entier1 = pop(pile);
	int entier2 = pop(pile);
	push(pile, entier1 + entier2);
}

void subtraction() {
	if (!verification()) 
		return;
	int entier1 = pop(pile);
	int entier2 = pop(pile);
	push(pile,  entier1 - entier2);
}

void multiplication() {
	if (!verification()) 
		return;
	int entier1 = pop(pile);
	int entier2 = pop(pile);
	push(pile, entier1 * entier2);
}

void division() {
	if (!verification()) 
		return;
	int entier1 = pop(pile);
	int entier2 = pop(pile);
	push(pile, entier1 / entier2);
}

void modulo() {
	if (!verification()) 
		return;
	int entier1 = pop(pile);
	int entier2 = pop(pile);
	push(pile, entier1%entier2);
}

void factorielle() {
	int entier1 = pop(pile);
	int i, f = 1;
	for (i = 1; i <= entier1; i++)
    	f = f * i;
	push(pile, f);
}

void exponentiation() {
	int entier1 = pop(pile);
	int entier2 = pop(pile);
	push(pile, (int) pow(entier1, entier2));
}

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

void reverse() {
	if (!verification()) 
		return;
	int entier1 = pop(pile);
	int entier2 = pop(pile);
	push(pile, entier2);
	push(pile, entier1);
}
