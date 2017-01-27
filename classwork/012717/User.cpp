#include "User.h"
#include <iostream>

User::User(std::string name)
{
	this->name = name;
	this->ptr_name = new std::string(name);
}

User::~User()
{
	std::cout << "Deleting User class" << std::endl;
	delete this->ptr_name; // Always works on a pointer
}
