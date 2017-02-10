#include "Ant.h"
#include <cstdlib>
#include <iostream>

Ant::Ant(int ID)
{
	this->id = ID;
	this->x = 0;
	this->y = 0;
}

Ant::Ant(const Ant &old)
{
	this->id = old.id;
	this->x = old.x;
	this->y = old.y;
}

/* Move the ants in a random way (up, down, left, or right)
 * Also, see if the ant fights
 * Also, see if the ant finds food
 * @return
 * 0 -- Ant moved, nothing happened
 * 1 -- Ant in fight, won
 * 2 -- Ant in fight, lost
 * 3 -- Ant found food
 */
int Ant::move()
{
	// Random number 0 - 3 inclusive
	int randomNum = rand() % 4;
	int random_action = rand() % 5;

	switch (randomNum)
	{
		case 0: // Go up 1, unless attempt to go out of bounds
		{
			if (this->y != Y_MAX)
				this->y++;
		}
		break;

		case 1: // Go down 1, unless attempt to go out of bounds
		{
			if (this->y != -Y_MAX)
				this->y--;
		}
		break;

		case 2: // Go right 1, unless attempt to go out of bounds
		{
			if (this->x != X_MAX)
				this->x++;
		}
		break;

		case 3: // Go left 1, unless attempt to go out of bounds
		{
			if (this->x != -X_MAX)
				this->x--;
		}
		break;
	}

	switch (random_action)
	{
		case 3: // Fight time!
			return this->fight();
		break;

		case 4: // Food found!
			return 3;
		break;

		default: // Nothing happened, ant just moved
			return 0;
		break;
	}
}

/*
 * Ant is ready to fight!
 * 50/50 chance the ant wins or dies
 * return if it's alive or dead
 */
int Ant::fight()
{
	int win = rand() % 2;

	if (win)
		return 1;
	else
		return 2;
}

/*
 * Ant is less then half the grid distance from (0,0)
 * In the demo case of max = 25, an ant
 * from -12 to 12 in both directions is in range.
 */
bool Ant::inRange()
{

	if (-Y_MAX/2 < y && y < Y_MAX/2)
		if (-X_MAX/2 < x && x < X_MAX/2)
			return true;

	return false;
}