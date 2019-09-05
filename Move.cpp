#include "Move.hpp"
#include "World.hpp"
#include <iostream>

extern World world;

bool Move::isValid()
{
	return world.isValid(from) && world.isValid(to) && world[from] == agent && world[to] == nullptr;
}

void Move::execute()
{
	if(!isValid())
	{
		//Throw?
		logMessage = "can't move";
		return;
	}

	std::swap(world[from], world[to]);
	agent->coord = to;
	logMessage = "Moving";
}
