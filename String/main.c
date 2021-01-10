#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Fonction qui remplace toutes les lettres identique de la chaine par rapport à un caractère par un autre caractère */
void test_strchr(char* chaine, char a_remplacer, char replace) {
	char * pointeur = NULL;

	printf("Test de la fonction strchr\n");
	printf("Chaine : %s \n", chaine);
	printf("On va remplacer les lettres '%c' de la chaine par les lettres : '%c'\n", a_remplacer, replace);

	pointeur = strchr(chaine, a_remplacer);
	while (pointeur != NULL ) {
		*pointeur = replace;
		pointeur = strchr(pointeur + 1, a_remplacer);
	}
}

void test_strfry(char* chaine) {
	char *pointeur;
	
	printf("Test de la fonction srfry qui change aléatoirement une chaine\n");
	printf("Chaine '%s' : \n", chaine);
	pointeur = strfry(chaine);
	printf("Echange 1 : %s\n", pointeur);
	printf("Echange 2 : %s\n", (char *) strfry(chaine));
	printf("Echange 3 : %s\n", (char *) strfry(chaine));

}

/* Tests des différentes fonctions de la librairie string.h */
int main() {
	char* chaine = "TEST";
	char newChaine[40];
	char* chaine2 = (char *) malloc( 5 * sizeof(char) );
	printf("Affichage de la chaîne pour les tests : %s\n", chaine);

	printf("Test de la fonction strlen\n");
	printf("Longueur de la chaine doit être égale à 4 : %s\n", 4 == strlen(chaine) ? "vrai" : "faux");

	printf("\n");

	printf("Test de la fonction strcopy\n");
	printf("newChaine n'est pas initialisé : %s\n", newChaine);
	printf("Copie de la chaine 'TEST' dans la variable newChaine : %s\n", strcpy(newChaine, chaine));

	printf("\n");

	printf("Test de la fonction strcmp\n");
	printf("Cette fonction compare deux chaines de caractères\n");
	printf("Vérifions en comparant une chaine caractère à elle-même\n");
	printf("Comparons la variable chaine à elle-même : %s\n", 0 == strcmp(chaine, chaine) ? "les chaines sont identiques" : "les chaines ne sont pas identiques"); 
	printf("Comparons la variable chaine à la chaine 'TOTO' : %s\n", 0 == strcmp(chaine, "TOTO") ? "les chaines sont identiques" : "les chaines ne sont pas identiques"); 

	printf("\n");

	printf("Test de la fonction strcat\n");
	strcpy(chaine2, chaine);
	printf("Fonction qui ajoute une chaine à une autre\n");
	printf("Test sur la chaine 'TEST', le programme ajoutera ' SUCCESS'\n");
	printf("Résultat de la chaine finale : %s\n",  strcat(chaine2, " SUCCESS"));

	printf("\n");

	strcpy(chaine2, "TOTO");
	test_strchr(chaine2, 'O', 'A');
	printf("Chaine remplacé : %s\n", chaine2);
	
	printf("\n");
	
	strcpy(chaine2, chaine);
	test_strfry(chaine2);
	

	return 0;
}
