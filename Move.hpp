#pragma once
#include "Action.hpp"
#include "Coordinate.hpp"

class Move : public Action {
	public:
		Move(Object* a, Coordinate f, Coordinate t) : Action(a), from(f), to(t) {};
		~Move() {};
		virtual void execute() override;

	private:
		Coordinate from;
		Coordinate to;
		virtual bool isValid() const override;

};
