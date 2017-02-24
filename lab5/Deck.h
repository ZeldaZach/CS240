#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Queue.h"

class Deck
{
	private:
		Queue<Card*> *deck;
		
	public:
		Deck();
		Card draw();
		bool empty();
		void shuffle();
};

#endif