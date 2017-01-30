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

		User operator=(User other)
		{
			std::string str = std::string(*other.name);
			return User(str);
		}
};

#endif
