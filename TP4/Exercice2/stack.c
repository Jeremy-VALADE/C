#include <stdio.h>
#include "stack.h"


static Stack stack;

void stack_init(void) {
 	stack.size = 0;
}

int stack_size(void) {
	return stack.size;
}

int stack_is_empty(void) {
	return stack.size == 0;
}

int stack_top(void) {
	if (stack_is_empty()) {
		printf("La pile est vide");
		return 0;
	}
 
	return stack.values[stack.size - 1];
}

int stack_pop(void) {
	if (stack_is_empty()) {
		printf("La pile est vide");
		return 0;
	}
 
	stack.size--;
	return stack.values[stack.size];
}

void stack_push(int n) {
	if ( (stack.size+1) < MAX_SIZE) {
		stack.values[stack.size] = n;
		stack.size++;
	}
	else
		printf("Exception dép:assement index tableau\n");
}

void stack_display(void) {
	int i;
	for (i = 0 ; i < stack.size ; i++) {
		printf("\tIndex %d : %d\n", i, stack.values[i]);
	}
}

int stack_get_element(int index) {
	if (index < 0 || index > MAX_SIZE) {
		printf("Index pas initialisé passe !!!!\n");
		return 0;
	}
	else
		return stack.values[index];

}


/*int main() {
	stack_init();
	printf("Taille de la pile : %d \n", stack_size());
	printf("Pile vide ? %d\n", stack_is_empty());
	printf("Taille de la pile après Cinq push\n");
	stack_push(1);
	stack_push(2);
	stack_push(3);
	stack_push(4);
	stack_push(5);

	printf("Pile vide ? après push %d\n", stack_is_empty());
	printf("Taille de la pile : %d \n", stack_size());
	printf("Sommet de la pile doit être 5 : %d\n", stack_top());
	printf("Pop de la pile : %d\n", stack_pop());
	printf("Taille de la pile : %d\n", stack_size());
	printf("Element 1 : %d\n", stack_get_element(0));
	stack_display();

	return 0;
}*/
