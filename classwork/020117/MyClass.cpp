#include "MyClass.h"
#include <iostream>
#include <string>

using namespace std;
MyClass::MyClass(int x)
{
	this->x = x;
}

MyClass::MyClass()
{

}

MyClass MyClass::operator- (MyClass other)
{
	MyClass newmc;
	newmc = this->x - other.x;
	return newmc;
}

int MyClass::myfunc(int x)
{
	return x * x;
}

int main()
{
	MyClass obj1(5), obj2(11);
	MyClass obj3 = obj1 + obj2; // 5 + 11 = 16

	std::cout << obj1.x << " + " << obj2.x << " = " << obj3.x << std::endl;

	string myString = "Hello"; // Overloaded operator=
	string myOtherString("Goodbye");

	string concatString = myString + myOtherString; // Overloaded operator+
	concatString += myString; // Overloaded operator+=

	std::cout << concatString << std::endl; // myString + myOtherString + myString

	const char *cstr = myString.c_str(); // Get underlying string

	return 0;
}
