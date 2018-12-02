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

	World::init();
	
	while(true)
	{
		World::tick();
		curses_output();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	return 0;
}
