#include <stdio.h>

static unsigned short tab_short[8];


void init_global_static(void) {
	int i;
	for (i = 0; i < 6; i++) {
		tab_short[i] = i*10;
	}
}

int main() {
	int i;
	int* tab_int = (int*)tab_short;

	init_global_static();

	for (i = 0; i < 4; i++) {
		printf("%d ", *((unsigned short*)(&tab_int[i])));
	}
	return printf("\n");
}