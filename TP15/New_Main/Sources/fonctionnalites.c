#include <stdio.h> 
#include <math.h>
#include "../Headers/stack.h"
#include "../Headers/fonctionnalites.h"

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

int stack_pop() {
	return pop(pile);
}
void clear_stack() {
	free_stack(pile);
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
	int entier1 = pop(pile);
	int entier2 = pop(pile);
	push(pile, entier2);
	push(pile, entier1);
}

int stack_size() {
	return pile->current;
}