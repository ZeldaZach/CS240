#include "User.h"
#include <iostream>

int main()
{
	User user1("Zach"); // Creates memory on the stack, auto managed
	User *user2 = new User("Halp"); // Creates memory on heap, pointer w/o management

	std::cout << user1.name << std::endl;
	std::cout << user2->name << std::endl;

	delete user2;
	return 0;
}
