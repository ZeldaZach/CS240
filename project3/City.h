#ifndef CITY_H
#define CITY_H

#include <string>
#include <list>
#define String std::string

class City
{
	private:
		String name;
		int x;
		int y;
		int distance;
		bool fullyExplored;
		City *optimalPrevious;
		std::list<City *> adjacent;
		City *theClosestCity;

	public:
		City(String, int, int);
		String getName() { return name; };
		int getXCoor() { return x; };
		int getYCoor() { return y; };
		int getDistance() { return distance; };
		bool isFullyExplored() { return fullyExplored; };
		City* getTheClosestCity() { return theClosestCity; };
		City* getOptimalPrevious() { return optimalPrevious; };
		void setAdjacent(City *, City *, City *, City *);
		void setOptimalPrevious(City *);
		void setDistance(int);
		void setFullyExplored(bool);
		void setTheClosestCity(City *);
		std::list<City *> getAdjacent();
		bool operator<(City &);
		bool operator==(City &);
};

#endif
