#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Heap.h"

Heap::Heap() : sortLength(0)
{
}

// Taken from https://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int
bool Heap::isInteger(const String &s)
{
   if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
	   return false;

   char *p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}

Heap::Heap(String filename) : sortLength(0)
{
	std::ifstream file(filename);
	
	if (file == NULL)
		return; // FILE_NOT_FOUND
	
	String line;
	while (std::getline(file, line)) // line = name
	{
		if (isInteger(line))
		{
			sortLength = 0;
			members.clear();
			return; // FILE_MALFORMED
		}

		String name = line;		
		std::getline(file, line); // line = budget

		if (!isInteger(line))
		{
			sortLength = 0;
			members.clear();
			return; // FILE_MALFORMED
		}

		unsigned int budget = stoi(line);

		Player p(name, budget);
		members.push_back(p);
	}
	
	sortLength = members.size();
	heapify();
}

Heap::Heap(const Heap &old) : sortLength(old.sortLength)
{
	for (auto i = old.members.begin(); i != old.members.end(); i++)
		this->members.push_back(*i);
	
	heapify();
}

void Heap::heapify()
{
	for (int i = (sortLength - 2)/2; i >= 0; i--)
		siftdown(i);
}

void Heap::siftdown(int pos)
{
	int lChild = 2*pos+1;
	int rChild = 2*pos+2;
	int largest;
	
	if (lChild < sortLength && members.at(lChild).getBudget() > members.at(pos).getBudget())
		largest = lChild;
	else
		largest = pos;
	
	if (rChild < sortLength && members.at(rChild).getBudget() > members.at(largest).getBudget())
		largest = rChild;
	
	if (largest != pos)
	{
		swap(largest, pos);
		siftdown(largest);
	}
}

void Heap::swap(int x, int y)
{
	Player tmp = members.at(x);
	members.at(x) = members.at(y);
	members.at(y) = tmp;
}

void Heap::addPlayer(Player p)
{
	this->members.push_back(p);
	this->sortLength++;
	heapify();
}

Player Heap::getPlayer()
{
	if (this->size() == 0)
		return Player();

	Player retVal = members.at(0);
	
	swap(0, sortLength-1);
	sortLength--;
	
	members.erase(members.end());

	siftdown(0);
	return retVal;
}

std::vector<Player> Heap::getArray()
{
	return members;
}

bool Heap::empty()
{
	return (members.size() == 0);
}

unsigned int Heap::size()
{
	return members.size();
}