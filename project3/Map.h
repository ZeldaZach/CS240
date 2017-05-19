#ifndef MAP_H
#define MAP_H

#include "City.h"
#include <string>
#include <vector>
#define String std::string

class Map
{
	public:
		Map(String);
		~Map();
		City* findByName(String);
		std::vector<City *> shortestPath(City*, City*);
		unsigned int pathDistance(City*, City*);
		enum Direction {X_AXIS, Y_AXIS, HIGHER, LOWER};

	private:
		std::vector<City *> cities;
		int maxXCoordinate;
		int maxYCoordinate;
		void addAdjacencies();
		void setMaxCoordinates();
		City* getClosestCity(std::vector<City *>::iterator, Map::Direction, Map::Direction);
		City* getClosestCityInAllDirections(City *);
		City* getMinimumVertex();
		int getDistanceBetween(City *, City *);
		void printDEBUGTable();
};

#endif
