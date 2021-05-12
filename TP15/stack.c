#include <stdio.h>   
#include <stdlib.h>
#include <limits.h>
#include "stack.h"



#define DEFAULT_SIZE_VALUES 1024

/* Function init a stack */
Stack* create_stack() {
	Stack* pile = (Stack*) malloc(sizeof(Stack));
	pile->capacity = DEFAULT_SIZE_VALUES;
	pile->values = (int*) malloc(DEFAULT_SIZE_VALUES*sizeof(int));
	pile->current = 0;
	return pile;
}

void realloc_values(Stack* pile) {
	pile->capacity = pile->capacity*2;
	pile->values = (int*) realloc(pile->values, pile->capacity * sizeof(int));
	if (pile->values == NULL) {
		fprintf(stderr, "Not enough meomory!\n");
		exit(1);
	}
}

void push(Stack* pile, int elt) {
	if (pile->current == pile->capacity) {
		realloc_values(pile);
	}
	pile->values[pile->current] = elt;
	pile->current++;
}

int pop(Stack* pile) {
	if (pile->current == 0) {
		fprintf(stderr, "Stack is empty\n");
		return INT_MIN;
	}
	
	pile->current--;
	return pile->values[pile->current];
	
}

int top(Stack* pile) {
	if (pile->current == 0) {
		fprintf(stderr, "Stack is empty\n");
		return INT_MIN;
	}
	return pile->values[pile->current-1];
}

void free_stack(Stack* pile) {
	free(pile->values);
	free(pile);
}
