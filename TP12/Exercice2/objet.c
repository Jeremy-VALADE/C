#include <string.h>
#include "objet.h"
#include <stdio.h>
#include <stdlib.h>

#define NB_PACK 4096

List tableau[NB_PACK];


int hash(char word[50]) {
	int i;
	unsigned int somme = 0;
	for (i = 0; i < strlen(word); i++) {
		somme += (i+1)*word[i];
	}
	somme = somme%NB_PACK;
	return somme;
}


Node* allocation(char word[50]) {
	Node* node = (Node*)malloc(sizeof(Node));
	strcpy(node->word, word);
	node->next = NULL;
	return node;
}

int find(List* liste, char word[50]) {
	Node* node = *liste;
	while (node != NULL) {
		if (strcmp(node->word, word) == 0) {
			return 1;
		}
		node = node->next;
	}

	return 0;
}



void insertion(List* liste, Node* node) {
	int hashWord = hash(node->word);
	if (tableau[hashWord] == NULL) {
		node->next = tableau[hashWord];
		tableau[hashWord] = node;
	}
	else if (!find(&tableau[hashWord], node->word)) {
		node->next = tableau[hashWord];
		tableau[hashWord] = node;
	}
}

int size() {
	int size = 0;
	int i;
	for (i = 0; i < NB_PACK; i++) {
		if (tableau[i] != NULL) {
			Node* node = tableau[i];
			while (node != NULL) {
				size++;
				node = node->next;
			}
		}	
	}
	return size;
}

void free_list() {
	int i;
	for (i = 0; i < NB_PACK; i++) {
		Node* c = tableau[i];
		Node* tmp = NULL;
		while (c != NULL) {
			tmp = c;
			c = c->next;
			free(tmp);
		}
	}
}

