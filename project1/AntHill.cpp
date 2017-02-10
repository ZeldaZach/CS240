#include "AntHill.h"
#include "Ant.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>

/*
 * Taken from Stack Overflow to fix strings
 * https://stackoverflow.com/questions/12975341/to-string-is-not-a-member-of-std-says-g
 */
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}

AntHill::AntHill()
{
	this->current_ants = 0;
	this->next_id = 1;
	this->food_count = 0;
	this->ants = new LinkedList();
	this->attack_count = 0;
	this->defended_attacks = 0;
	this->defeated_attacks = 0;
	this->turn_count = 1;

	for (int i = 0; i < STARTING_ANT_COUNT; i++)
		this->addAnt();
}

AntHill::~AntHill()
{
	delete this->ants;
}

int AntHill::addAnt()
{
	if (this->ants->addAnt(new Ant(this->next_id)))
	{
		this->next_id++; // IDs are unique
		this->current_ants++; // Update the count of ants in the hill

		return this->next_id - 1; // ID of the ant that was just added
	}
	
	return -1; // There was an error
}

bool AntHill::removeAnt(int ant_id)
{
	if (this->ants->removeAnt(ant_id))
		this->current_ants--;
}

Ant* AntHill::getAnt(int ant_id)
{
	return this->ants->getAnt(ant_id);
}

void AntHill::turn()
{
	std::string afterMessages, beforeMessages; // Message buffers for the output
	
	//The Anthill produces all of the ants it can
	for (int i = 0; i < this->food_count; i++)
	{
		int new_ant = this->addAnt();
		beforeMessages.append("Ant #" + patch::to_string(new_ant) + " has been born and has set out scavaging\n");
	}
	this->food_count = 0;

	//The Anthill may be attacked
	int action_to_take = rand() % 5;

	if (action_to_take == ANT_HILL_ATTACKED_NUM) // Ant Hill Attacked (20% chance)
	{
		int attacking_ants = rand() % (this->current_ants + 1) + 1; // Range: [1, this->current_ants]

		// Any Ants less than half the size of the grid in any direction help ‘defend’.
		int defending_ants = this->getDefenders();
		this->attack_count++;

		if (defending_ants < attacking_ants)
		{
			// Delete all defending_ants
			for (int i = 0; i < this->next_id; i++)
			{
				if (this->getAnt(i) && this->getAnt(i)->inRange())
				{
					beforeMessages.append("Ant #" + patch::to_string(i) + " has fought and died in the ant hill invasion\n");
					this->removeAnt(i);
				}
			}
			this->food_count = 0;
			this->defeated_attacks++;
		}
		else
		{
			for (int i = 0; i < this->next_id; i++)
				if (this->getAnt(i) && this->getAnt(i)->inRange())
					beforeMessages.append("Ant #" + patch::to_string(i) + " has fought and survived the ant hill invasion\n");

			this->defended_attacks++;
		}
	}

	// Every Ant has moved
	beforeMessages.append(move(action_to_take == ANT_HILL_ATTACKED_NUM));
	
	// Write output to log file
	std::ofstream file;
	file.open("anthill.log", std::ios::out | std::ios::app);
	file << printHillInfo(beforeMessages, afterMessages);
	file.close();
	
	this->turn_count++;
}

/*
 * This will return how many anys are in range
 * and are able to help defend the ant hill
 * incase of attack by foreigners
 */
int AntHill::getDefenders()
{
	int retVal = 0;

	for (int i = 0; i < this->next_id; i++)
		if (this->getAnt(i) && this->getAnt(i)->inRange())
			retVal++;

	return retVal;
}

/*
 * Get the current state of the AntHill
 * This will tell us how much food, how many ants
 * how many attacks we've had, how many attacks 
 * we've lost, and (optional) the action taken
 * by the ants on their journey around the ant farm.
 */
std::string AntHill::printHillInfo(std::string beforeMessages, std::string afterMessages)
{
	std::string retVal("");
	
	// Append turn number
	retVal.append("----Turn " + patch::to_string(this->turn_count) + "-----\n");
	
	// If there's optional beforeMessages included, begin with them!
	if (beforeMessages.length())
		retVal.append(beforeMessages);

	// Populare the retVal with relevant data
	retVal.append(
		std::string("The hill currently has:") + "\n"
		+ "Food: " + patch::to_string(this->food_count) + "\n"
		+ "Ants: " + patch::to_string(this->current_ants) + "\n"
		+ "The hill has been attacked " + patch::to_string(this->attack_count) + " times." + "\n"
		+ "Successfully defended: " + patch::to_string(this->defended_attacks) + "\n"
		+ "Failed to defend: " + patch::to_string(this->defeated_attacks) + "\n"
	);

	// If there's optional afterMessages included, append them too!
	if (afterMessages.length())
		retVal.append(afterMessages);

	// Add a line break for good measure before returning
	retVal.append("\n");
		
	return retVal;
}

/* Randomly move each ant in the ant hill
 * Return a string of all the ant actions that occured
 * seperated by line breaks
 */
std::string AntHill::move(bool wasAttacked)
{
	std::string retStr("");

	for (int i = 0; i < this->next_id; i++)
	{
		if (this->getAnt(i))
		{
			int retVal = this->getAnt(i)->move();

			// If the ant helped in the attack, it is not out fighting/foraging
			if (wasAttacked && this->getAnt(i)->inRange())
				break;

			switch (retVal)
			{
				default:
				case 0: // Ant moved
				break;

				case 1: // Ant in fight, won
					retStr.append("Ant #" + patch::to_string(i) + " has run into a rival ant and killed them\n");
				break;

				case 2: // Ant in fight, lost
					retStr.append("Ant #" + patch::to_string(i) + " has run into a rival ant, fought, and died\n");
					this->removeAnt(i);
				break;

				case 3: // Ant found food
					retStr.append("Ant #" + patch::to_string(i) + " has foraged and found a food\n");
					this->food_count++;
				break;
			}
		}
	}

	return retStr;
}