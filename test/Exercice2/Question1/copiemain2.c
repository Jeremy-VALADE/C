#include <stdio.h>
#include <string.h>

/* Programme permettant d'afficher la somme de deux entiers entrées par l'utilisateur via scanf */
/*
   int concat(char* dest, char* s1, char* s2) {
   int i = 0;
   int j =0;
   int compteur;
   while (s1[i] != '\0') {
   i++;
   }
   while (s2[j] != '\0') {
   j++;
   }

   compteur = i+j;
   int taille1 = i;
   int taille2 = j;
   int k;
   j = i = 0;
   for (k= 0; k < compteur; k++) {
   if (k < taille1) {
   dest[k] = s1[i];
   i++;
   }
   else {
   dest[k] = s2[j];
   j++;
   }
   }

   printf("%d\n", strlen(dest));
   return j+i;
   }
   */

/* Fonction qui affiche un tableau */
void print_tableau(int tab[], int taille) {
	int i;
	printf("[");
	for (i = 0; i < taille ; i++) {
		printf("%d", tab[i]);
		if (!((i+1) == taille))
			printf(", ");	       
	}
	printf("]\n");
}



void tri_lineaire_borne(int t[], int size) {
	int occurrence[100] = {0};
	int i, j, k; 
	for (i = 0 ; i < size; i++) {
		occurrence[t[i]] += 1;
	}
	/*	print_tableau(occurrence, 100);*/
	printf("passe\n");

	k = 0;
	for (i =0; i < 100; i++) {
		/*	print_tableau(t, size);*/
		j = occurrence[i];
		/*	printf("j : %d\n",  occurrence[1]);*/
		while (j > 0) {
			t[k] = i;
			k++;
			j--;
		}
	}
}

void strange(char* arg) {
	int i;
	for (i = strlen(arg); i >=0; i--) {
		printf("%c", arg[i]);
	}
	printf("\n");
}

void strange2(char* arg) {
	if (arg[0] == '\0') {
		printf("\n");
		return;
	}

	printf("%c", arg[strlen(arg)-1]);
	arg[strlen(arg)-1] = '\0';

	strange2(arg);
}


int index(int n) {

	int valeur[] = {100, 50, 10, 5, 1};
	int i;
	for (i = 0; i < 5; i++) {
		if (valeur[i] == n)
			return i;
	}
	return -1;
}
int index2(char c) {

	char chaine[] = {'C', 'L', 'X', 'V', 'I'};
	int i;
	for (i = 0; i < 5; i++) {
		if (chaine[i] == c)
			return i;
	}
	return -1;
}



void affiche_nombre_romain(int n) {
	int valeur[] = {100, 50, 10, 5, 1};
	char chaine[] = {'C', 'L', 'X', 'V', 'I'};
	int compteur = 0;
	char c[100];
	int i = 0;
	int quotient;
	int passe = 0;
	while (n !=0) {
		printf("n : %d\n", n);
		quotient = n/valeur[i];

		if (quotient > 3) {
			int index = i;
			if (compteur%2 ==0) {       
			printf("passe");	
				c[compteur] = chaine[i];
				compteur++;
				c[compteur] = chaine[i-1];
				compteur++;
				passe = 0;

			} 
			else 
			{
				compteur--;
				index =  index2(c[compteur]);
				printf("total %d\n", quotient*valeur[index] + n);
				c[compteur] = chaine[index];
				compteur++;
				c[compteur] = chaine[index-1];
				compteur++;
				passe = 1;
			/*	printf("%c\n", c[compteur]);*/
			}
			n-= valeur[i] * quotient;
			i++;
		}
		else {
			while (quotient > 0) {
				c[compteur] = chaine[i];
				n -= valeur[i];
				quotient--;
				compteur++;
			}
			i++;	
		}
	}
	c[compteur] = '\0';
	printf("Chaine : %s\n", c);
}
int main() {
	/*
	   char* chaine = "Bonjour";
	   char* chaine2 = " Jeremy";
	   char c[500];

	   printf("%d\n", concat(c, chaine, chaine2));
	   printf("%s\n", c);

*/
	/*
	   int t[] = {1,7,3,5,1,3,7,3,5,3,2,1,4,6,9};
	   tri_lineaire_borne(t, 15);
	   print_tableau(t, 15);	

	   char p[] = "poule";
	   strange(p);
	   strange2(p);
	   */
	/*	affiche_nombre_romain(66);*/
	/*	affiche_nombre_romain(400);	affiche_nombre_romain(98);
*/		affiche_nombre_romain(9);

		int i;
		for (i = 1; i < 100; i++) {
			printf("%d ->", i);
			affiche_nombre_romain(i);
			printf("\n");
	}
	
	return 0;
}
