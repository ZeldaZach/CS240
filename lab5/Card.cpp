#include "Card.h"

Card::Card(int suit, int value)
{
	this->suit = 0;
	this->value = 0;

	if (1 < value && value < 15)
		this->suit = suit;

	if (0 < suit && suit < 5)
		this->value = value;
}

Card::Card(const Card &old)
{
	this->suit = old.suit;
	this->value = old.value;
}


bool Card::operator==(const Card &other)
{
	return ((this->suit == other.suit) && (this->value == other.value));
}
