#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <vector>
#include "Player.h"

#define String std::string

class Heap
{
	private:
		std::vector<Player> members;
		unsigned int length;
		unsigned int sortLength;
		
		void heapify();
		void siftdown(int);
		bool isLeaf(int);
		void swap(int, int);

	public:
		Heap();
		Heap(String);
		Heap(const Heap &);
		void addPlayer(Player);
		Player getPlayer();
		std::vector<Player> getArray();
		bool empty();
		unsigned int size();
};

#endif