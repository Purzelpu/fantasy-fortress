#pragma once
#include "Action.hpp"
#include "Zwerg.hpp"
#include "Job.hpp"

class Work : public Action {
	public:
		Work(Zwerg* a, Job* j) : Action(a), job(j) {};
		~Work() {};
		virtual void execute();

	private:
		Job* job;
		virtual bool isValid();

};
