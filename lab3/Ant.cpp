#include "Ant.h"
#include <cstdlib>
#include <iostream>

Ant::Ant(int ID)
{
	this->id = ID;
	this->x = 0;
	this->y = 0;
	this->experience = 3;
}

// Move the ants in a random way (up, down, left, or right)
void Ant::move()
{
	// Random number 0 - 3 inclusive
	int randomNum = rand() % 4;

	switch (randomNum)
	{
		case 0: // Go up 1
			this->y++;
		break;
		
		case 1: // Go down 1
			this->y--;
		break;
		
		case 2: // Go right 1
			this->x++;
		break;
		
		case 3: // Go left 1
			this->x--;
		break;
	}
}

Ant* Ant::fight(Ant *other)
{
	Ant* winner;
	int this_ant_power, other_ant_power;

	// Don't allow for ties
	while (true)
	{
		this_ant_power = (rand() % this->experience) + 1;
		other_ant_power = (rand() % other->experience) + 1;
		
		if (this_ant_power != other_ant_power)
			break;
	}
	
	if (this_ant_power > other_ant_power)
	{		
		std::cerr << "Ant #" << this->getID() << " (defender) beats Ant #"
			<< other->getID() << " (challenger) by the score "
			<< this_ant_power << " to " << other_ant_power << std::endl;
		
		winner = this;
		winner->experience += other->experience;
	}
	else
	{
		std::cerr << "Ant #" << other->getID() << " (challenger) beats Ant #"
			<< this->getID() << " (defender) by the score "
			<< other_ant_power << " to " << this_ant_power << std::endl;
		
		winner = other;
		winner->experience += this->experience;
	}

	return winner;
}