#pragma once
#include "Action.hpp"
#include "Coordinate.hpp"

class Move : public Action {
	public:
		Move(Object* a, coordinate f, coordinate t) : Action(a), from(f), to(t) {};
		~Move() {};
		virtual void execute() override;

	private:
		coordinate from;
		coordinate to;
		virtual bool isValid() const override;

};
