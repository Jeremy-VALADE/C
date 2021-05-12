#include <stdio.h>
#include <limits.h>
#include "../New_Main/Headers/operation.h"

int divide(int* args) {
	if (args[1] == 0) {
		fprintf(stderr, "Division by Zero\n");
		return INT_MIN;
	}
	return args[0] / args[1];
}

operation api_table = {'/', 2, divide};