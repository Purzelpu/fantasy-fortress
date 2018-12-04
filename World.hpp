#pragma once

#include "Object.hpp"
#include <iostream>


const unsigned int HOCH = 20;
const unsigned int BREIT = 30;

class World{
	public:
	static Object* feld[BREIT][HOCH];
	static coordinate move(coordinate, coordinate);
	static void init();
	static void tick();
	static Object* getObjectAt(coordinate& c);
};

