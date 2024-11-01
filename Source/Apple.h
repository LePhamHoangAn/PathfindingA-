#pragma once
#include "screen.h"
#include "Snake.h"


class apple
{
public:
	int count = 0;
private:
	int ah ;
	int aw ;
	

public:
	int ax = 28;
	int ay=0;
	bool alive = true;
	apple();
	
	void appledraw(int nx, int ny, Screen& screen);
	
};