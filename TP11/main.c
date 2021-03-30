#include <time.h>
#include <unistd.h>
#include "objet.h"
#include "interface.h"

int main() {
	/* Coordonnées souris */
	int x, y;
	clock_t begin, end;
	MLV_Image* image = NULL;
	Taquin* taquin = createTaquin(512, 512, 4, 5);

	srand(time(NULL));
	create_window(taquin);
	image = getImage("Images/image2.png");
	createPlateau(taquin, image);

	affichage(taquin);
	begin = clock();
	while (!verification(taquin)) {
		coordonneesSouris(&x, &y);
		getCase(taquin, x, y);
		affichage(taquin);
	}
	end = clock();
	
	victoire_window(taquin, (end-begin)/CLOCKS_PER_SEC);
	sleep(20);
	free_window(image);
	free_taquin(taquin);





	return 0;
}
