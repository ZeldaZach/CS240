#include <list>
#include <string>
#include <iostream>

int main()
{
	std::list<string> ll;
	ll.insert("eggs");
	ll.insert("milk");
	ll.insert("sugar");
	ll.insert("chocolate");
	ll.insert("flour");

	for (std::list<string>::Iterator iter = ll.begin(); iter < ll.end(); iter++)
		std::cout << *iter << std::endl;

	ll.erase(5);
	ll.insert("coffee");

	for (std::list<string>::Iterator iter = ll.begin(); iter < ll.end(); iter++)
		if (*iter == "sugar")
			*iter = "honey";

	for (std::list<string>::Iterator iter = ll.begin(); iter < ll.end(); iter++)
		if (*iter == "milk")
			ll.erase(iter);
}
