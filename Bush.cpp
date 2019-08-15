#include <iostream>
#include "Bush.hpp"
#include "World.hpp"
#include "GrowBerries.hpp"

	void Busch::tick()
	{
		World::registerAction(new GrowBerries(this));
	}

	char Busch::getSymbol()
	{
		if(beeren == 0)
		{
			return 'b';
		}
		else
		{
			return 'B';
		}
	}

	bool Busch::hatBeeren()
	{
		return beeren>0;
	}

	void Busch::nimmBeeren()
	{
		beeren = 0;
	}

	bool Busch::isEdible()
	{
		return hatBeeren();
	}
