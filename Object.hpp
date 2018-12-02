#pragma once 
#include "Coordinate.hpp"

class Object
{
	public:
	coordinate coord;
	virtual void tick() = 0;
	virtual char getSymbol() = 0;
	virtual bool isEdible()
	{
		return false;
	}

	Object(coordinate c) : coord(c) {}

};
