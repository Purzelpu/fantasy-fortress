#include "World.hpp"
#include "Dwarf.hpp"
#include "Bush.hpp"

void World::init()
{

	feld[3][3] = new Bush({3,3});
	feld[7][7] = new Dwarf({7,7});
	feld[11][5] = new Bush({11,5});

	World::registerJob(new Job({10, 9},7));
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
		a->execute();
		delete a;
		output.writeLog(a -> logMessage);
	}
	action_queue.clear();

	output.curses_output();
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

void World::registerAction(Action* a)
{
	action_queue.push_back(a);
}

void World::registerJob(Job* job)
{
	job_queue.push_back(job);
}

bool World::hasJobs()
{
	return !job_queue.empty();
}

Job* World::getJob()
{
	Job* j = job_queue.back();
	job_queue.pop_back();
	return j;
}
