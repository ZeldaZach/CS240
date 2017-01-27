#ifndef USER_H
#define USER_H

#include <string>

class User
{
	private:

	public:
		User(std::string);
		std::string name;
		std::string *ptr_name;
		~User();
};

#endif
