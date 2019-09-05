#include "Coordinate.hpp"

bool operator==(const Coordinate& left, const Coordinate& right)
{
	return left.x==right.x && left.y==right.y;
}

bool operator!=(const Coordinate& left, const Coordinate& right)
{
	return !(left==right);
}

std::ostream& operator<<(std::ostream& os,const Coordinate& c)
{
	os << c.x << " " << c.y;
	return os;
}
