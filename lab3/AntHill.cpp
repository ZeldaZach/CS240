#include "AntHill.h"
#include "Ant.h"
#include <iostream>

AntHill::AntHill()
{
	this->current_ants = 0;
	this->next_id = 0;
	this->ants = NULL;
}

AntHill::~AntHill()
{
	// Delete the pointers inside of the array
	for (int i = 0; i < current_ants; i++)
		delete ants[i];

	// Delete the array that held the pointers
	delete[] this->ants;
}

int AntHill::addAnt()
{
	// Allocate new array of size+1
	Ant **tmp = new Ant*[current_ants + 1];

	// Copy old array to new array
	for (int i = 0; i < current_ants; i++)
		tmp[i] = ants[i];

	// New ant object
	Ant *new_ant = new Ant(this->next_id);
	this->next_id++;

	// Resulting ant into new array
	tmp[current_ants] = new_ant;

	// Update current number of ants
	this->current_ants++;

	// Free old array and set that array to new array
	delete[] this->ants;
	this->ants = tmp;

	return new_ant->getID();
}

bool AntHill::removeAnt(int id)
{
	bool retVal = false;
	int indexToSlate = -1;

	// First, lets see if this ant that is slated to die actually exists
	for (int i = 0; i < this->current_ants; i++)
	{
		if (this->ants[i]->getID() == id)
		{
			retVal = true;
			indexToSlate = i;
			break;
		}
	}

	/* Ok, so we need to remove an ant from the hill
	 * If we're not slating an ant, then just return false
	 */
	if (retVal)
	{
		// Allocate new array of size-1
		Ant **tmp = new Ant*[this->current_ants - 1];

		// Copy all pointers over except removed ant
		for (int i = 0, j = 0; i < this->current_ants; i++)
		{
			if (i == indexToSlate)
			{
				delete this->ants[i];
			}
			else
			{
				tmp[j] = this->ants[i];
				j++;
			}
		}

		// Update current number of ants
		this->current_ants--;

		// Free old array and set that array to new array
		delete[] this->ants;
		this->ants = tmp;
	}

	return retVal;
}

Ant* AntHill::getAnt(int id)
{
	// Return ant by ID, not index
	for (int i = 0; i < this->current_ants; i++)
		if (ants[i]->getID() == id)
			return this->ants[i];

	return NULL;
}

// Randomly move each ant in the ant hill
void AntHill::move()
{
	for (int i = 0; i < this->current_ants; i++)
	{
		this->ants[i]->move();
	}
}

void AntHill::printHillInfo()
{
	for (int i = 0; i < this->current_ants; i++)
	{
		std::cout << "Ant #" << i << " [" << this->ants[i]->getX() << "," << this->ants[i]->getY() << "]" << std::endl;
	}
}
