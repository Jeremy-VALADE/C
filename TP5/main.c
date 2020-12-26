/* Programme implémentant différente fonction */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tableau.h"

/* Exécution du programme */
int main(int argc, char* argv[]){
	srand(time(NULL));
	/* Test des fonctions de l'exercice 1 */
	int tab[6] = {0, 1, 2, 3, 4, -1};
	printf("Tableau : \n");
	print_array(tab);
	printf("La taille de ce tableau est de : %d éléments \n", array_size(tab));
	printf("Vérification de la méthode are_equals_array sur ce tableau : \n");
	printf("Si 1 alors les deux tableaux sont égaux sinon 0\n");
        printf("Résultat de la fonction are_equals_array(tab,tab) : %d\n", are_arrays_equal(tab,tab));


	int* tab2; /* Le tableau 2 sera une copie du tableau 1 */
	tab2 = copy_array(tab);
	printf("Tableau 2\n");
	printf("Tableau 1 == Tableau2 ? : %d\n", are_arrays_equal(tab, tab2));
	print_array(tab2);


	/* ----------------------------------------------------------- */
	/* Test des fonctions de l'exercice 2 */
	/* Test de la fonction fill_array */
	int* newTab;
	newTab = fill_array();
	printf("Affiche du tableau saisi\n");
	print_array(newTab);

	/* Test de la fonction random_array */
	int* randomTab1;
	int* randomTab2;
	int* randomTab3;
	int* randomTab4;
	
	randomTab1 = random_array(5, 100);
	randomTab2 = random_array(5, 100);
	randomTab3 = random_array(5, 100);
	randomTab4 = random_array(5, 100);

	print_array(randomTab1);
	print_array(randomTab2);
	print_array(randomTab3);
	print_array(randomTab4);

	/* Test de la fonction concat_array */
	int concatTab1[3] = {1, 123, -1};
	int concatTab2[5] = {1, 25, 32, 32, -1};
	int* concatTab = concat_array(concatTab1, concatTab2);
	printf("Tableau 1\n");
	print_array(concatTab1);
	printf("Tableau 2\n");
	print_array(concatTab2);
	printf("Concaténation du tableau1 et du tableau 2\n");
	print_array(concatTab);

	/* Tests des fonctions de l'exercice 3 */ 

	/* Test de la fonction merge_sort */
	int tabImpair[4] = {1, 3, 5, -1};
	int tabPair[5] =  {2, 4, 6, 8, -1};
	int* tabTrier = merge_sorted_arrays(tabImpair, tabPair);
	printf("Tableau Impair\n");
	print_array(tabImpair);
	printf("Tableau Pair\n");
	print_array(tabPair);
	printf("Tableau trier (impair + pair)\n");
	print_array(tabTrier);

	/* Tests de la fonction split_arrays */
	int tableau[9] = {1, 2, 3, 4, 5, 6, 7, 8, -1};	
	int* tableauPartie1;
	int* tableauPartie2;

	split_arrays(tableau, &tableauPartie1, &tableauPartie2);
	printf("Tableau à diviser en deux\n");
	print_array(tableau);
	printf("Deux tableaux \n");
	print_array(tableauPartie1);
	print_array(tableauPartie2);

	/* Test de la fonction merge_sort */
	int* tableau1;
	int* tableau2;
	int* tableau3;

	int* triTableau1;
	int* triTableau2;
	int* triTableau3;
	
	tableau1 = random_array(20, 100);
	tableau2 = random_array(20, 100);
	tableau3 = random_array(20, 100);

	triTableau1 = merge_sort(tableau1);
	triTableau2 = merge_sort(tableau2);
	triTableau3 = merge_sort(tableau3);

	printf("Tableau 1\n");
	print_array(tableau1);
	printf("Tri du tableau \n");
	print_array(triTableau1);
	printf("Tableau 2 \n");
	print_array(tableau2);
	printf("Tri du tableau \n");
	print_array(triTableau2);
	printf("Tableau 3 \n");
	print_array(tableau3);
	printf("Tri du tableau \n");
	print_array(triTableau3);


	/*	int* tab1;
	int** tab2;
	int** tab3 = NULL;
*/
/*	tab3 = random_array(10, 100);
	print_array(tab3);
	tab1 = allocate_integer_array(16);
	tab2 = allocate_integer_array(16);
	tab3 = allocate_integer_array(16);
	tab = {0,1,2,3,4,-1};
	*//*
	tab1[0] = 1;
	tab1[1] = 155;
	tab1[2] = 475;
	tab1[3] = 9;
	tab1[4] = 555;
	tab1[5] = -1;
*/
/*	tab1 = fill_array();
	print_array(tab1);
	printf("\n");
	printf("\n");
	printf("\n");
	print_array(merge_sort(tab1));
	printf("Taille tableau 20 ? : %d\n", array_size(tab1));
	printf("\n");
	split_arrays(tab1, &tab2, &tab3);
	print_array(tab2);
	 printf("\n");
	print_array(tab3);		*/
	/*	tab2[0] = 1;
	tab2[1] = 8;
	tab2[2] = 10;
	tab2[3] = -1;
	tab2[4] = -1;
	tab3 = merge_sorted_arrays(tab2, tab1);
		print_array(tab3);*/
	/*	tab3 = concat_array(tab1, tab2);
 *
	print_array(tab3);*/
	/*printf("Taille du tab : %d\n", array_size(tab));*/
/*	tab3 = copy_array(tab2);
	print_array(tab3);
	printf("Equals ? : %d\n", are_array_equals(tab, tab2));
*/	return 0;
}
