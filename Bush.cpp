#include <iostream>
#include "Bush.hpp"

	void Busch::tick()
	{
		count++;
		if(count==5)
		{
			std::cout << count;
			count = 0;
			if(beeren < 5)
			{
				beeren++;
			}
		}
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
