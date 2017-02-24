#ifndef CARD_H
#define CARD_H

class Card
{
	private:
		int suit;
		int value;

	public:
		Card(int suit, int value);
		int getValue() { return value; }
		int getSuit() { return suit; }
		bool operator==(const Card &other);
		
		enum Value {
			TWO = 2, THREE = 3, FOUR = 4, FIVE = 5,
			SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9,
			TEN = 10, JACK = 11, QUEEN = 12, KING = 13,
			ACE = 14
		};
		enum Suit { DIAMOND = 1, CLUB = 2, HEART = 3, SPACE = 4};
};


#endif