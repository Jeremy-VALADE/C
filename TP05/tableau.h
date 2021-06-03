/* Fonctions exercice 1 du TP5 */
int array_size(int* array);
void print_array(int* array);
int are_arrays_equal(int* first, int* second) ;
int* copy_array(int* array);

/* Fonctions exercice 2 du TP5 */
int* fill_array(void); 
int* random_array(int size, int max_entry);
int* concat_array(int* first, int* second);

/* Fonction exercice 3 du TP5 */
int* merge_sorted_arrays(int* first, int* second);
void split_arrays(int* array, int** first, int** second);
int* merge_sort(int* array);
