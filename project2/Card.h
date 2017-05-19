#ifndef CARD_H
#define CARD_H

class Card
{
	private:
		int suit;
		int value;

	public:
		Card();
		Card(int, int);
		Card(const Card &);
		int getValue() { return value; }
		int getSuit() { return suit; }
		bool operator==(const Card &);
		bool operator>(const Card &);
};

#endif