#pragma once

#include <vector>

#include "World.hpp"
#include "Object.hpp"

class Zwerg : public Object
{
	protected:
		unsigned char hunger;
	friend class TakeBerries;
	public:
		Zwerg(coordinate c) : Object(c) {}
		void tick();

		char getSymbol() {
			return (hunger<10) ? 'Z' : 'z';
		}
};

std::vector<coordinate> findNextFood(coordinate);
