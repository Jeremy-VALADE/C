/* Fonction qui initialise la fenêtre, l'image le son du jeu */
void create_window();

/* Fonction qui détermine les coordonées de la case sélectionnée.
 * Transmet à la fonction find(x, y) la ligne et la colonne correspondant à cette case.
 * */
void findCase(int x, int y);

/* Fonction qui récupère les coordonnées de la souris */
void getSouris(int* x, int* y);

/* Fonction qui affiche le jeu. Il détermine aussi si vous avez gagné ou perdu */ 
int game_finish();

/* Fonction qui libère les ressources de la libMLV */ 
void free_window();
