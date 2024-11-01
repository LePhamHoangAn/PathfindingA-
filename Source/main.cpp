//Name: Pham Hoang An Le
//date of delivery(dd/mm/yyyy):05/12/2021


#include "Screen.h"
#include "Snake.h"
#include "Apple.h"
#include "Game.h"
int screenWidth = 700;
int screenHeight = 700;


/* 
Galba v1.4
DrawPixelColor		-> renamed DrawPixel as an overloaded function
DrawCircleColor		-> renamed DrawCircle as an overloaded function
DrawRectangleColor	-> renamed DrawRectangle as an overloaded function

unsigned char a; for Alpha (255 = no transparency) added to the Color struct, draw functions taking unsigned char r,g,b now takes unsigned char r,g,b,a

*/

int main(int argc, char** argv)
{
	tiles ti;
	snake sna;
	apple app;
	game g;
	
	
	Screen screen(screenWidth, screenHeight, "Galba");
	
 	while (screen.IsOpen())
	{	
		screen.Clear();
		
		g.update(sna, ti, app, screen);

		screen.Display();
	}
	return 0;
}