#include "LinkedList.h"
#include <cstddef>
#include <iostream>

/*
 * Default Constructor
 */
LinkedList::LinkedList()
{
	this->head = NULL;
}

/*
 * Non-Default Constructor
 */
LinkedList::LinkedList(Ant* a)
{
	this->head = new Node(a);
}

/*
 * Copy Constructor
 */
LinkedList::LinkedList(const LinkedList &old)
{
	Node *old_nodes = old.head;
	while (old_nodes)
	{
		addAnt(new Ant(old_nodes->ant));
		old_nodes = old_nodes->next;
	}
}

/*
 * Destructor that deletes the nodes
 * the nodes should _already_ be empty
 * of memory so no need to check them for
 * what's inside of them.
 */
LinkedList::~LinkedList()
{
	Node *this_nodes = this->head;
	Node *next = NULL;

	while (this_nodes)
	{
		next = this_nodes->next;
		delete this_nodes;
		this_nodes = next;
	}
}

/*
 * Overload << operator to be another form of
 * append to list
 */
void LinkedList::operator<<(Ant *new_ant)
{
	this->addAnt(new_ant);
}

/*
 * Start by looping through the current LinkedList
 * until we hit the end. Then create a new node element
 * with the ant set and assign that to be the new last element
 * of the LinkedList.
 */
void LinkedList::addAnt(Ant* a)
{
	Node *tmp = this->head;
	Node *n = new Node(a);

	if (this->head == NULL)
	{
		this->head = n;
	}
	else
	{
		// Get to the end of the LL
		while (tmp->next)
			tmp = tmp->next;

		// Append to former end of LL
		tmp->next = n;
	}
}

/*
 * Start by looping through the current LinkedList
 * and trying to find an ant that has the id specified
 * in the parameter.
 * @return Ant* if we find it, NULL if we don't
 */
Ant* LinkedList::getAnt(int ant_id)
{
	Node *tmp = this->head;

	while (true)
	{
		if (tmp == NULL)
			return NULL;
		else if (tmp->ant->getID() == ant_id)
			return tmp->getAnt();
		else
			tmp = tmp->next;
	}
}

/*
 * Update the Node w/ the Ant's ID being ant_id
 * We update by removing the ant and putting a new
 * ant in its place (it probably has a new ID...)
 * @return true if the ant was replaced
 */
bool LinkedList::updateAnt(int ant_id, Ant* new_ant)
{
	Node *tmp = this->head;

	while (tmp)
	{
		if (tmp->getAnt()->getID() == ant_id)
		{
			delete tmp->ant;
			tmp->ant = new_ant;
			return true;
		}
		else
		{
			tmp = tmp->next;
		}
	}

	return false;
}

/*
 * Go through the LL and remove the ant specified by ant_id
 * Then link the prior and next nodes together to form a
 * continued LL. If head was removed, set next to head.
 * @return false if ant not found
 */
bool LinkedList::removeAnt(int ant_id)
{
	Node *tmp = this->head;
	Node *prev = NULL;

	while (tmp)
	{
		if (tmp->getAnt()->getID() == ant_id)
		{
			/*
			 * [PREV] => [THIS] => [NEXT]
			 * [PREV] => [NEXT]
			 */
			if (prev)
				prev->next = tmp->next;
			else
				this->head = tmp->next;

			delete tmp->getAnt();
			delete tmp;

			return true;
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}

	return false;
}

/*
 * Non-Default Constructor for Node
 */
Node::Node(Ant* a)
{
	this->ant = a;
	this->next = NULL;
}
