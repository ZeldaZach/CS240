// General practice; Include your header files first, then library
#include "dog.h"
#include "cat.h"
#include <iostream>

using namespace std;

int main()
{
	Dog fido; // Constructor implicitly called
	Cat mittens;

	cout << "Hello" << endl;
	return 0;
}
