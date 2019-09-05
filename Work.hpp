#pragma once
#include "Action.hpp"
#include "Dwarf.hpp"
#include "Job.hpp"

class Work : public Action {
	public:
		Work(Dwarf* a, Job* j) : Action(a), job(j) {};
		~Work() {};
		virtual void execute();

	private:
		Job* job;
		virtual bool isValid();

};
