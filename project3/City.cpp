#include "City.h"
#include <list>

City::City(String cityName, int xCoor, int yCoor) : name(cityName), x(xCoor), y(yCoor)
{
}

void City::setAdjacent(City *up, City *down, City *left, City *right)
{
	if (up) adjacent.push_back(up);
	if (down) adjacent.push_back(down);
	if (left) adjacent.push_back(left);
	if (right) adjacent.push_back(right);
}

std::list<City *> City::getAdjacent()
{
	return adjacent;
}

bool City::operator<(City &c)
{
	return (c.getName() < this->name);
}

bool City::operator==(City &c)
{
	return (c.getName() == this->name && c.getXCoor() == this->getXCoor() && c.getYCoor() == this->getYCoor());
}