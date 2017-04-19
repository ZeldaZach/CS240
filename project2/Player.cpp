#include "Player.h"

Player::Player() : name(), budget(-1)
{
}

Player::Player(String name, int budget) : name(name), budget(budget)
{	
}

String Player::getName()
{
	return name;
}

int Player::getBudget()
{
	return budget;
}

bool Player::bet(int amount)
{
	if (amount > budget)
		return false;

	budget -= amount;
	return true;
}

void Player::collectWinnings(int amount)
{
	budget += amount;
}

bool Player::operator==(const Player &other)
{
	return (this->name == other.name && this->budget == other.budget);
}