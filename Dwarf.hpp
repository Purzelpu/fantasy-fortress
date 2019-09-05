#pragma once

#include <vector>
#include "World.hpp"
#include "Object.hpp"
#include "Job.hpp"

class Dwarf : public Object
{
	friend class TakeBerries;
	friend class GetJobAction;
	friend class Work;
	protected:
		unsigned char hunger = 0;
		Job* job = nullptr;

	public:
		Dwarf(Coordinate c) : Object(c) {}
		void tick();

		char getSymbol() {
			return (hunger<10) ? 'Z' : 'z';
		}
};

std::vector<Coordinate> findNextFood(Coordinate);
