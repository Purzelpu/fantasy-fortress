#include "Job.hpp"

bool Job::isDone()
{
	return progress >= hardness;
}
