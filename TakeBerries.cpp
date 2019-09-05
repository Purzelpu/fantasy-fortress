#include "TakeBerries.hpp"
#include "World.hpp"
#include "Bush.hpp"
#include <iostream>

bool TakeBerries::isValid() const
{
	//TODO: Check if adjacent
	return berries->isEdible() && ((Bush*)berries) -> hatBeeren(); 
}

void TakeBerries::execute()
{
	if(!isValid())
	{
		//Throw?
		return;
	}
	((Bush*)berries)->nimmBeeren();
	((Dwarf*)agent)->hunger = 0;

	logMessage = "Eating";
}
