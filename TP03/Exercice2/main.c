/* Programme qui compte le nombre de caractères, de mots et de lignes d'une chaine de caractères */

#include <stdio.h>

void wc() {
	char caractere;
	int mot;
	int compteur_caractere, compteur_mot, compteur_ligne;
	
	mot = 0; /*Boolean permettant de savoir si on est sur un mot */
	compteur_caractere = compteur_mot = compteur_ligne = 0;
	
	printf("Saisir une chaine de caractère, pour sortir faites Ctrl-d \n");	
	
	while ((caractere = getchar()) != EOF) {
		if (caractere == '\n') {
			compteur_ligne++;
			mot = 0;					
		}
		else if (caractere != ' ' && caractere != '\t') {			/*On vérfie que le valeur entré est un caractère */
			compteur_caractere++;
			if (mot == 0) {						/*Si il n'y a pas encore eu de mot, on incrémente */
				mot = 1;
				compteur_mot++;	
		       	}
		}
		else 
			mot = 0;
	} 
	printf("\n");
	printf("Nombres de caractères : %d\n", compteur_caractere);
        printf("Nombres de  mots : %d\n", compteur_mot);
        printf("Nombres de lignes : %d\n", compteur_ligne);
}


/* Exécution du programme */
int main() {
	wc();
	return 0;
}
