#pragma once
#include "Action.hpp"
#include "Coordinate.hpp"
#include "Dwarf.hpp"

class GetJobAction : public Action {
	public:
		GetJobAction(Dwarf* a): Action(a) {};
		virtual void execute();

	private:
		virtual bool isValid();

};
