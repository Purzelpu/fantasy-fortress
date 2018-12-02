#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stdlib.h>
#include <chrono>
#include <thread>

#include "Object.hpp"
#include "Bush.hpp"
#include "Zwerg.hpp"
#include "World.hpp"
#include "curses_output.h"






int main(int argc, char** argv)
{
	curses_init();

	for(unsigned int i=0;i<BREIT;i++)
		for(unsigned int j=0;j<HOCH;j++)
		{
			feld[i][j] = nullptr;
		}
	feld[3][3] = new Busch({3,3});
	feld[7][7] = new Zwerg({7,7});
	feld[4][5] = new Busch({4,5});
	
	while(true)
	{
		//loop
		for(unsigned int i=0;i<HOCH;i++)
			for(unsigned int j=0;j<BREIT;j++)
			{
				if(feld[j][i] != nullptr)
				{
					feld[j][i] -> tick();
				}
			}

		curses_output();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	return 0;
}
