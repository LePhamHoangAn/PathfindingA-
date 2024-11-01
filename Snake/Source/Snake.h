#pragma once
#include<iostream>
#include "screen.h"



class snake
{
	struct bodypart { int x = 0; int y = 0; };


	int dirx;
	int diry;


	 int headheight;
	 int headwidth;

	bool vertical;


	int step;

public:
	bodypart curpositions[700];
	bodypart prepositions[700];

	int count;

	int colindex;
	int rowindex;

	int x=0;
	int y=0;
    
	snake();
	int speed = 5;
	void movement(Screen& screen);
	void part(int nx,int ny, Screen& screen);
	
	void gettinglong(Screen& screen);
};
