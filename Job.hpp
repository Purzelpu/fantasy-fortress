#pragma once
#include "Coordinate.hpp"

class Job {
	public:
		unsigned int progress = 0;
		unsigned int hardness;
		Coordinate location;

		Job(Coordinate loc, int hard) : hardness(hard), location(loc) {};

		bool isDone();
};
