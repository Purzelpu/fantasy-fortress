#pragma once
#include <ncurses.h>
#include <string>

class CursesOutput {
public : 
	CursesOutput();
	~CursesOutput();
	void curses_output();
	void writeLog(std::string);
private:
	WINDOW* window_world;
	WINDOW* window_log;
	WINDOW* logBorder;
};
