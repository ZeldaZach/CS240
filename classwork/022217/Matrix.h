#ifndef MATRIX_H
#define MATRIX_H

#define MAX_ROWS 50
#define MAX_COLUMNS 50

#include <iostream>

template <class T>
class Matrix
{
	private:
		T doubleArray[MAX_ROWS][MAX_COLUMNS];
		int rows;
		int cols;
		
	public:
		Matrix() { rows = MAX_ROWS; cols = MAX_COLUMNS; }
		void printMatrix();
		void setMatrix(T[][MAX_COLUMNS]);
};

template <class T>
void Matrix<T>::printMatrix()
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLUMNS; j++)
		{
			std::cout << doubleArray[i][j];
		}

		std::cout << std::endl;
	}		
}

template <class T>
void Matrix<T>::setMatrix(T data[][MAX_COLUMNS])
{
	this->rows = sizeof(data) / sizeof(data[0]);
	this->cols = MAX_COLUMNS;
	
	// Deep copy
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			this->doubleArray[i][j] = data[i][j];
}

#endif