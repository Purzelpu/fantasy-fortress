#include <vector>
#include <deque>
#include <iostream>
#include "Dwarf.hpp"
#include "Bush.hpp"
#include "World.hpp"
#include "Move.hpp"
#include "Work.hpp"
#include "GetJobAction.hpp"
#include "TakeBerries.hpp"

extern World world;

void Dwarf::tick()
{
	hunger++;
	if(hunger < 10)
	{
		if(job != nullptr)
		{
			//if not near job: move there
			if(job->location.x > coord.x)
			{
				world.registerAction(new Move(this, coord, {coord.x+1,coord.y}));
			}
			else if(job->location.x < coord.x)
			{
				world.registerAction(new Move(this, coord, {coord.x-1,coord.y}));
			}
			else if(job->location.y < coord.y)
			{
				world.registerAction(new Move(this, coord, {coord.x,coord.y-1}));
			}
			else if(job->location.y > coord.y)
			{
				world.registerAction(new Move(this, coord, {coord.x,coord.y+1}));
			}

			if (job->location == coord)
			{
				world.registerAction(new Work(this, job));
			}
		}
		else
		{
			if(world.hasJobs())
			{
				world.registerAction(new GetJobAction(this));
			}
			else
			{
				//Wander aimlessly
				int dx = std::rand() % 3  - 1 ;
				int dy = std::rand() % 3 - 1;
				world.registerAction(new Move(this, coord, {coord.x+dx, coord.y+dy}));
			}
		}
	}
	//Find food
	else
	{
		std::vector<Coordinate> food = findNextFood(coord);
		if(food.empty()) return; //No food found :( Do nothing. 
		if(food.size() > 1)
		{
			Coordinate step = food.back();
			world.registerAction(new Move(this, coord, step));
		}
		if(food.size() == 1)
		{
			Coordinate bush_coord = food.back();
			Object* bush = world[bush_coord];
			world.registerAction(new TakeBerries(this, coord, bush));
		}
	}
}


//Use flood fill to find the bush closest to (x,y).
std::vector<Coordinate> findNextFood(Coordinate root)
{
	std::vector<Coordinate> path;

	Coordinate came_from[BREIT][HOCH];
	for(unsigned int i=0;i<BREIT;i++)
		for(unsigned int j=0;j<HOCH;j++)
		{
			//This can not happen
			came_from[i][j] = {BREIT+1, HOCH+1};
		}

	std::deque<Coordinate> frontier;
	frontier.push_front(root);
	came_from[root.x][root.y] = root;
	Coordinate expand;

	while(!frontier.empty())
	{
		expand = frontier.back();
		frontier.pop_back();
		//std::cout << "Expanding " << expand.x << " " << expand.y << std::endl;
		if (world[expand] != nullptr && world[expand]->isEdible())
		{
			//std::cout << "Found something @" << expand.x << " " << expand.y << std::endl;
			break;
		}
		else
		{
			unsigned int x = expand.x;
			unsigned int y = expand.y;
			//Coordinates are unsigned -> 0-1 = BIG
			if(x-1 < BREIT && came_from[x-1][y] == Coordinate({BREIT+1, HOCH+1})) 
			{
				frontier.push_front({x-1,y});
				came_from[x-1][y] = {x,y};
				//std::cout << "Added " << x-1 << " " << y << std::endl;
			}
			if(y-1 < HOCH && came_from[x][y-1] == Coordinate({BREIT+1, HOCH+1}))
			{
				frontier.push_front({x,y-1});
				came_from[x][y-1] = {x,y};
				//std::cout << "Added " << x << " " << y-1 << std::endl;
			}
			if(x+1 < BREIT && came_from[x+1][y] == Coordinate({BREIT+1, HOCH+1}))
			{
				frontier.push_front({x+1, y});
				came_from[x+1][y] = {x,y};
				//std::cout << "Added " << x+1 << " " << y << std::endl;
			}
			if(y+1 < HOCH && came_from[x][y+1] == Coordinate({BREIT+1, HOCH+1}))
			{
				frontier.push_front({x,y+1});
				came_from[x][y+1] = {x,y};
				//std::cout << "Added " << x << " " << y+1 << std::endl;
			}
		}
	}

	do{
		path.push_back(expand);
	} while((expand = came_from[expand.x][expand.y]) != root);

	return path;
}
