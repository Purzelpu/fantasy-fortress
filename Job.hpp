#pragma once
#include "Coordinate.hpp"

class Job {
	public:
		unsigned int progress = 0;
		unsigned int hardness;
		coordinate location;

		Job(coordinate loc, int hard) : hardness(hard), location(loc) {};

		bool isDone();
};
