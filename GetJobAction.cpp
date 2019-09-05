#include "GetJobAction.hpp"
#include "World.hpp"
#include <iostream>

bool GetJobAction::isValid()
{
	//TODO: Check if adjacent
	return World::hasJobs();
}

void GetJobAction::execute()
{
	if(!isValid())
	{
		//Throw?
		return;
	}
	((Dwarf*)agent)->job = World::getJob();

	logMessage = "Found work";
}
