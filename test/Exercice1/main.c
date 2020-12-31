#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void cube_it(int* p) {
	*p = (*p) * (*p) * (*p);
}

const char* vowel="aeiouy";

int has_vowel(char* chaine){
	int i, j;
	for (i = 0; i < strlen(chaine); i++) {
		for (j = 0; j < strlen(vowel); j++) {
			if (chaine[i] == vowel[j])
				return chaine[i];
		}
	}
	return 0;
}
void rotate_string3(char *s){
	char toto[100];
	int i;
	char caractere = s[0];
	for (i = 1; i < (strlen(s)); i++) {
		toto[i-1]= s[i];
	}
	toto[i-1] = caractere;
	toto[i] = '\0';
	strcpy(s, toto);
}
/*
   void rotate_string(char *s){
   char toto[100];
   int i;
   char caractere = s[0];
   for (i = 1; i < (strlen(s)); i++) {
   s[i] = s[i];
   }
   strncpy(s, toto, i+1);
   }*/
/*
   void reverse_words(char* sentence) {
   char** tableau = split(sentence, " ");
   }

   char** split(char* s, char delimiter) {
   char tableau[100];
   int i;
   for (i = 0; i < strlen(s); i++) {
   if (s[i] != delimiter)
   strncpy(tableau[1], s, 
   }
   }
   */
int is_a_number(char* s){
	int nombre = atoi(s);
	printf("nombre : %d\n", nombre);	

	return 0;
}

/*Programme qui affiche "HelloWorld" */
int main() {
	/*	int t = 2;
		int *p = &t;
		cube_it(p);
		printf("Résultat : %d\n", *p);
		*/
	/*	printf("Résultat : %d\n", has_vowel("a"));
	*/
	char test[] = "test";
	rotate_string3(test);
	printf("%s\n", test);

	printf("NUmber : %d\n", is_a_number("0"));
	printf("NUmber : %d\n", is_a_number("-10"));
	printf("NUmber : %d\n", is_a_number("a0"));
	printf("NUmber : %d\n", is_a_number("3.14"));
	/*	char* t = "";
		printf("%s\n", t);
		*/

	return 0;
}
