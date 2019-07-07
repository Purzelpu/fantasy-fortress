#pragma once

#include "Object.hpp"
#include <iostream>
#include <vector>
#include "Action.hpp"


const unsigned int HOCH = 20;
const unsigned int BREIT = 30;

class World{
	public:
	static Object* feld[BREIT][HOCH];
	static Object* getObjectAt(coordinate& c);
	static bool isValid(const coordinate&);
	static void init();
	static void tick();
	static void registerAction(Action* action);

	static std::vector<Action*> action_queue;
};

