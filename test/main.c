#include <stdio.h>
#include <string.h>

void reverse_words(char* sentence) {
	char c[500];
	char* contenu[500];

	int i = 0;
	int j = 0;
	int k = 0;
	while (sentence[i] != '\0') {
		if (sentence[i] != ' ') {
			c[k] = sentence[i];
			k++;
		}
		else {
			c[k] = ' ';
			k++;
			c[k] = '\0';
			char s[500];
			strcpy(s, c);
			
			contenu[j] = s;
			printf("contenu 0 : %s\n", contenu[0]);
			printf("%s\n", contenu[j]);
			k = 0;
		}
		i++;
	}
	c[k] = '\0';	
	contenu[j] = c;
	printf("%s\n", contenu[0]);
	printf("%s\n", contenu[1]);
	j++; 
	for (i = 0; i < j ; i++) {

		printf("i : %d -> %s ", i, contenu[i]);
	}

}

int main() {
	reverse_words("deux mot");
	return 0;
}
