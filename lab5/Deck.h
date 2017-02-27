#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Queue.h"

class Deck
{
	private:
		Queue<Card*> *deck;
		void swap(Card&, Card&);
		void randomize(Card**, int);

	public:
		Deck();
		~Deck();
		Card draw();
		bool empty();
		void shuffle();
};

#endif