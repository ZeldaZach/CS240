#include "LinkedList.h"
#include "Ant.h"
#include "AntHill.h"
#include <iostream>

void print(LinkedList ll)
{
	Node *head = ll.getHead();
	while (head)
	{
		std::cout << "Ant ID " << head->getAnt()->getID() << " was found" << std::endl;
		head = head->getNext();
	}
	std::cout << std::endl;

}

#if 0
int main()
{
	LinkedList ll;

	for (int i = 0; i < 10; i++) // Ants 0-9 are born
		ll.addAnt(new Ant(i));
	print(ll);

	for (int i = 0; i < 10; i+= 2) // Ants even are dead
		ll.removeAnt(i);
	print(ll);

	for (int i = 0; i < 10; i+=2) // Ants 0-9 even added back, out of order now
		ll << new Ant(i);
	print(ll);

	for (int i = 30; i < 40; i++) // Ants 30-39 are born
		ll << new Ant(i);
	print(ll);

	for (int i = 50; i < 60; i++) // Replace ants 0-9 w/ 50-59
		ll.updateAnt(i-50, new Ant(i));
	print(ll);

	LinkedList new_ll(ll); // Create a copy
	print(new_ll);

	LinkedList ll2(new Ant(10)); // Create a new LL w/ only 1 ant
	print(ll2);

	for (int i = 1111; i < 1120; i++) // Add ants to new LL
		ll2 << new Ant(i);
	print(ll2);

	return 0;
}
#endif

int main()
{
	AntHill *farm = new AntHill();

	for (int i = 0; i < 10; i++)
		farm->turn();
}