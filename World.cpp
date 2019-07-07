#include "World.hpp"
#include "Zwerg.hpp"
#include "Bush.hpp"
#include <iostream>

Object* World::feld[BREIT][HOCH] = {nullptr};
std::vector<Action*> World::action_queue;

void World::init()
{
	feld[3][3] = new Busch({3,3});
	feld[7][7] = new Zwerg({7,7});
	feld[11][5] = new Busch({11,5});
}

void World::tick()
{
	//Planning
	for(unsigned int i=0;i<HOCH;i++)
		for(unsigned int j=0;j<BREIT;j++)
		{
			if(feld[j][i] != nullptr)
			{
				feld[j][i] -> tick();
			}
		}
	
	//Acting
	for(Action* a : action_queue)
	{
		std::cout << "action" << std::endl;
		a->execute();
		delete a;
	}
	action_queue.clear();

}

bool World::isValid(const coordinate& c)
{
	return (c.x <= BREIT) && (c.y <=HOCH);
}

Object* World::getObjectAt(coordinate& c)
{
	//Check coordinates
	return feld[c.x][c.y];
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
	if(getObjectAt(to) != nullptr)
	{
		return from;
		//throw ex? 
	}

	//std::cout << "Move to " << to.x << " " << to.y << std::endl;
	std::swap(feld[from.x][from.y], feld[to.x][to.y]);
	return to;
}

void World::registerAction(Action* a)
{
	std::cout << "Register " <<std::endl;
	action_queue.push_back(a);
}
