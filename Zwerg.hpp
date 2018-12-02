#pragma once

#include <vector>

#include "World.hpp"
#include "Object.hpp"

class Zwerg : public Object
{
	private:
		unsigned char hunger;
	public:
		Zwerg(coordinate c) : Object(c) {}
		void tick();

		char getSymbol() {
			return 'Z';
		}
};

coordinate move(coordinate, coordinate);
std::vector<coordinate> findNextFood(coordinate);
