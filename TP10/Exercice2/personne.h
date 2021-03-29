typedef struct cell {
        char first_name[256];
        char last_name[256];
        int age;
        struct cell* next;
}Cell, *List;

Cell* allocate_cell(char* first, char* last, int age);
int name_order(Cell* p1, Cell* p2);
int age_order(Cell* p1, Cell* p2);
void ordered_insertion(List* liste, Cell* new, int order_func(Cell*, Cell*));
void display(List liste);
void free_list(List liste);
void ordered_recursive(List* liste, Cell* new, int order_func(Cell* c1, Cell* c2));
