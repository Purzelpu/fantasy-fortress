#pragma once
#include "Object.hpp"

class Action {
	public:
	Object* agent;

	Action(Object* a) : agent(a) {}
	virtual ~Action() {};

	virtual void execute();

	private:
	virtual bool isValid();
};
