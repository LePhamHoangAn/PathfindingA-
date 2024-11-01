#include <iostream>
#include "Apple.h"
#include "Snake.h"

apple::apple()
	:ah{20},
	
	aw{ 20 },

 ax  {rand() % (20 - 2)},
 ay  {rand() % (20 - 2)},

	 alive{ true }
{}

void apple::appledraw(int nx, int ny, Screen& screen)
{
	screen.DrawRectangle(nx, ny, 20, 20,255,0,0,255);
}


