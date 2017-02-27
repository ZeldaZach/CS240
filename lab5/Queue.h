#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <class T>
class Queue
{
	private:
		/* Head = FRONT OF QUEUE; Tail = BACK OF QUEUE */
		LinkedList<T> *list;

	public:
		Queue();
		Queue(T initial);
		Queue(const Queue &old);
		~Queue();

		bool enqueue(T data);
		T dequeue();
		T peek();
		bool empty();
		void clear();
		int size();
};

template <class T>
Queue<T>::Queue()
{
	list = new LinkedList<T>();
}

template <class T>
Queue<T>::Queue(T initial)
{
	list = new LinkedList<T>(initial);
}

template <class T>
Queue<T>::Queue(const Queue &old)
{
	while (old != NULL)
		this->enqueue(old.read());
}

template <class T>
Queue<T>::~Queue()
{
	delete list;
}

template <class T>
bool Queue<T>::enqueue(T data)
{
	list->insert(data);
}

template <class T>
T Queue<T>::dequeue()
{
	T retVal = list->read();
	list->remove(retVal);
	return retVal;
}

template <class T>
T Queue<T>::peek()
{
	return this->list->iterator->data;
}

template <class T>
bool Queue<T>::empty()
{
	return (this->size() == 0);
}

template <class T>
void Queue<T>::clear()
{
	delete list;
	list = new LinkedList<T>();
}

template <class T>
int Queue<T>::size()
{
	return this->list->size();
}

#endif
