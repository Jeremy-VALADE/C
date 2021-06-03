#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sub_word_ptr(const char* w, const char* pattern) {
	char* pointeur;
	int compteur = 0;

	int i= 0;
	while (*w != '\0') {
		if (*w == pattern[compteur]) {
			if (*w == pattern[0])
				pointeur = (char*)w;
			compteur++;
		}
		else {
			pointeur = NULL;
			compteur = 0;
		}

		if (compteur == strlen(pattern)-1)
			break;
		w++;
	}

	return pointeur;
}

int main() {
	char toto[] = "wabcababyyabccd";
	char t[] = "aabbc";
	char* str = sub_word_ptr(toto, "abc");
	printf("str : %s\n", str);
	char* str2 = sub_word_ptr(t, "abc");
	if (str2 == NULL)
		printf("null\n");

	return 0;
}