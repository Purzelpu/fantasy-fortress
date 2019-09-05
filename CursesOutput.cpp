#include <curses.h>
#include <iostream>
#include <cstdlib>
#include "World.hpp"
#include "CursesOutput.hpp"
#include "Coordinate.hpp"

extern World world;

CursesOutput::~CursesOutput()
{
	delwin(window_world);
	delwin(window_log);
	delwin(logBorder);
	endwin();
}

CursesOutput::CursesOutput()
{
	initscr();
	clear();
	curs_set(0);

	window_world = newwin(HOCH+2, BREIT+2, 1,1);
	logBorder = newwin(7, 52, HOCH+4, 1);
	window_log = derwin(logBorder, 5, 50, 1,1);
	scrollok(window_log, TRUE);
	box(window_world,0,0);
	box(logBorder,0,0);
	wrefresh(logBorder);
}

void CursesOutput::curses_output()
{
	for(unsigned int x=0;x<BREIT;++x)
	for(unsigned int y=0;y<HOCH;++y)
	{
		if(world[{x,y}] == nullptr)
		{
			mvwaddch(window_world,y+1,x+1,'.');
		}
		else
		{
			mvwaddch(window_world, y+1,x+1, (world[{x,y}] -> getSymbol())) ;
		}
	}
	wrefresh(window_world);
}

void CursesOutput::writeLog(std::string message)
{
	//scroll(log);
	waddstr(window_log, message.c_str());
	waddstr(window_log, "\n");
	wrefresh(window_log);
}
