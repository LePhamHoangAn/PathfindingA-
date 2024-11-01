#include "Game.h"

game::game()
	:
	column {},
	 row{}
	
{}

void game::grid(tiles& t, Screen& screen)
{
	for (int i = 0; i < t.x; i = i++)
		for (int j = 0; j < t.y; j = j++)
		{
			screen.DrawRectangle(i * t.size, j * t.size, 20, 20, 220, 220, 220, 100);
		}
}
void game::grid2(tiles& t, Screen& screen)
{
	for (int i = 0; i < gridsize; i++)
	{
		column[i] = i * t.size;
		row[i] = i * t.size;	
	}
}

void game::drawsnek(snake& snake, Screen& screen)
{
	snake.part(column[snake.colindex], row[snake.rowindex], screen);

	if (snake.count > 0)
	{
		for (int i = 1; i <= snake.count; i++)
		{
			snake.part(column[snake.curpositions[i].x], row[snake.curpositions[i].y], screen);
			
		}
	}
}

void game::applecollision(snake& s,apple& a, Screen& screen)
{
	if ((s.colindex == a.ax  ) && (s.rowindex == a.ay ))
	{
		s.count++;
	
		a.ax = rand() % (20 -  2);
		a.ay = rand() % (20 -  2);
		if (s.colindex == a.ax || s.rowindex == a.ay)
		{
			a.ax = rand() % (20 - 2);
			a.ay = rand() % (20 - 2);
		}
		a.count = a.count + 1;

		s.gettinglong(screen);
	}	
}

void game::update(snake& sna,tiles& ti,apple&app, Screen& screen)
{
	
	if (over==false)
	{
		grid(ti, screen);
		grid2(ti, screen);

		sna.movement(screen);
		applecollision(sna, app, screen);
		drawsnek(sna, screen);
		app.appledraw(column[app.ax], row[app.ay], screen);
		if ((sna.colindex > ti.x) || (sna.colindex < 0) || (sna.rowindex > ti.y) || (sna.rowindex < 0))
		{
			over = true;
		}
		killself(sna, ti, screen);
	}
	else
	{
		gameover(sna,ti,screen);
	}
}

void game::gameover(snake& s,tiles& t, Screen& screen)
{
	screen.DrawText(700 / 3, 20, 255, 0, 0, 255, "YOU LOSE!!!!!!!!!!!");
}

void game::killself(snake& s, tiles& t, Screen& screen)
{
	for (int i = 1; i <= s.count; i++)
	{
		if (s.curpositions[0].x == s.curpositions[i].x && s.curpositions[0].y == s.curpositions[i].y)
		{
			over = true;
		}
	}
}

