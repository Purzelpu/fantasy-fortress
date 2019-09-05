#pragma once
#include "Action.hpp"
#include "Coordinate.hpp"
#include "Dwarf.hpp"

class TakeBerries: public Action {
	public:
		TakeBerries(Dwarf* a, Coordinate f, Object* b) : Action(a), from(f), berries(b) {};
		virtual void execute() override;

	private:
		Coordinate from;
		Object* berries;
		virtual bool isValid() const override;

};
