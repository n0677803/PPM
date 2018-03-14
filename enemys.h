//#pragma once
#ifndef ENEMYS_H
#define ENEMYS_H

#include <cmath>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


class enemyClass {
public:
	int x, y, power, xOffSet, yOffSet;
	float gradient;
	ALLEGRO_BITMAP *enemySprite;

public:
	void draw();
	void update();
	void init(int tempx, int tempy, int tempOffx, int tempOffy, float tempgradient, int temppower, ALLEGRO_BITMAP *tempimage);


};

#endif