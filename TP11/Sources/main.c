#include <time.h>
#include <unistd.h>
#include "../Headers/objet.h"
#include "../Headers/interface.h"

int main() {
	/* Coordonnées de la souris */
	int x, y;
	time_t begin, end;
	MLV_Image* image = NULL;
	Taquin* taquin = createTaquin(512, 512, 4, 5);

	srand(time(NULL));
	create_window(taquin);
	image = getImage("Images/image2.png");
	createPlateau(taquin, image);

	affichage(taquin);
	begin = time(NULL);
	while (!verification(taquin)) {
		coordonneesSouris(&x, &y);
		getCase(taquin, x, y);
		affichage(taquin);
	}
	end = time(NULL);
	victoire_window(taquin, difftime(end, begin));
	/* Affichage de l'écran de victoire */
	sleep(20);
	free_window(image);
	free_taquin(taquin);

	return 0;
}
