#ifndef ANTHILL_H
#define ANTHILL_H

#include "Ant.h"
#include "LinkedList.h"
#include <string>
#include <cstdlib>

class AntHill
{
	private:
		LinkedList *ants;
		int current_ants;
		int next_id;
		int food_count;
		int attack_count;
		int defended_attacks;
		int defeated_attacks;
		int turn_count;

	public:
		AntHill();
		~AntHill();
		int addAnt();
		int getCurrentNumAnts() { return current_ants; }
		int getDefenders();
		bool removeAnt(int ant_id);
		void turn();
		std::string move(bool wasAttacked);
		std::string printHillInfo(std::string beforeMessages = NULL, std::string afterMessages = NULL);
		Ant *getAnt(int ant_id) { return this->ants->getAnt(ant_id); }
		const static int STARTING_ANT_COUNT = 10; // How many ants to start in your new Ant Hill
		const static float ODDS_OF_ANTHILL_ATTACK = 0.20; // Odds of attack on the hill (1.00 = 100%)
};

#endif
