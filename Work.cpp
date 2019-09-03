#include "Work.hpp"
#include "World.hpp"
#include <iostream>
#include <sstream>

bool Work::isValid()
{
	return job != nullptr && agent != nullptr;
}

void Work::execute()
{
	if(!isValid())
	{
		//Throw?
		logMessage = "can't work";
		return;
	}

	if (!job -> isDone())
	{
		std::stringstream logStream;
		job -> progress++;
		logStream << "working " << job->progress << "/" << job->hardness;
		logMessage = logStream.str();
	}

	if(job -> isDone())
	{
		logMessage = "Job done";
		Zwerg* z = static_cast<Zwerg*>(agent);
		z -> job = nullptr;
		delete job;
	}
}
