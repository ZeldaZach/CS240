#ifndef ANTHILL_H
#define ANTHILL_H

#include "Ant.h"
#include "LinkedList.h"
#include <string>

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

	public:
		AntHill();
		~AntHill();
		int addAnt();
		int getCurrentNumAnts() { return current_ants; }
		int getDefenders();
		bool removeAnt(int ant_id);
		void turn();
		std::string move();
		std::string printHillInfo(std::string additionalMessages = "");
		Ant *getAnt(int ant_id);
		
		
};

#endif