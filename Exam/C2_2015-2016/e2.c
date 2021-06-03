#include <stdio.h>

int nb_swap_bit(unsigned long int u) {
	int i, bit1, bit2;
	int compteur = 0;

	for (i = 1; i < 8; i++) {
		bit1 = ((u>>(i-1)) & 1) ? 1 : 0;
		bit2 = ((u>>i) & 1) ? 1 : 0;
		if (bit1 != bit2)
			compteur++;
	}
	return compteur;
}

int main() {
	printf("%d\n", nb_swap_bit('\0'));
	printf("%d\n", nb_swap_bit(97));
	printf("%d\n", nb_swap_bit(255));
	printf("%d\n", nb_swap_bit(85));

	return 0;
}