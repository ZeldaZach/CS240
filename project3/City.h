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
		std::list<City *> adjacent;

	public:
		City(String, int, int);
		String getName() { return name; };
		int getXCoor() { return x; };
		int getYCoor() { return y; };
		void setAdjacent(City *, City *, City *, City *);
		std::list<City *> getAdjacent();
		bool operator<(City &);
		bool operator==(City &);
};

#endif
