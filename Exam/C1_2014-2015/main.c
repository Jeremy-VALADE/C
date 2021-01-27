#include <stdio.h>
#include <string.h>

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void miror_array(int t[], int n) {
	int lo = 0;
	int hi = n/2;
	while (lo <= hi) {
		swap(&t[lo], &t[n-lo-1]);
		lo++;
	}
}

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


int nb = 0;
int strange(int a, int b) {
	nb++;
	if (a >= b) {
		return 1;
	}
	return strange(a+1, b) + strange(a, b-1);
}

typedef struct student {
	char first_name[64];
	char last_name[64];
	int age;
}Student;

void initialize_student(Student* st, char* first_name, char* last_name, int age) {
	int i;
	for (i = 0; i< strlen(first_name); i++) {
		st->first_name[i] = first_name[i];
	}
	for (i = 0; i< strlen(last_name); i++) {
		st->last_name[i] = last_name[i];
	}
	st->age = age;
}

int is_valid_matrix(int mat[8][8]) {
	int i, j, nombreDe1;
	int sum = 0;
	/* lignes */
	for (i = 0; i < 8; i++) {
		nombreDe1 = 0;		
		for ( j = 0; j < 7; j++) {
			if (mat[i][j] == 1) {
				nombreDe1++;
				sum++;
			}
		}
		
		if (nombreDe1%2 != mat[i][7])
			return 0;
		else
			sum++;
	}
	/* colonnes */
	for (i = 0; i < 8; i++) {
		nombreDe1 = 0;		
		for ( j = 0; j < 7; j++) {
			if (mat[j][i] == 1) {
				nombreDe1++;
				sum++;
			}
		}
		
		if (nombreDe1%2 != mat[7][i])
			return 0;
		else
			sum++;
	}

	/*toutes la matrice */
	if (sum%2 != mat[7][7])
		return 0;

	return 1;
}

void repair_matrix(int mat[8][8]) {
	int i, j, nombreDe1;
	int sum = 0;
	int ligne = -1;
	int colonne = -1;

	/* lignes */
	for (i = 0; i < 8; i++) {
		nombreDe1 = 0;		
		for ( j = 0; j < 7; j++) {
			if (mat[i][j] == 1) {
				nombreDe1++;
				sum++;
			}
		}
		
		if (nombreDe1%2 != mat[i][7])
			ligne = i;
		else
			sum++;
	}
	/* colonnes */
	for (i = 0; i < 8; i++) {
		nombreDe1 = 0;		
		for ( j = 0; j < 7; j++) {
			if (mat[j][i] == 1) {
				nombreDe1++;
				sum++;
			}
		}
		
		if (nombreDe1%2 != mat[7][i])
			colonne = i;
		else
			sum++;
	}

	/*toutes la matrice */
	if (sum%2 != mat[7][7]) {
		ligne = 7;
		colonne = 7;
	}
	if (ligne != -1 && colonne != -1) {
		if (mat[ligne][colonne] == 0) {
			mat[ligne][colonne] = 1;
		}
		else {
	
			mat[ligne][colonne] = 0;
		}
	}

}




int main(int argc, char* argv[]) {
/*	char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	char* chaine;
	int occurrence[26] = {0};
	int i, j, k;

	for (i = 1; i < argc; i++) {
		chaine = argv[i];
		for ( j = 0; j < strlen(chaine); j++) { 
			k = 0;
			while (k < 26) {	
				if (alphabet[k] == chaine[j]) {
					occurrence[k] += 1;
					break;
				}	
				k++;
			}
		}
	}

	for (i = 0; i < 26; i++) {
		if (occurrence[i] != 0)
			printf("%c : %d\n", alphabet[i], occurrence[i]);
	}
*/
/*
	int t[] = {12, 45, -3, 18, 5, 7, -50};
	print_tableau(t, 7);
	miror_array(t, 7);
	print_tableau(t, 7);
*/
/*	int i;
	if (argc == 1) {
		printf("Pas assez d'arguments \n");
		return 1;
	}
	for (i = strlen(argv[1]) - 1; i >= 0; i--) {
		printf("%c", argv[1][i]);
	}
	printf("\n");
*/
/*
	printf("%d\n", strange(0,4));
	printf("nombre d'appels : %d\n", nb);
*/
	Student st;
	char prenom[] = "Jeremy";
	char nom[] = "VALADE";
	initialize_student(&st, prenom, nom, 20);
	
	printf("%s\n", st.first_name);
	printf("%s\n", st.last_name);
	printf("%d\n", st.age);

	return 0;
}
