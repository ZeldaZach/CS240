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

Ant::Ant(Ant *old)
{
	this->id = old->id;
	this->x = old->x;
	this->y = old->y;
}

/* Move the ants in a random way (up, down, left, or right)
 * Also, see if the ant fights
 * Also, see if the ant finds food
 * @return enum of action taken
 */
int Ant::move()
{
	int move_direction = rand() % 4;

	switch (move_direction)
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

	// 20% fight, 20% find food, 60% just move
	int random_action = rand() % 5;
	switch (random_action)
	{
		case 3: // Fight time!
			return this->fight();
		break;

		case 4: // Food found!
			return FOUND_FOOD;
		break;

		default: // Nothing happened, ant just moved
			return JUST_MOVED;
		break;
	}
}

/*
 * Ant is ready to fight!
 * 66/33 chance the ant wins or dies
 * return if it's alive or dead
 */
int Ant::fight()
{
	// Our hero ant will win ODDS_OF_WINNING_FIGHT % of the time
	bool winner = ((rand() % 100) < (ODDS_OF_WINNING_FIGHT * 100));

	if (winner)
		return FIGHT_WIN;
	else
		return FIGHT_LOSE;
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

/*
 * Compare 2 ants and see if they are the same
 * 2 ants are the "same" if they have the same ID
 */
bool Ant::operator==(Ant *other)
{
	if (this->id == other->id)
		return true;

	return false;
}