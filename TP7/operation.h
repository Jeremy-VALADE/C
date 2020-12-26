int fread_board(const char* file, Board board);

/* Vérification que deux tableaux sont égaux */
int are_array_equals(Board first, Board second);

/* Affiche une grille de sudoku */
void print_board(Board b);

/* Cette fonction permet de dire s'il est possible de mettre 
 * ce chiffre dans la case sélectionnée */
int possible(Board b, int current, int num_ligne, int num_colonne);


/* Fonction qui résout un sudoku à une solution */
int solveSudoku(Board b, int row, int col);
