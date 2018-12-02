#pragma once

#include "Object.hpp"

class Busch : public Object
{
	private:
	unsigned char beeren=0;
	unsigned char count=0;

	public:
	Busch(coordinate c) : Object(c) {}

	void tick();

	bool hatBeeren();

	void nimmBeeren();

	virtual char getSymbol();

	virtual bool isEdible();
};
