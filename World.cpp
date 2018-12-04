#include "World.hpp"
#include "Zwerg.hpp"
#include "Bush.hpp"

	Object* World::feld[BREIT][HOCH] = {nullptr};

void World::init()
{
	feld[3][3] = new Busch({3,3});
	feld[7][7] = new Zwerg({7,7});
	feld[4][5] = new Busch({4,5});
}

void World::tick()
{
	for(unsigned int i=0;i<HOCH;i++)
		for(unsigned int j=0;j<BREIT;j++)
		{
			if(feld[j][i] != nullptr)
			{
				feld[j][i] -> tick();
			}
		}

}


coordinate World::move(coordinate from, coordinate to)
{
	//Bereich
	if(to.x >= BREIT || to.y >= HOCH)
	{
		return from;
		//throw exception?
	}

	//Besetzt
	if(feld[to.x][to.y] != nullptr)
	{
		return from;
		//throw ex? 
	}

	//std::cout << "Move to " << to.x << " " << to.y << std::endl;
	std::swap(feld[from.x][from.y], feld[to.x][to.y]);
	return to;
}
