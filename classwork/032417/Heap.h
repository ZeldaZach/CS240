#ifndef HEAP_H
#define HEAP_H

#include <cstdlib>

template <class T>
class Heap {
	private:
	T *list;
	unsigned int heapSize, listSize;
	bool isLeaf(int i);
	void swap(int x, int y);
	void siftdown(int i);
	void heapify();

	public:
	Heap();
	Heap(T list, int size);
	Heap(Heap &old); // Todo
	~Heap(); // Todo
};

template <class T>
Heap<T>::Heap() : list(nullptr), heapSize(0), listSize(0)
{
}

template <class T>
Heap<T>::Heap(T list, int size) : list(list), heapSize(size), listSize(size)
{
	heapify();
}

template <class T>
void Heap<T>::heapify()
{
	for (int i = (this->size-2)/2; i >= 0; i--)
	{
		siftdown(i);
	}
}

template <class T>
void Heap<T>::siftdown(int i)
{
	if (i < 0 || i > this->size)
		return;

	while (!isLeaf(i)) // 2i+1 == null, 2i+2 == null
	{
		int child = left(i); // left(int i) ret 2i+1

		if ((child+1 < this->size) && list[child] < list[child+1])
			child = child+1;

		if (list[i] > list[child])
			return;

		swap(i, child);
		i = child;
	}
}

template <class T>
void Heap<T>::swap(int x, int y)
{
	if (list[x] != list[y])
	{
		list[x] ^= list[y];
		list[y] ^= list[x];
		list[x] ^= list[y];
	}
}

#endif
