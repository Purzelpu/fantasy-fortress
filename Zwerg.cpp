#include <vector>
#include <deque>
#include <iostream>
#include "Zwerg.hpp"
#include "Bush.hpp"
#include "World.hpp"
#include "Move.hpp"

void Zwerg::tick()
{
	hunger++;
	if(hunger < 10)
	{
		int dx = std::rand() % 3  - 1 ;
		int dy = std::rand() % 3 - 1;
		World::registerAction(new Move(this, coord, {coord.x+dx, coord.y+dy}));
	}
	else
	{
		std::vector<coordinate> food = findNextFood(coord);
		if(food.empty()) return; //No food found :( Do nothing. 
		if(food.size() > 1)
		{
			coordinate step = food.back();
			World::registerAction(new Move(this, coord, step));
		}
		if(food.size() == 1)
		{
			coordinate bush_coord = food.back();
			Object* busch = World::getObjectAt(bush_coord);
			if(busch->isEdible() && ((Busch*)busch)->hatBeeren())
			{
				((Busch*)busch)->nimmBeeren();
				hunger = 0;
			}
		}

	}
}


//Use flood fill to find the bush closest to (x,y).
std::vector<coordinate> findNextFood(coordinate root)
{
	std::vector<coordinate> path;

	coordinate came_from[BREIT][HOCH];
	for(unsigned int i=0;i<BREIT;i++)
		for(unsigned int j=0;j<HOCH;j++)
		{
			//This can not happen
			came_from[i][j] = {BREIT+1, HOCH+1};
		}

	std::deque<coordinate> frontier;
	frontier.push_front(root);
	came_from[root.x][root.y] = root;
	coordinate expand;

	while(!frontier.empty())
	{
		expand = frontier.back();
		frontier.pop_back();
		//std::cout << "Expanding " << expand.x << " " << expand.y << std::endl;
		if (World::getObjectAt(expand) != nullptr && World::getObjectAt(expand)->isEdible())
		{
			//std::cout << "Found something @" << expand.x << " " << expand.y << std::endl;
			break;
		}
		else
		{
			unsigned int x = expand.x;
			unsigned int y = expand.y;
			//coordinates are unsigned -> 0-1 = BIG
			if(x-1 < BREIT && came_from[x-1][y] == coordinate({BREIT+1, HOCH+1})) 
			{
				frontier.push_front({x-1,y});
				came_from[x-1][y] = {x,y};
				//std::cout << "Added " << x-1 << " " << y << std::endl;
			}
			if(y-1 < HOCH && came_from[x][y-1] == coordinate({BREIT+1, HOCH+1}))
			{
				frontier.push_front({x,y-1});
				came_from[x][y-1] = {x,y};
				//std::cout << "Added " << x << " " << y-1 << std::endl;
			}
			if(x+1 < BREIT && came_from[x+1][y] == coordinate({BREIT+1, HOCH+1}))
			{
				frontier.push_front({x+1, y});
				came_from[x+1][y] = {x,y};
				//std::cout << "Added " << x+1 << " " << y << std::endl;
			}
			if(y+1 < HOCH && came_from[x][y+1] == coordinate({BREIT+1, HOCH+1}))
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
