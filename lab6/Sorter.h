#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <sys/time.h>

template <class T>
class Sorter
{
	private:
		T container; // std::vector<int> or std::list<int>
		void swap(int &, int &);

	public:
		Sorter();
		void clear();
		unsigned int size();
		void insert(int i);
		void shuffle();
		typename T::iterator operator[](int index);

		void insertionSort();
		void selectionSort();
		void bubbleSort();
};

template <class T>
Sorter<T>::Sorter()
{
}

template <class T>
void Sorter<T>::clear()
{
	this->container.clear();
}

template <class T>
unsigned int Sorter<T>::size()
{
	return this->container.size();
}

template <class T>
void Sorter<T>::insert(int i)
{
	this->container.push_back(i);
}

template <class T>
void Sorter<T>::shuffle()
{
	std::vector<int> tmp;

	// Push to tmp
	while (size() != 0)
	{
		tmp.push_back(container.back());
		this->container.pop_back();
	}

	// Do actual shuffle
	for (int i = 0; i < 3; i++)
		std::random_shuffle(tmp.begin(), tmp.end());

	// Push to container
	while (tmp.size() != 0)
	{
		insert(tmp.back());
		tmp.pop_back();
	}
}

template <class T>
typename T::iterator Sorter<T>::operator[](int index)
{
	int i = 0;
	typename T::iterator myIterator = this->container.begin();

	while (true)
	{
		if (i == index)
			return myIterator;

		i++;
		myIterator++;
	}
}

template <class T>
void Sorter<T>::insertionSort()
{
	struct timeval t1, t2;
	double timeUsed;
	std::vector<int> tmp;

	// Start timer
	gettimeofday(&t1, NULL);

	// Push values to tmp
	while (size() != 0)
	{
		tmp.push_back(container.back());
		this->container.pop_back();
	}

	// Insertion Sort Method
	for (int i = 1; i < tmp.size(); i++)
		for (int j = i; j > 0 && tmp.at(j-1) < tmp.at(j); j--)
			swap(tmp.at(j), tmp.at(j-1));

	// Push values to container
	while (tmp.size() != 0)
	{
		insert(tmp.back());
		tmp.pop_back();
	}

	// Stop timer
	gettimeofday(&t2, NULL);

	// Calculate time used
	timeUsed = (t2.tv_sec - t1.tv_sec) * 1000.0;
	timeUsed += (t2.tv_usec - t1.tv_usec) / 1000.0;
	std::cout << "Sort Method insertSort took " << timeUsed << " ms"
		<< " to sort " << size() << " elements." << std::endl;
}

template <class T>
void Sorter<T>::selectionSort()
{
	struct timeval t1, t2;
	double timeUsed;
	std::vector<int> tmp;

	// Start timer
	gettimeofday(&t1, NULL);

	// Push values to tmp
	while (size() != 0)
	{
		tmp.push_back(container.back());
		this->container.pop_back();
	}

	// Selection Sort Method
	int i, minElementIndex, j;

	for (i = 0; i < (tmp.size() - 1); i++)
	{
		minElementIndex = i;
		for (j = i+1; j < tmp.size(); j++)
			if (tmp.at(j) > tmp.at(minElementIndex))
				minElementIndex = j;

		if (minElementIndex != i)
			swap(tmp.at(i), tmp.at(minElementIndex));
	}

	// Push values to container
	while (tmp.size() != 0)
	{
		insert(tmp.back());
		tmp.pop_back();
	}

	// Stop timer
	gettimeofday(&t2, NULL);

	// Calculate time used
	timeUsed = (t2.tv_sec - t1.tv_sec) * 1000.0;
	timeUsed += (t2.tv_usec - t1.tv_usec) / 1000.0;
	std::cout << "Sort Method selectionSort took " << timeUsed << " ms"
		<< " to sort " << size() << " elements." << std::endl;
}

template <class T>
void Sorter<T>::bubbleSort()
{
	struct timeval t1, t2;
	double timeUsed;
	std::vector<int> tmp;

	// Start timer
	gettimeofday(&t1, NULL);

	// Push values to tmp
	while (size() != 0)
	{
		tmp.push_back(container.back());
		this->container.pop_back();
	}

	// Do bubble Sort
	for (int i = 0; i < (tmp.size() - 1); i++)
		for (int j = 0; j < (tmp.size() - i - 1); j++)
			if (tmp.at(j) < tmp.at(j+1))
				swap(tmp.at(j), tmp.at(j+1));

	// Push values to container
	while (tmp.size() != 0)
	{
		insert(tmp.back());
		tmp.pop_back();
	}

	// Stop timer
	gettimeofday(&t2, NULL);

	// Calculate time used
	timeUsed = (t2.tv_sec - t1.tv_sec) * 1000.0;
	timeUsed += (t2.tv_usec - t1.tv_usec) / 1000.0;
	std::cout << "Sort Method bubbleSort took " << timeUsed << " ms"
		<< " to sort " << size() << " elements." << std::endl;
}

template <class T>
void Sorter<T>::swap(int &t1, int &t2)
{
	int hold = t1;
	t1 = t2;
	t2 = hold;
}

#endif