#pragma once

#include "Object.hpp"

class Busch : public Object
{
	friend class GrowBerries;
	protected:
		unsigned char beeren=0;
		unsigned char stage = 0;

	public:
	Busch(coordinate c) : Object(c) {}

	void tick();

	bool hatBeeren();

	void nimmBeeren();

	virtual char getSymbol();

	virtual bool isEdible();
};
