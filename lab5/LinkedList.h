#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>
#include <iostream>

template <class T>
class Node
{
	template <class U> friend class LinkedList;
	template <class U> friend class Queue;

	private:
		T data;

	public:
		Node<T> *next;
		Node(T initial);
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
		LinkedList(T initial);
		LinkedList(const LinkedList<T> &old);
		~LinkedList();

		void insert(T data);
		T& read();
		bool empty();
		bool remove(T &data);
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
	return (this->head == NULL);
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
			if (tmp == this->head)
			{
				std::cerr << "Head is null" << std::endl;
				this->head = NULL;
			}
			else if (prev)
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
Node<T>::Node(T initial)
{
	this->data = initial;
	this->next = NULL;
}


#endif
