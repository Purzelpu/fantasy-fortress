#include <iostream>
#include "Bush.hpp"
#include "World.hpp"
#include "GrowBerries.hpp"

	void Bush::tick()
	{
		World::registerAction(new GrowBerries(this));
	}

	char Bush::getSymbol()
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

	bool Bush::hatBeeren()
	{
		return beeren>0;
	}

	void Bush::nimmBeeren()
	{
		beeren = 0;
	}

	bool Bush::isEdible()
	{
		return hatBeeren();
	}
