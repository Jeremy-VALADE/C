#include "objet.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
	if (!find(liste, node->word)) {
		node->next = *liste;
		*liste = node;
	}
}

int size(List* liste) {
	int size = 0;
	Node* node = *liste;
	while (node != NULL) {
		size++;
		node = node->next;
	}
	return size;
}

void free_list(List l) {
	Node* c = l;
	Node* tmp = NULL;
	while (c != NULL) {
		tmp = c;
		c = c->next;
		free(tmp);
	}
}



