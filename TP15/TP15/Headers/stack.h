#ifndef __STACK__
#define __STACK__

typedef struct dynamic_stack {
	int* values;	/* Tableau d'entiers de la pile */
	int capacity;	/* Taille maximale du tableau */
	int current;	/* Taille courante du tableau */
} Stack;

#endif

/* Fonction qui initialise une pile */
Stack* create_stack(void);

/* Fonction qui insère un entier dans la pile */
void push(Stack* pile, int elt);

/* Fonction qui retourne  la tête de la pile  et le supprime de cette dernière*/
int pop(Stack* pile);

/* Fonction qui retourne la tête de la pile */
int top(Stack* pile);

/* Fonction qui libère la pile */
void free_stack(Stack* pile);
