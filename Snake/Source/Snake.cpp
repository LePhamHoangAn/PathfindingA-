
#include "Snake.h"



snake::snake()
	:
	dirx{ 1 },
	diry{ 1 },

	colindex{ 0 },
	rowindex{ 0 },

	headheight{ 20 },
	headwidth{ 20 },

	count{0},
	curpositions{ {0, 0} },
	prepositions{ {0, 0} },


	 step{ 5 },

	vertical{ true }
{
}

void snake::movement(Screen& screen)
{
	prepositions[0].x = colindex;
	prepositions[0].y = rowindex;

	if (step % 5 == 0)
	{
		if (vertical == true)
		{
			rowindex += 1 * dirx;

			if (screen.IsKeyDown(Key::Right))
			{
				diry = +1;
				vertical = false;
			}

			else if (screen.IsKeyDown(Key::Left))
			{
				diry = -1;
				vertical = false;
			}
		}
		else
		{
			colindex += 1 * diry;
			if (screen.IsKeyDown(Key::Down))
			{
				dirx = 1;
				vertical = true;

			}

			else if (screen.IsKeyDown(Key::Up))
			{
				dirx = -1;
				vertical = true;
			}
			
		}


		curpositions[0].x = colindex;
		curpositions[0].y = rowindex;

		

		gettinglong(screen);
	}

	step++;
}

void snake::gettinglong(Screen& screen)
{
		for (int i = 1; i <= count; i++)
		{
		
			prepositions[i].x = curpositions[i].x;
			prepositions[i].y = curpositions[i].y;

			curpositions[i].x = prepositions[i - 1].x;
			curpositions[i].y = prepositions[i - 1].y;

		}
}

void snake::part(int nx, int ny, Screen& screen)
{
	screen.DrawRectangle(nx, ny, 20, 20,0,255,0,255);
}