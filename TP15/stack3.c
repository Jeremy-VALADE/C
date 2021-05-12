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
	printf("Pile : \n");
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


int main() {
	stack_init();
	printf("Initialisation de la pile\n");
	printf("Taille de la pile : %d éléments \n", stack_size());
	printf("La pile est-elle vide ? %d\n", stack_is_empty() == 1);
	printf("Push de cinq éléments dans la pile\n");
	stack_push(10);
	stack_push(2);
	stack_push(3);
	stack_push(4);
	stack_push(5);

	printf("La pile est-elle vide après les push ?  %d\n", stack_is_empty() == 1);
	printf("Taille de la pile : %d \n", stack_size());
	printf("Le sommet de la pile doit être 5 : %d\n", stack_top() == 5);
	printf("Pop de la pile doit être 5 (sommet) : %d\n", stack_pop() == 5);
	printf("Taille de la pile doit être égal à 4 car on a enlevé un élément : %d\n", stack_size() == 4);
	printf("Affichage de l'élément 1 : %d\n", stack_get_element(0));
	stack_display();

	return 0;
}
