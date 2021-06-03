typedef struct node {
	char word[8192];
	struct node* next;
} Node, *List;

Node* allocation();
void insertion(Node* node);
int size();
void free_list();

