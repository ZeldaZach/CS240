#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <iostream>
#include "Player.h"

class Table
{
	private:
		std::vector<Player> players;
		
	public:
		Table(int, int);
		bool emptySeat();
		std::vector<Player> playRound();
		void addPlayer(Player);
		void printWinner();
};

#endif