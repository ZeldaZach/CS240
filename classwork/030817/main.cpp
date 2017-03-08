#include <iostream>
#include <string>

int main()
{
	LinkedList<string> ll;
	ll << "eggs" << "milk" << "sugar";
	ll << "chocolate" << "flour";

	for (int i = 0; i < ll.size(); i++)
		std::cout << ll.read() << std::endl;

	ll.remove("flour");
	ll.insert("coffee");

	for (int i = 0; i < ll.size(); i++)
	{
		if (ll.read() == "sugar")
		{
			// Replace
		}
	}

	ll.remove("milk");

	return 0;
}
