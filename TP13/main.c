#include <stdio.h>
#include <unistd.h>
#include "interface.h"


int main() {
	/* Coordonnées de la souris (x, y) */
	int x;
	int y;
	create_window();

	while (!game_finish()) {
		getSouris(&x, &y);
		findCase(x, y);	
	} 

	sleep(20);	

	free_window();
	
	return 0;
}
