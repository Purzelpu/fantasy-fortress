#include <curses.h>
#include <iostream>
#include <cstdlib>
#include "World.hpp"

void curses_end()
{
	endwin();
}

void curses_init()
{
	initscr();
	curs_set(0);
	std::atexit(curses_end);
}

void curses_output()
{
	for(unsigned int x=0;x<BREIT;++x)
	for(unsigned int y=0;y<HOCH;++y)
	{
		if(World::feld[x][y] == nullptr)
		{
			mvaddch(y,x,'.');
		}
		else
		{
			mvaddch(y,x,World::feld[x][y] -> getSymbol());
		}
		refresh();
	}
}

