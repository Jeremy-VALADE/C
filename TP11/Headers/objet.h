#include <MLV/MLV_all.h>

/* Le jeu du taquin peut avoir au maximum 
le nombre d'image par ligne et par colonne en fonction de  
ces variables
*/
#define NB_LIGNE 16
#define NB_COLONNE 16


#ifndef __Taquin__
#define __Taquin__

typedef struct carre {
	int ligne;
	int colonne;
	MLV_Image* image;
} Carre;

/* Structure contenant toutes les parties de l'image*/
typedef struct plateau {
	int ligneCaseNoire;
	int colonneCaseNoire;
	Carre bloc[NB_LIGNE][NB_COLONNE];
} Plateau;

/* Caractéristique du jeu */
typedef struct Taquin {
	int width;
	int height;
	int nbCase;
	int epaisseurDuTrait;
	Plateau* p;
} Taquin;

#endif

/* Retourne un objet Taquin*/
Taquin* createTaquin(int width, int height, int nbCase, int epaisseurDuTrait);
/* Fonction qui crée un plateau*/
void createPlateau(Taquin* taquin, MLV_Image* image);
/* Fonction qui vérifie si la personne a résolu le jeu du taquin*/
int verification(Taquin* taquin);
/* Fonction qui récupère la case sur laquelle l'utilisateur a cliqué */
void getCase(Taquin* taquin, int x, int y);

/*Fonction qui libère le taquin */
void free_taquin(Taquin* taquin);
