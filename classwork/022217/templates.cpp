#include "templates.h"

int main()
{
	MyClass::MyClass<int> mc1;
	MyClass::MyClass<char> mc2;
	MyClass::MyClass<MyClass<int>> mc3;

	return 0;
}
