#pragma once
#include "Action.hpp"
#include "Coordinate.hpp"
#include "Zwerg.hpp"

class GetJobAction : public Action {
	public:
		GetJobAction(Zwerg* a): Action(a) {};
		virtual void execute();

	private:
		virtual bool isValid();

};
