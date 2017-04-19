#include "Card.h"

Card::Card() : suit(0), value(0)
{
}

Card::Card(int suit, int value) : suit(0), value(0)
{
	// Card values 2 - A (A = 14, K = 13, ..., 3 = 3, 2 = 2)
	if (1 < value && value < 15)
		this->value = value;

	// Suit values Diamonds-Spaces (Diamond = 1, Club = 2, Heart = 3, Spade = 4)
	if (0 < suit && suit < 5)
		this->suit = suit;
}

Card::Card(const Card &old) : suit(old.suit), value(old.value)
{
}

/*
 * Attempting to see if this card = other card
 * Example: ret true if this = Card(DIAMONDS, JACK) & other = Card(DIAMONDS, JACK)
 */
bool Card::operator==(const Card &other)
{
	return ((this->suit == other.suit) && (this->value == other.value));
}

bool Card::operator>(const Card &other)
{
	return (this->value > other.value);
}
