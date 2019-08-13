#pragma once
#include "Object.hpp"

class Action {
	public:
	Object* agent;
	std::string logMessage;

	Action(Object* a) : agent(a), logMessage("") {}
	virtual ~Action() {};

	virtual void execute();

	private:
	virtual bool isValid();
};
