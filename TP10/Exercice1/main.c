#include <stdio.h>
#include <stdlib.h>

void swap_mem(void* z1, void* z2, size_t size) {
	char* a = (char*) z1;
	char* b = (char*) z2;
	char c;

	int i;
	for (i = 0; i < size; i++) {
		c = a[i];
		a[i] = b[i];
		b[i] = c;	
	}
}

int main() {
	int a = 5;
	int b = 10;
	
	double c = 1025520.552225;
	double d = 25.255;

	printf("Echange des variables A et B\n");
	printf("A : %d, B : %d\n", a, b);
	swap_mem(&a, &b, sizeof(int));
	printf("Variable après échange\n");	
	printf("A : %d, B : %d\n", a, b);

	printf("Echange des variables C et D\n");
	printf("C : %f, D : %f\n", c, d);	
	swap_mem(&c, &d, sizeof(double));
	printf("Variable après échange\n");	
	printf("C : %f, D : %f\n", c, d);

	return 0;
}
