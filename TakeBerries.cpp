#include "TakeBerries.hpp"
#include "World.hpp"
#include "Bush.hpp"
#include <iostream>

bool TakeBerries::isValid()
{
	//TODO: Check if adjacent
	return berries->isEdible() && ((Busch*)berries) -> hatBeeren(); 
}

void TakeBerries::execute()
{
	if(!isValid())
	{
		//Throw?
		return;
	}
	((Busch*)berries)->nimmBeeren();
	((Zwerg*)agent)->hunger = 0;

	logMessage = "Eating";
}
