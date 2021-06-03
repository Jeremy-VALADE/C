#include <stdio.h>

unsigned int pgcd(unsigned int a, unsigned int b) {
	if(a == 1 || b == 1)
		return 1;
	if (a == b)
		return a;
	int resteA = (a & (1<<0))  ? 1 :0;
		int resteB = (b & (1<<0))  ? 1 :0;

	if (resteA == 0 && resteB == 0) {
		a = a>>1;
		b = b>>1;
		return pgcd(a, b)<<1;
	}
	if (resteA == 0) {
		a = a>>1;
		return pgcd(a, b);
	}
	if (resteB == 0) {
		b = b>>1;
		return pgcd(a, b);
	}

	if (a > b)
		return pgcd(a-b ,b);
	else
		return pgcd(a, b-a);
}

int main() {
	printf("pcgd : %d\n", pgcd(333, 500));	
	unsigned int n= 1;
	printf("n :%d\n", ((n & (1<<0))) ? 1 :0);
	return 0;
}