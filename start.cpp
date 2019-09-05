#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stdlib.h>
#include <chrono>
#include <thread>

#include "Object.hpp"
#include "Bush.hpp"
#include "Dwarf.hpp"
#include "World.hpp"
#include "CursesOutput.hpp"





World world;

int main(int argc, char** argv)
{

	world.init();
	
	while(true)
	{
		world.tick();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	return 0;
}
