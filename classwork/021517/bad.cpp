#include <iostream>

int* foo(int y)
{
	int x = y;
	return &x;
}

int main()
{
	int *x = foo(5);
	std::cout << *(x+5) << std::endl;

	int *z = foo(6);
	std::cout << *(x+4) << std::endl;
	return 0;
}
