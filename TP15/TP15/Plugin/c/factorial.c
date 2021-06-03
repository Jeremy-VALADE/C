#include "../../Headers/operation.h"

int factorial(int* args) {
	int i;
	int result = 1;
	for (i = 1; i <= args[0]; i++)
		result *= i;
	return result;
}

operation api_table = {'!', 1, factorial};

