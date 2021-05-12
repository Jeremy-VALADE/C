#include "operation.h"

int modulo(int* args) {
	return args[0] % args[1];
}

operation api_table = {'%', 2, modulo};