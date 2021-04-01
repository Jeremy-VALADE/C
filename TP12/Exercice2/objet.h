typedef struct node {
	char word[50];
	struct node* next;
} Node, *List;


Node* allocation();
void insertion(List* liste, Node* node);
int size();
void free_list();

