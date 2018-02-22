#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

int main()
{
	al_init();
	al_init_font_addon();
	al_init_image_addon();
	ALLEGRO_DISPLAY* display = al_create_display(800, 600);
	ALLEGRO_FONT* font = al_create_builtin_font();
	al_clear_to_color(al_map_rgb(0, 0, 0));

	ALLEGRO_BITMAP *testImage, *background;
	testImage = al_load_bitmap("ship.png");
	background = al_load_bitmap("background1.png");
	al_draw_bitmap(background, 0, 0, 0);
	al_draw_bitmap(testImage, 400, 400, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "we doing it bois");
	al_flip_display();
	al_rest(5.0);
	al_clear_depth_buffer(0);
	
	return 0;
}