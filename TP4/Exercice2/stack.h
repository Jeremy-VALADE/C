#ifndef _STACK_
#define _STACK_

#define MAX_SIZE 15

typedef struct stack {
	int values[MAX_SIZE];
	int size;
}Stack;

void stack_init(void);
int stack_size(void);
int stack_is_empty(void);
int stack_top(void);
int stack_pop(void);
void stack_push(int n);
void stack_diplay(void);
int stack_get_element(int index);

#endif
