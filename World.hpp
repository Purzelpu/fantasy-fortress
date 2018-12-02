#pragma once

#include "Object.hpp"
#include <iostream>


const unsigned int HOCH = 10;
const unsigned int BREIT = 10;

class World{
	public:
	static Object* feld[BREIT][HOCH];
	static coordinate move(coordinate, coordinate);
	static void init();
	static void tick();
};

