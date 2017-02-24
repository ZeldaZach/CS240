#include "LinkedList.h"
#include "Queue.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Deck.h"
#include "Card.h"
#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <cassert>
#include <string>
#include <ctime>
#include <cstdlib>

#define EXTRA_CREDIT 1

using namespace std;


int main(){
	srand(time(NULL));
	cerr << "\n\tTEST #1: Test create a integer List" << endl;
	LinkedList<int> list;
	list.insert(5);
	assert(list.read() == 5);
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #2: Test create a Card List" << endl;
	LinkedList<Card*> cards_list;
	cards_list.insert(new Card(1, 14));
	cards_list.insert(new Card(2, 14));
	cards_list.insert(new Card(3, 14));
	Card * draw_card1 = cards_list.read();
	assert(*draw_card1 == Card(1, 14));
	Card * draw_card2 = cards_list.read();
	assert(*draw_card2 == Card(2, 14));
	Card * draw_card3 = cards_list.read();
	assert(*draw_card3 == Card(3, 14));

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #3: Test delete elements from Linked List" << endl;
	cards_list.remove(draw_card1);
	delete draw_card1;
	cards_list.remove(draw_card2);
	delete draw_card2;
	cards_list.remove(draw_card3);
	delete draw_card3;
	assert(cards_list.empty() == true);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #4: Test add 1 element to a Queue" << endl;

	Queue<int> queue;
	queue.enqueue(5);
	assert(5 == queue.dequeue());

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #5: Test create a Card Queue" << endl;

	Queue<Card*> cards_queue;
	cards_queue.enqueue(new Card(1, 14));
	cards_queue.enqueue(new Card(2, 14));
	cards_queue.enqueue(new Card(3, 14));
	draw_card1 = cards_queue.dequeue();
	assert(*draw_card1 == Card(1, 14));
	assert(cards_queue.empty() == false);
	draw_card2 = cards_queue.dequeue();
	assert(*draw_card2 == Card(2, 14));
	draw_card3 = cards_queue.dequeue();
	assert(*draw_card3 == Card(3, 14));
	assert(cards_queue.empty() == true);
	delete draw_card1;
	delete draw_card2;
	delete draw_card3;

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #6: Test Card Queue Order" << endl;

	cards_queue.enqueue(new Card(1, 14));
	cards_queue.enqueue(new Card(2, 14));
	draw_card1 = cards_queue.dequeue();
	assert(*draw_card1 == Card(1, 14));
	cards_queue.enqueue(new Card(3, 14));
	draw_card2 = cards_queue.dequeue();
	assert(*draw_card2 == Card(2, 14));
	cards_queue.enqueue(new Card(4, 14));
	draw_card3 = cards_queue.dequeue();
	assert(*draw_card3 == Card(3, 14));
	Card * draw_card4 = cards_queue.dequeue();
	assert(*draw_card4 == Card(4, 14));
	delete draw_card1;
	delete draw_card2;
	delete draw_card3;
	delete draw_card4;

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #7: Create Deck" << endl;

	Deck deck;
	int last_suit = -1, last_val = -1;
	int num_cards = 1;
	for(Card draw_card = deck.draw();!deck.empty(); draw_card = deck.draw()){
		assert(draw_card.getSuit() != last_suit || draw_card.getValue() != last_val);
		last_suit = draw_card.getSuit();
		last_val = draw_card.getValue();
		num_cards++;
	}
	assert(num_cards == 52);

	cerr << "\n\t========================PASS========================\n" << endl;

#if EXTRA_CREDIT
	cerr << "\n\tTEST #8: EXTRA CREDIT -- Shuffle" << endl;
	Deck deck2, deck3, deck4;
	deck3.shuffle();
	deck4.shuffle();
	int unshuffled = 20;
	for(Card card2 = deck2.draw(), card3 = deck3.draw(), card4 = deck4.draw();
		!deck2.empty() && !deck3.empty() && !deck4.empty();
			card2 = deck2.draw(), card3 = deck3.draw(), card4 = deck4.draw()){
		if(card2 == card3 || card3 == card4){
			unshuffled--;
		}
		// cerr << "C2[" << card2.getSuit() << "," << card2.getValue() << "]\t";
		// cerr << "C3[" << card3.getSuit() << "," << card3.getValue() << "]\t";
		// cerr << "C4[" << card4.getSuit() << "," << card4.getValue() << "]" << endl;

		assert(unshuffled > 0);
	}
	cerr << "\n\t========================PASS========================\n" << endl;
#endif

	cerr << "\n\tAll Tests Passed.\nDon't forget to run with Valgrind and submit to Blackboard!\n" << endl;
	return 0;
}
