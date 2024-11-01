#pragma once

#include <iostream>
#include "screen.h"
#include "Snake.h"
#include "Apple.h"

struct tiles
{
	int x = 28;
	int y = 28;
	int size = 25;
	int width = size * x;
	int height = size * y;
};

class game
{
	const static int gridsize = 700;
	
	
public:
	int column[gridsize];
	int row[gridsize];
	bool over = false;
	game();
	void grid(tiles& t, Screen& screen);
	void grid2(tiles& t, Screen& screen);
	void applecollision(snake& s, apple& a, Screen& screen);
	void drawsnek(snake& snake, Screen& screen);
	void gettinglong(snake& s, apple& a, Screen& screen);
	void gameover(snake& s, tiles& t, Screen& screen);
	void update(snake& sna, tiles& ti, apple& app, Screen& screen);
	void killself(snake& s, tiles& t, Screen& screen);

	
};
