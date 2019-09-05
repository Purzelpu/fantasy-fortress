#pragma once
#include "Action.hpp"
#include "Coordinate.hpp"
#include "Bush.hpp"

class GrowBerries: public Action {
	public:
		GrowBerries(Bush* a) : Action(a) {};
		virtual void execute();

	private:
		virtual bool isValid();

};
