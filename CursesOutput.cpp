#include <curses.h>
#include <iostream>
#include <cstdlib>
#include "World.hpp"
#include "CursesOutput.hpp"

CursesOutput::~CursesOutput()
{
	delwin(world);
	delwin(log);
	delwin(logBorder);
	endwin();
}

CursesOutput::CursesOutput()
{
	initscr();
	clear();
	curs_set(0);

	world = newwin(HOCH+2, BREIT+2, 1,1);
	logBorder = newwin(7, 52, HOCH+4, 1);
	log = derwin(logBorder, 5, 50, 1,1);
	scrollok(log, TRUE);
	box(world,0,0);
	box(logBorder,0,0);
	wrefresh(logBorder);
}

void CursesOutput::curses_output()
{
	for(unsigned int x=0;x<BREIT;++x)
	for(unsigned int y=0;y<HOCH;++y)
	{
		if(World::feld[x][y] == nullptr)
		{
			mvwaddch(world,y+1,x+1,'.');
		}
		else
		{
			mvwaddch(world, y+1,x+1,World::feld[x][y] -> getSymbol());
		}
	}
	wrefresh(world);
}

void CursesOutput::writeLog(std::string message)
{
	//scroll(log);
	waddstr(log, message.c_str());
	waddstr(log, "\n");
	wrefresh(log);
}
