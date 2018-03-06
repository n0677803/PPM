#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <string>
#include <iostream>

ALLEGRO_BITMAP *testImage, *background, *enemyShip, *projectileMain, *projectileSide;
int playerX, playerY, frameCount, windowWidth, windowHeight;
ALLEGRO_KEYBOARD_STATE *keyboardState;
std::vector<std::vector<int>> enemyList;
std::vector<std::vector<int>> projectileList;
std::vector<std::vector<int>> otherElementsList;
bool firing = false;

enum myKeys {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ESCAPE
};

class backgroundC {
protected:
	int x, y; 
public:
	float speed;

	void draw() {
		al_draw_bitmap(background, x, y, 0);
		if (y>windowHeight) {
			y = -(2000 - windowHeight);

			std::cout << "screen flip" << std::endl;
		}
		else if (y > 0) {
			al_draw_bitmap(background, 0, y-2000, 0);
		}		
	}
	void update() {
		y += speed;
		
	}

	void init() {
		x = 0;
		y = 0;
		speed = 1;
	}
};

void drawBackground() {
	al_draw_bitmap(background, 0, (frameCount%2000), 0);
	al_draw_bitmap(background, 0, ((frameCount % 2000) - 2000), 0);
}

void drawEnemies() {
	for (int i = 0; i < enemyList.size(); i++) {
		al_draw_bitmap(enemyShip,enemyList[i][0],enemyList[i][1],0);
	}
}

void drawProjectiles() {
	for (int i = 0; i < projectileList.size(); i++) {
		if (projectileList[i][2] == 0) {
			al_draw_bitmap(projectileMain, projectileList[i][0], projectileList[i][1], 0);
		}
		else {
			al_draw_bitmap(projectileSide, projectileList[i][0], projectileList[i][1], 0);
		}
	}
}

void drawScreen() {
	
	drawEnemies();
	drawProjectiles();
	al_draw_bitmap(testImage, playerX, playerY, 0);
	al_flip_display();
	al_clear_depth_buffer(0);
	frameCount++;
}

void updateProjectiles() {
	for (int i = 0; i < projectileList.size(); i++) {
		if (projectileList[i][1] < -100) {
			projectileList.erase(projectileList.begin() + i);
		}
		else {
			projectileList[i][1] -= 10;
		}
	}
}

float distanceBetween(int x1, int y1, int x2, int y2) {
	return sqrt((((x2 - x1) ^ 2) + ((y2 - y1) ^ 2)));
}

void updateEnemies() {
	if (enemyList.size() > 0 && projectileList.size()>0) {
		for (int j = 1; j < projectileList.size(); j++) {
			for (int i = 0; i < enemyList.size(); i++) {
				if (distanceBetween(projectileList[j][0], projectileList[j][1], enemyList[i][0], enemyList[i][1]) < 30) {
					enemyList.erase(enemyList.begin() + i);
				}
			}
		}
	}
}


void spawnEnemy() {
	std::vector<int> temp;
	temp.push_back(100);
	temp.push_back(100);
	enemyList.push_back(temp);
}

void handleInput() {

}

int main()
{
	al_init();
	al_init_font_addon();
	al_init_image_addon();
	al_install_keyboard();
	windowHeight = 600;
	windowWidth = 800;

	ALLEGRO_DISPLAY* display = al_create_display(windowWidth, windowHeight);
	ALLEGRO_FONT* font = al_create_builtin_font();

	al_clear_to_color(al_map_rgb(0, 0, 0));

	testImage = al_load_bitmap("ship.png");
	background = al_load_bitmap("background1.png");
	enemyShip = al_load_bitmap("enemyShip.png");
	projectileMain = al_load_bitmap("Red_note_.png");
	projectileSide = al_load_bitmap("Green_note.png");
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	backgroundC currentBackground;
	currentBackground.init();

	bool done = false;
	int xMoveSpeedLeft = 0;
	int xMoveSpeedRight = 0;
	int yMoveSpeedUp = 0;
	int yMoveSpeedDown = 0;

	while (!done) {
		ALLEGRO_EVENT events;
		al_wait_for_event_timed(event_queue, &events, 1/60);


		if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (events.keyboard.keycode) {
			case ALLEGRO_KEY_DOWN:
				yMoveSpeedDown = 10;								
				break;
			case ALLEGRO_KEY_UP:
				yMoveSpeedUp = -10;								
				break;
			case ALLEGRO_KEY_LEFT:
				xMoveSpeedLeft = -10;								
				break;
			case ALLEGRO_KEY_RIGHT:
				xMoveSpeedRight = 10;				
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_J:
				spawnEnemy();
				break;
			case ALLEGRO_KEY_Z:
				firing = true;
				break;
			case ALLEGRO_KEY_COMMA:
				currentBackground.speed++;
				
				std::cout << currentBackground.speed << std::endl;
				break;
			case ALLEGRO_KEY_FULLSTOP:
				if (currentBackground.speed > 1) {
					currentBackground.speed--;
				}
				break;
			}
		}
		if (events.type == ALLEGRO_EVENT_KEY_UP) {
			switch (events.keyboard.keycode) {
			case ALLEGRO_KEY_DOWN:
				yMoveSpeedDown = 0;				
				break;
			case ALLEGRO_KEY_UP:
				yMoveSpeedUp = 0;				
				break;
			case ALLEGRO_KEY_LEFT:
				xMoveSpeedLeft = 0;				
				break;
			case ALLEGRO_KEY_RIGHT:
				xMoveSpeedRight = 0;				
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_Z:
				firing = false;
				break;
			}
		}

		if (firing && (frameCount%5==0)) {
			std::vector<int> temp;
			temp.push_back(playerX);
			temp.push_back(playerY);
			temp.push_back(1);
			projectileList.push_back(temp);
			temp[0] = playerX + 80;
			projectileList.push_back(temp);
			temp[0] = playerX + 40;
			temp[1] = playerY - 10;
			temp[2] = 0;
			projectileList.push_back(temp);
		}

		playerX += (xMoveSpeedLeft + xMoveSpeedRight);
		playerY += (yMoveSpeedUp + yMoveSpeedDown);
		currentBackground.draw();
		drawScreen();
		currentBackground.update();
		updateProjectiles();
		updateEnemies();
		al_rest(1.0 / 60);
	}
	

	
	return 0;
}

