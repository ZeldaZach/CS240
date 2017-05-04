#include "Map.h"
#include "City.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <iomanip>

Map::Map(String fileName) : maxXCoordinate(0), maxYCoordinate(0)
{
	std::ifstream file(fileName);

	if (file.is_open())
	{
		String line;
		while (getline(file, line))
		{
			// result = [cityName, X, Y]
			std::vector<String> result;
			std::istringstream iss(line);
			for(String s; iss >> s; )
			    result.push_back(s);

			cities.push_back(new City(result.at(0), std::stoi(result.at(1)), std::stoi(result.at(2))));
		}

		setMaxCoordinates();
		addAdjacencies();
	}
	else
	{
		std::cerr << "Unable to open file " << fileName << std::endl;
	}
}

Map::~Map()
{
	for (auto iter : cities)
		delete iter;
}

void Map::setMaxCoordinates()
{
	for (auto city : cities)
	{
		if (city->getXCoor() > maxXCoordinate)
			maxXCoordinate = city->getXCoor();

		if (city->getYCoor() > maxYCoordinate)
			maxYCoordinate = city->getYCoor();
	}
}

void Map::addAdjacencies()
{
	/*
 	 * For each city, look up, down, left, and right.
 	 * If another city shares the X/Y Coorinate (Depending on dir we're checking)
 	 * Then add it as that adjacent city. If two+ cities share the same X/Y Coor
 	 * Then we will need to see which one is close.
 	 * Do this by THIS->Coor - THAT->Coor and the smaller number wins
	 */
	for (std::vector<City *>::iterator iter = cities.begin(); iter != cities.end(); iter++)
	{
		City *cUp = nullptr, *cDown = nullptr, *cLeft = nullptr, *cRight = nullptr, *closest = nullptr;
		City *cityToEstablish = *iter;
		
		cUp = getClosestCity(iter, X_AXIS, HIGHER);
		cDown = getClosestCity(iter, X_AXIS, LOWER);
		cLeft = getClosestCity(iter, Y_AXIS, LOWER);
		cRight = getClosestCity(iter, Y_AXIS, HIGHER);
		cityToEstablish->setAdjacent(cUp, cDown, cLeft, cRight);
		
		// Get the closest city of all 4 directions
		closest = getClosestCityInAllDirections(cityToEstablish);
		cityToEstablish->setTheClosestCity(closest);
	}
}

City* Map::getClosestCity(std::vector<City *>::iterator iter, Map::Direction axis, Map::Direction direction)
{
	City *city = *iter;
	City *dest = nullptr;
	int xCoor = city->getXCoor();
	int yCoor = city->getYCoor();
	int difference = INT_MAX;

	for (auto subIter = cities.begin(); subIter != cities.end(); subIter++)
	{
		if (iter == subIter)
			continue;

		City *otherCity = *subIter;

		if (axis == X_AXIS)
		{
			if (xCoor != otherCity->getXCoor())
				continue;

			if (direction == HIGHER)
				if (yCoor > otherCity->getYCoor())
					continue;

			if (direction == LOWER)
				if (yCoor < otherCity->getYCoor())
					continue;

			if (abs(yCoor - otherCity->getYCoor()) < difference)
			{
				difference = abs(yCoor - otherCity->getYCoor());
				dest = otherCity;
			}
		}
		else if (axis == Y_AXIS)
		{
			if (yCoor != otherCity->getYCoor())
				continue;

			if (direction == HIGHER)
				if (xCoor > otherCity->getXCoor())
					continue;

			if (direction == LOWER)
				if (xCoor < otherCity->getXCoor())
					continue;

			if (abs(xCoor - otherCity->getXCoor()) < difference)
			{
				difference = abs(xCoor - otherCity->getXCoor());
				dest = otherCity;
			}
		}
	}

	return dest;
}

City* Map::getClosestCityInAllDirections(City *c)
{
	int distance = 0;
	std::list<City *> adj = c->getAdjacent();
	City *closest = nullptr;
	
	for (auto iter : adj)
	{
		City *cIter = iter;
		
		if (cIter)
		{
			if (cIter->getXCoor() == c->getXCoor())
			{
				int checkDistance = abs(cIter->getYCoor() - c->getYCoor());
				if (checkDistance < distance)
				{
					distance = checkDistance;
					closest = cIter;
				}
			}
			else if (cIter->getYCoor() == c->getYCoor())
			{
				if (cIter)
				{
					int checkDistance = abs(cIter->getXCoor() - c->getXCoor());
					if (checkDistance < distance)
					{
						distance = checkDistance;
						closest = cIter;
					}
				}
			}
		}
	}
	
	return closest;
}

City* Map::findByName(String cityName)
{
	for (auto i : cities)
		if (i->getName() == cityName)
			return i;

	return nullptr;
}

std::vector<City *> Map::shortestPath(City *start, City *dest)
{
	std::vector<City *> path;
	
	for (auto iter = cities.begin(); iter != cities.end(); iter++)
	{
		City *c = *iter;
		c->setDistance(INT_MAX);
		c->setOptimalPrevious(nullptr);
		c->setFullyExplored(false);
	}

	start->setDistance(0);
	
	while (true)
	{
		City *node = getMinimumVertex();
		
		if (node == nullptr || node->getDistance() == INT_MAX)
			break;
		
		node->setFullyExplored(true);
		
		std::list<City *> adjacents = node->getAdjacent();
		
		for (auto iter = adjacents.begin(); iter != adjacents.end(); iter++)
		{
			City *adj = *iter;
			if (adj->getDistance() > node->getDistance() + getDistanceBetween(node, adj))
			{
				adj->setDistance(node->getDistance() + getDistanceBetween(node, adj));
				adj->setOptimalPrevious(node);
			}
		}
	}
	
	//printDEBUGTable();
	
	if (start == dest || dest->getOptimalPrevious())
	{
		while (dest)
		{
			path.push_back(dest);
			dest = dest->getOptimalPrevious();
		}
		std::reverse(path.begin(), path.end());
	}

	return path;
}

void Map::printDEBUGTable()
{
	std::cerr << std::setw(13) << "NAME";
	std::cerr << std::setw(10) << "Explored";
	std::cerr << std::setw(15) << "Distance";
	std::cerr << std::setw(13) << "PastOptimal" << std::endl;
	for (auto iter : cities)
	{	
		City *x = iter->getOptimalPrevious();
		String tt = x ? x->getName() : "";
		
		std::cerr << std::setw(13) << iter->getName();
		std::cerr << std::setw(10) << iter->isFullyExplored();
		std::cerr << std::setw(15) << iter->getDistance();
		std::cerr << std::setw(13) << tt << std::endl;
	}
}

int Map::getDistanceBetween(City *c1, City *c2)
{
	if (c1->getXCoor() == c2->getXCoor())
		return abs(c1->getYCoor() - c2->getYCoor());
	else if (c1->getYCoor() == c2->getYCoor())
		return abs(c1->getXCoor() - c2->getXCoor());

	return -1;
}

City* Map::getMinimumVertex()
{
	int dist = INT_MAX;
	City *retVal = nullptr;
	
	for (auto iter = cities.begin(); iter != cities.end(); iter++)
	{
		City *c = *iter;

		if (c->isFullyExplored())
			continue;

		if (c->getDistance() < dist)
		{
			dist = c->getDistance();
			retVal = c;
		}
	}

	return retVal;
}

unsigned int Map::pathDistance(City *start, City *dest)
{
	std::vector<City *> path = shortestPath(start, dest);
	return path.empty() ? -1 : path.back()->getDistance();
}