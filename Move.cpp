#include "Move.hpp"
#include "World.hpp"
#include <iostream>

extern World world;

bool Move::isValid()
{
	return world.isValid(from) && world.isValid(to) && world.getObjectAt(from) == agent && world.getObjectAt(to) == nullptr;
}

void Move::execute()
{
	if(!isValid())
	{
		//Throw?
		logMessage = "can't move";
		return;
	}

	std::swap(world.feld[from.x][from.y], world.feld[to.x][to.y]);
	agent->coord = to;
	logMessage = "Moving";
}
