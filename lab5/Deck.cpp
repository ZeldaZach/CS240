#include "Deck.h"

Deck::Deck()
{
	deck = new Queue<Card*>();

	for (int value = 2; value <= 14; value++) // 2 through Ace
		for (int suit = 1; suit <= 4; suit++) // Diamond through Space
			deck->enqueue(new Card(suit, value));
}

Card Deck::draw()
{
	return *(deck->dequeue());
}

bool Deck::empty()
{
	return deck->empty();
}

void Deck::shuffle()
{
	int size = deck->size();
	Queue<Card*> *tmp_deck = new Queue<Card*>();
	Card *tmp[size];
	
	for (int i = 0; i < size; i++)
	{
		tmp[i] = deck->dequeue();
	}

	// Do Shuffle here
	
	for (int i = 0; i < size; i++)
	{
		tmp_deck->enqueue(tmp[i]);
	}
	
	deck = tmp_deck;
}
