#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Heap.h"

Heap::Heap() : length(0), sortLength(0)
{
	
}

Heap::Heap(String filename) : length(0), sortLength(0)
{
	std::ifstream file(filename);
	
	if (file == NULL)
		std::exit(404); // FILE_NOT_FOUND
	
	String line;
	while (std::getline(file, line))
	{
		String name = line;
		
		std::getline(file, line); // line = budget now
		unsigned int budget = stoi(line);

		Player p(name, budget);
		this->members.push_back(p);
		this->length++;
		this->sortLength++;
	}
}

Heap::Heap(const Heap &old) : length(old.length), sortLength(old.sortLength)
{
	for (auto i = old.members.begin(); i != old.members.end(); i++)
		this->members.push_back(*i);
}

void Heap::heapify()
{
	for (int i = (length - 2) / 2; i >= 0; i--)
		siftdown(i);
}

void Heap::siftdown(int i)
{
	if (i < 0 || i > length)
		return;
	
	while (!isLeaf(i))
	{
		int cIndex = 2*i+1;
		
		if ((cIndex+1 < length) && (members.at(cIndex).getBudget() < members.at(cIndex+1).getBudget()))
			cIndex++;
		
		if (members.at(i).getBudget() > members.at(cIndex).getBudget())
			return;
		
		swap(i, cIndex);
		i = cIndex;
	}
}

bool Heap::isLeaf(int i)
{
	return (2*i+1 >= length && 2*i+2 >= length);
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
	this->length++;
	this->sortLength++;
}

Player Heap::getPlayer()
{
	members.erase(members.begin()); // Erase highest priority
	length--;
	sortLength--;
	heapify();
}

std::vector<Player> Heap::getArray()
{
	return members;
}

bool Heap::empty()
{
	return (length == 0);
}

unsigned int Heap::size()
{
	return length;
}