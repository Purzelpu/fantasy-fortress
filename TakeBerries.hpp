#pragma once
#include "Action.hpp"
#include "Coordinate.hpp"
#include "Zwerg.hpp"

class TakeBerries: public Action {
	public:
		TakeBerries(Zwerg* a, coordinate f, Object* b) : Action(a), from(f), berries(b) {};
		virtual void execute();

	private:
		coordinate from;
		Object* berries;
		virtual bool isValid();

};
