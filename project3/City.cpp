#include "City.h"
#include <list>
#include <climits>

City::City(String cityName, int xCoor, int yCoor) : name(cityName), x(xCoor), y(yCoor), optimalPrevious(nullptr), distance(INT_MAX), fullyExplored(false)
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

void City::setOptimalPrevious(City* prev)
{
	optimalPrevious = prev;
}

void City::setDistance(int d)
{
	distance = d;
}

void City::setFullyExplored(bool b)
{
	fullyExplored = b;
}

void City::setTheClosestCity(City *c)
{
	theClosestCity = c;
}