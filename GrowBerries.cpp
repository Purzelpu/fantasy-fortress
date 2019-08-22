#include "TakeBerries.hpp"
#include "World.hpp"
#include "Bush.hpp"
#include "GrowBerries.hpp"
#include <iostream>
#include <sstream>

bool GrowBerries::isValid()
{
	//TODO: Check if adjacent
	return agent != nullptr && static_cast<Busch*>(agent) -> beeren < 5; 
}

void GrowBerries::execute()
{
	Busch* bagent = static_cast<Busch*>(agent);
	if(!isValid())
	{
		//Throw?
		return;
	}
	if(bagent -> stage == 15)
	{
		(bagent)-> beeren++;
		bagent -> stage = 0;
		logMessage = "fully grown";
	}
	else
	{
		bagent -> stage++;
		std::stringstream msgstream;
		msgstream << "Growing:   " << +bagent->stage;
		logMessage = msgstream.str();
	}

}
