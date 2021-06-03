#include "../../Headers/operation.h"

int power(int* args) {	
	if ( args[0] == 0) 
		return 1;
	
	int result = args[0];
	int i;
	for (i =  1; i < args[1]; i++) {
		result *= args[0];
	}
	return result;
}

operation api_table = {'^', 2, power};