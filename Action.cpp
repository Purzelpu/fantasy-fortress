#include "Action.hpp"
#include <iostream>

bool Action::isValid()
{
	return true;
}

void Action::execute()
{
	std::cout << "Do nothing" << std::endl;
}
