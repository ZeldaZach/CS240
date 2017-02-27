#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>
#include <iostream>
#include <type_traits>

template <class T>
class Node
{
	template <class U> friend class LinkedList;
	template <class U> friend class Queue;

	private:
		T data;

	public:
		Node<T> *next;
		Node(T);
};

template <class T>
class LinkedList
{
	template <class U> friend class Queue;

	private:
		Node<T> *head;
		Node<T> *iterator;

	public:
		LinkedList();
		LinkedList(T);
		LinkedList(const LinkedList<T> &);
		~LinkedList();

		void insert(T);
		T& read();
		bool empty();
		bool remove(T &);
		int size();
		Node<T> *getHead() { return head; }

		void operator<<(T new_data);
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	iterator = NULL;
}

template <class T>
LinkedList<T>::LinkedList(T initial)
{
	this->head = new Node<T>(initial);
	iterator = this->head;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &old)
{
	Node<T> *old_nodes = old.head;
	while (old_nodes)
	{
		insert(old_nodes->data);
		old_nodes = old_nodes->next;
	}
}

template <class T>
LinkedList<T>::~LinkedList() {
	Node<T> *this_nodes = this->head;
	Node<T> *next = NULL;

	while (this_nodes)
	{
		next = this_nodes->next;
		delete this_nodes;
		this_nodes = next;
	}
}

template <class T>
void LinkedList<T>::operator<<(T new_data)
{
	this->insert(new_data);
}

template <class T>
void LinkedList<T>::insert(T data)
{
	Node<T> *tmp = this->head;
	Node<T> *n = new Node<T>(data);

	if (this->head == NULL)
	{
		this->head = n;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = n;
	}
}

template <class T>
T& LinkedList<T>::read()
{
	if (this->iterator == NULL)
	{
		if (this->head == NULL)
		{
			// TODO: Figure out how to make this work
			// Illegal access
			std::exit(1);
		}
		else
		{
			iterator = this->head;
		}
	}

	Node<T> *tmp = this->iterator;
	this->iterator = iterator->next;

	return tmp->data;
}

template <class T>
bool LinkedList<T>::empty()
{
	return (this->size() == 0);
}

template <class T>
bool LinkedList<T>::remove(T &data)
{
	Node<T> *tmp = this->head;
	Node<T> *prev = NULL;

	while (tmp)
	{
		if (tmp->data == data)
		{
			if (prev)
			{
				prev->next = tmp->next;
			}
			else
			{
				this->head = tmp->next;
			}

			if (this->iterator == tmp)
			{
				this->iterator = tmp->next;
			}

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

template <class T>
int LinkedList<T>::size()
{
	int count = 0;
	Node<T> *tmp = this->head;

	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}

	return count;
}

template <class T>
Node<T>::Node(T initial)
{
	this->data = initial;
	this->next = NULL;
}

#endif