/* Fonction qui renvoie la position d'un char dans un tableau de char.
   Si le char n'est pas trouvé, elle renvoie -1
*/
int isCharInTab(char c, char tab[]);

/* Fonction qui filtre tous les fichiers .so*/
int filter(const struct dirent * d);

/* Fonction qui renvoie la chaine s1 concaténer à la chaine s2*/ 
char* concat(const char *s1, const char *s2);