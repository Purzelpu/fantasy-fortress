#include "Move.hpp"
#include "World.hpp"
#include <iostream>

bool Move::isValid()
{
	return World::isValid(from) && World::isValid(to) && World::getObjectAt(from) == agent && World::getObjectAt(to) == nullptr;
}

void Move::execute()
{
	if(!isValid())
	{
		//Throw?
		return;
	}

	std::swap(World::feld[from.x][from.y], World::feld[to.x][to.y]);
	agent->coord = to;
	logMessage = "Moving";
}
