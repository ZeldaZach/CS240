#ifndef HASH_H
#define HASH_H

#define String std::string
#include <vector>
#include <string>

class Hash
{
	private:
		int maxSize;
		int curSize;
		std::vector<std::pair<String, String> > dict;

	public:
		Hash(unsigned int);
		bool insert(String, String);
		bool remove(String);
		String find(String);
		bool empty();
		int size();
		void printHash();
		int hasher(String);
};

#endif
