#pragma once

#include "Object.hpp"

class Bush : public Object
{
	friend class GrowBerries;
	protected:
		unsigned char beeren=0;
		unsigned char stage = 0;

	public:
	Bush(Coordinate c) : Object(c) {}

	void tick();

	bool hatBeeren();

	void nimmBeeren();

	virtual char getSymbol();

	virtual bool isEdible();
};
