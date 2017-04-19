#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <vector>
#include "Player.h"

#define String std::string

class Heap
{
	private:
		int sortLength;
		
		void heapify();
		void siftdown(int);
		void swap(int, int);

	public:
		std::vector<Player> members;
		Heap();
		Heap(String);
		Heap(const Heap &);
		void addPlayer(Player);
		Player getPlayer();
		std::vector<Player> getArray();
		bool empty();
		unsigned int size();
		bool isInteger(const String &s);
};

#endif