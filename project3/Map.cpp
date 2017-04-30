#include "Map.h"
#include "City.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <climits>

Map::Map(String fileName) : maxXCoordinate(0), maxYCoordinate(0)
{
	std::ifstream file(fileName);

	if (file.is_open())
	{
		String line;
		while (getline(file, line)) // cityName X Y
		{
			// https://www.quora.com/How-do-I-split-a-string-by-space-into-an-array-in-c++
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
 	 * If another city shares the X/Y coordinate (Depending on dir we're checking)
 	 * Then add it as that adjacent city. If two+ cities share the same X/Y coord
 	 * Then we will need to see which one is close.
 	 * Do this by THIS->Coord - THAT->Coord and the smaller number wins
	 */
	for (std::vector<City *>::iterator iter = cities.begin(); iter != cities.end(); iter++)
	{
		City *cUp, *cDown, *cLeft, *cRight;
			
		cUp = getClosestCity(iter, X_AXIS, HIGHER);
		cDown = getClosestCity(iter, X_AXIS, LOWER);
		cLeft = getClosestCity(iter, Y_AXIS, LOWER);
		cRight = getClosestCity(iter, Y_AXIS, HIGHER);

		(*iter)->setAdjacent(cUp, cDown, cLeft, cRight);
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

City* Map::findByName(String cityName)
{
	for (auto i : cities)
		if (i->getName() == cityName)
			return i;
	
	return nullptr;
}

std::vector<City *> Map::shortestPath(City *start, City *dest)
{
	return std::vector<City *>();
}

unsigned int Map::pathDistance(City *start, City *dest)
{
	return 0;
}