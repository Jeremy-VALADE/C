#ifndef __STACK__
#define __STACK__

typedef struct dynamic_stack {
	int* values;
	int capacity;
	int current;
} Stack;

#endif

Stack* create_stack(void);
void push(Stack* pile, int elt);
int pop(Stack* pile);
int top(Stack* pile);
void free_stack(Stack* pile);
/*

*/