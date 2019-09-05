#pragma once
#include <iostream>

struct Coordinate
{
	unsigned int x;
	unsigned int y;
};

bool operator==(const Coordinate& left, const Coordinate& right);
bool operator!=(const Coordinate& left, const Coordinate& right);
std::ostream& operator<<(std::ostream& os,const Coordinate& c);
