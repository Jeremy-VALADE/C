#include "objet.h"

/* Fonction qui affiche la fenêtre */
void create_window(Taquin* taquin);
MLV_Image* getImage(char* string);
void coordonneesSouris(int* x, int* y);
void free_window(MLV_Image* image);
void affichage(Taquin* taquin);
void victoire_window(Taquin* taquin, int time);
