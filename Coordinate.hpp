#include <iostream>

struct coordinate
{
	unsigned int x;
	unsigned int y;
};

bool operator==(const coordinate& left, const coordinate& right);
bool operator!=(const coordinate& left, const coordinate& right);
std::ostream& operator<<(std::ostream& os,const coordinate& c);
