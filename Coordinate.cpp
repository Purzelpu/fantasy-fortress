#include "Coordinate.hpp"

bool operator==(const coordinate& left, const coordinate& right)
{
	return left.x==right.x && left.y==right.y;
}

bool operator!=(const coordinate& left, const coordinate& right)
{
	return !(left==right);
}

std::ostream& operator<<(std::ostream& os,const coordinate& c)
{
	os << c.x << " " << c.y;
	return os;
}
