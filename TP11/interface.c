#include <MLV/MLV_all.h>


void create_window() {
	MLV_create_window("Game", NULL, 271, 186);
}

MLV_Image* load_image() {
	return MLV_load_image("Images/image1.jpeg");
}


void free_window() {
	MLV_free_window();
}

int main() {
	MLV_Image *image;
	int red, blue, green, alpha;
	create_window();
	image = load_image("Images/image1.jpeg");
	int i, w, h;

	/*for (h = 0; h < 4; h++) {
	  int ligne = 0;séparation de 10 pixel
	  for (w = 0; w < 271; 
	  }*//*
	for (i = 0; i < 4; i++) {
		for (h = (i*186/4); h < ((i*186/4) + 186/4); h++) {
			int extention = 0;
			int ext = 0;
			if ((h%(186/4)) == 0 && (h <= (186/4)*3))
				ext = 20;
			for (w = 0; w < 271; w++) {
				if ((w%(271/4)) == 0 && (w <= (271/4)*3))
					extention = 10;
				MLV_get_pixel_on_image(image, w, h, &red, &green, &blue, &alpha);
				if (i == 3 && h >= (186/4 * 3) && w >= (271/4*3)) {
					MLV_draw_filled_rectangle(271/4*3, 186/4*3, 271/4, 186/4, MLV_COLOR_BLACK);
					break;
				}
				else {

				MLV_draw_pixel(w + extention, h+ext, MLV_rgba(red, green, blue, alpha));
				}
				extention = 0;
			}

		}
	}*/
	/*		MLV_draw_image(image, 0, 0);
	*/
	MLV_draw_filled_rectangle(0, 0, 271, 186, MLV_COLOR_WHITE);
	MLV_Image* m = MLV_copy_partial_image(image, 271/4*2, 186/4*2, 271/4, 186/4);
	MLV_draw_image(m, 0, 0);	
	MLV_Image* l = MLV_create_image(271/2, 186/2);
	MLV_draw_image(l, 271/2, 186/2);
	MLV_actualise_window();


	while (1) {}

	MLV_free_image(image);
	MLV_free_window();

	return 0;
}
