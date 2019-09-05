#pragma once

#include <iostream>
#include <vector>
#include "Action.hpp"
#include "Object.hpp"
#include "CursesOutput.hpp"
#include "Job.hpp"

const unsigned int HOCH = 20;
const unsigned int BREIT = 30;

class World{
	public:
	Object* feld[BREIT][HOCH] = {nullptr};
	Object* getObjectAt(coordinate& c);
	CursesOutput output;
	constexpr bool isValid(const coordinate& c) const
	{
		return (c.x <= BREIT) && (c.y <=HOCH);
	}
	void init();
	void tick();
	void registerAction(Action*);
	void registerJob(Job*);
	bool hasJobs() const;
	Job* getJob();

	private:
	std::vector<Action*> action_queue;
	std::vector<Job*> job_queue;
};

