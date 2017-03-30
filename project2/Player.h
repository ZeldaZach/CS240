#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Card.h"

#define String std::string

class Player
{
	private:
		String name;
		int budget;
	
	public:
		Card hand;
		
		Player(String, int);
		String getName();
		int getBudget();
		bool bet(int);
		void collectWinnings(int);
};

#endif