typedef struct node {
	char word[50];
	struct node* next;
} Node, *List;


Node* allocation();
void insertion(List* liste, Node* node);
int size(List* liste);
void free_list(List liste);
