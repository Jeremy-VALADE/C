/* Insère une dame dans le tableau */
void insert_dame(int numCase, int ligne, int colonne);

/* Retourne 1 si cette case contient une dame sinon 0*/
int caseIsDame(int numCase);

/* Renvoie le nombre de dame dans le tableau */
int sizeDames();

/* Supprime la dernière dame posée par le joueur*/
void deleteDame();

/* La fonction retourne la valeur de la fonction getCase dans le fichier operation.c*/
int caseIsTake(int numCase);

/* Si la fonction renvoie 1, cela indique que toutes les cases de l'échiquier sont remplit sinon elle renvoie 0. */
int allCaseFill();