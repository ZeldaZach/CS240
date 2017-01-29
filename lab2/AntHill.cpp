#include "AntHill.h"
#include <cstdlib>
#include <iostream>

Ant::Ant()
{
	// Invalid Object
}

Ant::Ant(int ID)
{
	this->id = ID;
	this->x = 0;
	this->y = 0;
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

int Ant::getID()
{
	return this->id;
}

int Ant::getX()
{
	return this->x;
}

int Ant::getY()
{
	return this->y;
}

AntHill::AntHill(int maxAnts)
{
	this->max_ants = maxAnts;
	this->current_ants = 0;
	this->next_id = 0;
}

bool AntHill::addAnt()
{
	// Ant Farm at max capacity already
	if (this->max_ants == this->current_ants)
	{
		return false;
	}
	else
	{
		// Add a new ant, increase total num of ants in hill, and set unique ID for next any
		this->ants[this->next_id] = Ant(this->next_id);
		this->current_ants++;
		this->next_id++;
		return true;
	}
	
}

Ant AntHill::getAnt(int id)
{
	return this->ants[id];
}

// Randomly move each ant in the ant hill
void AntHill::move()
{
	for (int i = 0; i < this->current_ants; i++)
	{
		this->ants[i].move();
	}
}

bool AntHill::changeMax(int newMaxAnts)
{
	// Cannot have negative ants, nor more than 100 (max size of buffer)
	if (newMaxAnts < 0 || newMaxAnts > 100)
		return false;
	else
		this->max_ants = newMaxAnts;
	
	return true;
}

void AntHill::printHillInfo()
{
	for (int i = 0; i < this->current_ants; i++)
	{
		std::cout << "Ant #" << i << " [" << this->ants[i].getX() << "," << this->ants[i].getY() << "]" << std::endl;
	}
}

int AntHill::getCurrentNumAnts()
{
	return this->current_ants;
}

int AntHill::getMaxAnts()
{
	return this->max_ants;
}
