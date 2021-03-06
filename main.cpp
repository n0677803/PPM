#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <string>
#include <iostream>
#include <cmath>
#include "enemys.h"

ALLEGRO_BITMAP *testImage, *background, *enemyShip, *projectileMain, *projectileSide;
int playerX, playerY, frameCount, windowWidth, windowHeight;
ALLEGRO_KEYBOARD_STATE *keyboardState;
std::vector<enemyClass> enemyList;

std::vector<std::vector<int>> projectileList;
std::vector<std::vector<int>> otherElementsList;
bool firing = false;



class backgroundC {
protected:
	int x, y; 
public:
	float speed;

	void draw() {
		al_draw_bitmap(background, x, y, 0);
		if (y>windowHeight) {
			y = -(2000 - windowHeight); // if off screen move back up to teselate

			
		}
		else if (y > 0) {
			al_draw_bitmap(background, 0, y-2000, 0);//draws teserlated background when main partially off screen
		}		
	}
	void update() {
		y += speed;//moves background down screen
		
	}

	void init() {
		x = 0;
		y = 0;
		speed = 1;
	}
};

float distanceBetween(int x1, int y1, int x2, int y2) {
	return sqrt((pow((x2 - x1),2)) + (pow((y2 - y1),2)));
}

void hitDetectionEnemysPlayerProjectiles() {
	for (int i = 0; i < enemyList.size(); i++) {
		for (int j = 0; j < projectileList.size(); j++) {
			if (distanceBetween(enemyList[i].x,enemyList[i].y,projectileList[j][0],projectileList[j][1])<15) {
				projectileList.erase(projectileList.begin()+j);
				enemyList.erase(enemyList.begin()+i);
				break;
			}
		}
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
	for (int i = 0; i < enemyList.size(); i++) {
		enemyList[i].draw();
		enemyList[i].update();
	}
	
	drawProjectiles();
	al_draw_bitmap(testImage, playerX, playerY, 0);
	al_flip_display();
	al_clear_depth_buffer(0);
	frameCount++;
}

void updateProjectiles() {
	for (int i = 0; i < projectileList.size(); i++) {
		if (projectileList[i][1] < -100) {
			projectileList.erase(projectileList.begin() + i); //removed from list if too far off screen
		}
		else {
			projectileList[i][1] -= 10;
		}
	}
}


int main()
{
	al_init(); // initilisations
	al_init_font_addon();
	al_init_image_addon();
	al_install_keyboard();
	windowHeight = 600;
	windowWidth = 800;

	ALLEGRO_DISPLAY* display = al_create_display(windowWidth, windowHeight);
	ALLEGRO_FONT* font = al_create_builtin_font();

	al_clear_to_color(al_map_rgb(0, 0, 0));

	testImage = al_load_bitmap("ship.png"); // load images to sprites
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

	while (!done) { //user input handling
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
			case ALLEGRO_KEY_J: // test key for enemy spawn
				
				break;
			case ALLEGRO_KEY_L:
				enemyClass temp;
				temp.init(1, 1, -50, -30, 0.01, 2,enemyShip);
				enemyList.push_back(temp);

				//test key for class list
				break;
			case ALLEGRO_KEY_Z:
				firing = true;
				break;
			case ALLEGRO_KEY_COMMA:
				currentBackground.speed++;
				
				//std::cout << currentBackground.speed << std::endl;
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

		if (firing && (frameCount%5==0)) { //fires every 5 frames
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

		playerX += (xMoveSpeedLeft + xMoveSpeedRight);//updates player position
		playerY += (yMoveSpeedUp + yMoveSpeedDown);
		currentBackground.draw();//other updates
		
		drawScreen();
		currentBackground.update();
		hitDetectionEnemysPlayerProjectiles();
		updateProjectiles();
		

		al_rest(1.0 / 60);//framerate limiter
	}
	

	
	return 0;
}

