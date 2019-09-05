#include "GetJobAction.hpp"
#include "World.hpp"
#include <iostream>

extern World world;

bool GetJobAction::isValid()
{
	//TODO: Check if adjacent
	return world.hasJobs();
}

void GetJobAction::execute()
{
	if(!isValid())
	{
		//Throw?
		return;
	}
	((Dwarf*)agent)->job = world.getJob();

	logMessage = "Found work";
}
