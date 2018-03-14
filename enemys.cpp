#include <cmath>
#include <iostream>
#include "enemys.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

void enemyClass::draw() {
	al_draw_bitmap(enemySprite,x+xOffSet,y+yOffSet,0);
	}

void enemyClass::init(int tempx, int tempy, int tempOffx, int tempOffy, float tempgradient, int temppower, ALLEGRO_BITMAP *tempimage) {
	x = tempx;
	y = tempy;
	xOffSet = tempOffx;
	yOffSet = tempOffy;
	gradient = tempgradient;
	power = temppower;
	enemySprite = tempimage;
}

void enemyClass::update() {
	x += 1;
	y = gradient*(pow(x, power));

}

