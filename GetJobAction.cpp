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
	((Zwerg*)agent)->job = World::getJob();

	logMessage = "Found work";
}
